#include "ObjectPool/ObjectPoolManager.h"
#include "ObjectPool/PoolableInterface.h"
#include "Engine/World.h"
#include "TimerManager.h"

UObjectPoolManager* UObjectPoolManager::Instance = nullptr;

UObjectPoolManager::UObjectPoolManager()
{
    DefaultConfig.MaxPoolSize = DefaultMaxPoolSize;
    DefaultConfig.CleanupInterval = DefaultCleanupInterval;
}

UObjectPoolManager* UObjectPoolManager::Get(UWorld* World)
{
    if (Instance && (!Instance->CachedWorld.IsValid() || Instance->CachedWorld.Get() != World))
    {
        Instance->DrainAll();
        Instance->RemoveFromRoot();
        Instance = nullptr;
    }

    if (!Instance && World)
    {
        Instance = NewObject<UObjectPoolManager>();
        Instance->AddToRoot();
        Instance->CachedWorld = World;

        Instance->DefaultConfig.MaxPoolSize = Instance->DefaultMaxPoolSize;
        Instance->DefaultConfig.CleanupInterval = Instance->DefaultCleanupInterval;

        for (const FPerClassConfigEntry& Entry : Instance->PerClassConfigs)
        {
            UClass* FoundClass = FindObject<UClass>(nullptr, *Entry.ClassName);
            if (FoundClass)
            {
                FPoolTypeConfig TypeConfig;
                TypeConfig.MaxPoolSize = Entry.MaxPoolSize;
                TypeConfig.CleanupInterval = Entry.CleanupInterval;
                Instance->SetPoolConfig(FoundClass, TypeConfig);
            }
        }

        Instance->StartCleanupTimer();
    }
    return Instance;
}

void UObjectPoolManager::StartCleanupTimer()
{
    UWorld* World = CachedWorld.Get();
    if (!World) return;

    float MinInterval = DefaultConfig.CleanupInterval;
    {
        FScopeLock MapLock(&BucketsMapLock);
        for (auto& Pair : Buckets)
        {
            MinInterval = FMath::Min(MinInterval, Pair.Value->Config.CleanupInterval);
        }
    }

    if (CleanupTimerHandle.IsValid())
    {
        World->GetTimerManager().ClearTimer(CleanupTimerHandle);
    }

    World->GetTimerManager().SetTimer(
        CleanupTimerHandle,
        this,
        &UObjectPoolManager::CleanupAll,
        MinInterval,
        true
    );
}

FObjectPoolBucket& UObjectPoolManager::FindOrCreateBucket(TSubclassOf<UObject> ObjectClass)
{
    {
        TUniquePtr<FObjectPoolBucket>* Existing = Buckets.Find(ObjectClass);
        if (Existing)
        {
            return **Existing;
        }
    }

    FScopeLock MapLock(&BucketsMapLock);

    TUniquePtr<FObjectPoolBucket>* Existing = Buckets.Find(ObjectClass);
    if (Existing)
    {
        return **Existing;
    }

    TUniquePtr<FObjectPoolBucket>& NewBucket = Buckets.Add(ObjectClass, MakeUnique<FObjectPoolBucket>());
    NewBucket->Config = DefaultConfig;
    NewBucket->LastCleanupTime = FPlatformTime::Seconds();
    return *NewBucket;
}

UObject* UObjectPoolManager::AcquireImpl(TSubclassOf<UObject> ObjectClass)
{
    if (!ObjectClass) return nullptr;

    FObjectPoolBucket& Bucket = FindOrCreateBucket(ObjectClass);
    UObject* Object = nullptr;

    {
        FScopeLock BucketLock(&Bucket.Lock);

        if (Bucket.PooledObjects.Num() > 0)
        {
            Object = Bucket.PooledObjects.Pop();
            if (!IsValid(Object))
            {
                Object = nullptr;
            }
            else
            {
                Bucket.ActiveObjects.Add(Object);
                Bucket.TotalReuses++;
            }
        }

        if (!Object)
        {
            Bucket.TotalAllocations++;
        }
    }

    if (Object)
    {
        if (Object->Implements<UPoolableInterface>())
        {
            IPoolableInterface::Execute_Reset(Object);
            IPoolableInterface::Execute_OnUnpooled(Object);
        }
        return Object;
    }

    UWorld* World = CachedWorld.Get();
    if (!World) return nullptr;

    if (ObjectClass->IsChildOf(AActor::StaticClass()))
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        Object = World->SpawnActor<AActor>(ObjectClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
    }
    else
    {
        Object = NewObject<UObject>(World, ObjectClass);
    }

    if (Object)
    {
        {
            FScopeLock BucketLock(&Bucket.Lock);
            Bucket.ActiveObjects.Add(Object);
        }

        if (Object->Implements<UPoolableInterface>())
        {
            IPoolableInterface::Execute_OnCreated(Object);
            IPoolableInterface::Execute_Reset(Object);
            IPoolableInterface::Execute_OnUnpooled(Object);
        }
    }

    return Object;
}

void UObjectPoolManager::ReleaseImpl(UObject* Object)
{
    if (!Object || !IsValid(Object)) return;

    TSubclassOf<UObject> ObjectClass = Object->GetClass();
    FObjectPoolBucket& Bucket = FindOrCreateBucket(ObjectClass);

    if (Object->Implements<UPoolableInterface>())
    {
        IPoolableInterface::Execute_OnPrePooled(Object);
        IPoolableInterface::Execute_Reset(Object);
        IPoolableInterface::Execute_OnPooled(Object);
    }

    bool bAddedToPool = false;
    {
        FScopeLock BucketLock(&Bucket.Lock);
        Bucket.ActiveObjects.Remove(Object);

        if (Bucket.PooledObjects.Num() < Bucket.Config.MaxPoolSize)
        {
            Bucket.PooledObjects.Add(Object);
            bAddedToPool = true;
        }
    }

    if (!bAddedToPool)
    {
        if (Object->Implements<UPoolableInterface>())
        {
            IPoolableInterface::Execute_OnDestroyed(Object);
        }
        DestroyObject(Object);
    }
}

void UObjectPoolManager::PreallocateImpl(TSubclassOf<UObject> ObjectClass, int32 Count)
{
    if (!ObjectClass || Count <= 0) return;

    UWorld* World = CachedWorld.Get();
    if (!World) return;

    FObjectPoolBucket& Bucket = FindOrCreateBucket(ObjectClass);

    for (int32 i = 0; i < Count; ++i)
    {
        UObject* Object = nullptr;

        if (ObjectClass->IsChildOf(AActor::StaticClass()))
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            Object = World->SpawnActor<AActor>(ObjectClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
        }
        else
        {
            Object = NewObject<UObject>(World, ObjectClass);
        }

        if (Object)
        {
            if (Object->Implements<UPoolableInterface>())
            {
                IPoolableInterface::Execute_OnCreated(Object);
                IPoolableInterface::Execute_Reset(Object);
                IPoolableInterface::Execute_OnPooled(Object);
            }

            bool bAdded = false;
            {
                FScopeLock BucketLock(&Bucket.Lock);
                if (Bucket.PooledObjects.Num() < Bucket.Config.MaxPoolSize)
                {
                    Bucket.PooledObjects.Add(Object);
                    bAdded = true;
                }
            }

            if (!bAdded)
            {
                if (Object->Implements<UPoolableInterface>())
                {
                    IPoolableInterface::Execute_OnDestroyed(Object);
                }
                DestroyObject(Object);
            }
        }
    }
}

void UObjectPoolManager::CleanupAll()
{
    double CurrentTime = FPlatformTime::Seconds();

    TArray<UObject*> ObjectsToDestroy;

    {
        FScopeLock MapLock(&BucketsMapLock);

        for (auto& Pair : Buckets)
        {
            FObjectPoolBucket& Bucket = *Pair.Value;

            if ((CurrentTime - Bucket.LastCleanupTime) < Bucket.Config.CleanupInterval)
            {
                continue;
            }

            FScopeLock BucketLock(&Bucket.Lock);

            Bucket.PooledObjects.RemoveAll([](UObject* Obj) {
                return !IsValid(Obj);
            });

            while (Bucket.PooledObjects.Num() > Bucket.Config.MaxPoolSize)
            {
                UObject* ObjectToDestroy = Bucket.PooledObjects.Pop();
                if (IsValid(ObjectToDestroy))
                {
                    ObjectsToDestroy.Add(ObjectToDestroy);
                }
            }

            TArray<UObject*> InvalidActive;
            for (UObject* Obj : Bucket.ActiveObjects)
            {
                if (!IsValid(Obj))
                {
                    InvalidActive.Add(Obj);
                }
            }
            for (UObject* Obj : InvalidActive)
            {
                Bucket.ActiveObjects.Remove(Obj);
            }

            Bucket.LastCleanupTime = CurrentTime;
        }
    }

    for (UObject* Obj : ObjectsToDestroy)
    {
        if (IsValid(Obj))
        {
            if (Obj->Implements<UPoolableInterface>())
            {
                IPoolableInterface::Execute_OnDestroyed(Obj);
            }
            DestroyObject(Obj);
        }
    }
}

void UObjectPoolManager::CleanupForClass(TSubclassOf<UObject> ObjectClass)
{
    if (!ObjectClass) return;

    TUniquePtr<FObjectPoolBucket>* BucketPtr = Buckets.Find(ObjectClass);
    if (!BucketPtr) return;
    FObjectPoolBucket& Bucket = **BucketPtr;

    TArray<UObject*> ObjectsToDestroy;
    {
        FScopeLock BucketLock(&Bucket.Lock);
        for (UObject* Obj : Bucket.PooledObjects)
        {
            if (IsValid(Obj))
            {
                ObjectsToDestroy.Add(Obj);
            }
        }
        Bucket.PooledObjects.Empty();
    }

    for (UObject* Obj : ObjectsToDestroy)
    {
        if (Obj->Implements<UPoolableInterface>())
        {
            IPoolableInterface::Execute_OnDestroyed(Obj);
        }
        DestroyObject(Obj);
    }
}

void UObjectPoolManager::DrainAll()
{
    UWorld* World = CachedWorld.Get();
    if (World && CleanupTimerHandle.IsValid())
    {
        World->GetTimerManager().ClearTimer(CleanupTimerHandle);
    }

    TArray<UObject*> ObjectsToDestroy;

    {
        FScopeLock MapLock(&BucketsMapLock);

        for (auto& Pair : Buckets)
        {
            FObjectPoolBucket& Bucket = *Pair.Value;
            FScopeLock BucketLock(&Bucket.Lock);

            for (UObject* Obj : Bucket.PooledObjects)
            {
                if (IsValid(Obj))
                {
                    ObjectsToDestroy.Add(Obj);
                }
            }
            Bucket.PooledObjects.Empty();
            Bucket.ActiveObjects.Empty();
        }

        Buckets.Empty();
    }

    for (UObject* Obj : ObjectsToDestroy)
    {
        if (IsValid(Obj))
        {
            if (Obj->Implements<UPoolableInterface>())
            {
                IPoolableInterface::Execute_OnDestroyed(Obj);
            }
            DestroyObject(Obj);
        }
    }
}

void UObjectPoolManager::SetPoolConfig(TSubclassOf<UObject> ObjectClass, const FPoolTypeConfig& Config)
{
    if (!ObjectClass) return;

    FObjectPoolBucket& Bucket = FindOrCreateBucket(ObjectClass);
    FScopeLock BucketLock(&Bucket.Lock);
    Bucket.Config = Config;
}

FPoolTypeConfig UObjectPoolManager::GetPoolConfig(TSubclassOf<UObject> ObjectClass) const
{
    const TUniquePtr<FObjectPoolBucket>* BucketPtr = Buckets.Find(ObjectClass);
    if (BucketPtr)
    {
        return (*BucketPtr)->Config;
    }
    return DefaultConfig;
}

void UObjectPoolManager::GetPoolStatistics(TMap<FString, FPoolStatistics>& OutStats) const
{
    OutStats.Empty();

    for (const auto& Pair : Buckets)
    {
        FObjectPoolBucket& Bucket = *Pair.Value;
        FString ClassName = Pair.Key->GetName();

        FScopeLock BucketLock(&Bucket.Lock);

        FPoolStatistics Stats;
        Stats.PooledCount = Bucket.PooledObjects.Num();
        Stats.ActiveCount = Bucket.ActiveObjects.Num();
        Stats.TotalAllocations = Bucket.TotalAllocations;
        Stats.TotalReuses = Bucket.TotalReuses;
        OutStats.Add(ClassName, Stats);
    }
}

void UObjectPoolManager::DestroyObject(UObject* Object)
{
    if (!IsValid(Object)) return;

    if (Object->IsA<AActor>())
    {
        Cast<AActor>(Object)->Destroy();
    }
    else
    {
        Object->ConditionalBeginDestroy();
    }
}
