#include "ObjectPool/ObjectPoolManager.h"
#include "ObjectPool/PoolableInterface.h"
#include "Inventory/InventoryItem.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

UObjectPoolManager* UObjectPoolManager::Instance = nullptr;

UObjectPoolManager::UObjectPoolManager()
{
    MaxPoolSizePerClass = 20;
    CleanupInterval = 30.0f;
}

UObjectPoolManager* UObjectPoolManager::Get(UWorld* World)
{
    if (!Instance && World)
    {
        Instance = NewObject<UObjectPoolManager>();
        Instance->AddToRoot(); // 防止被垃圾回收

        // 设置清理定时器
        World->GetTimerManager().SetTimer(
            Instance->CleanupTimerHandle,
            Instance,
            &UObjectPoolManager::CleanupPool,
            Instance->CleanupInterval,
            true
        );
    }
    return Instance;
}

template<typename T>
T* UObjectPoolManager::GetObjectFromPool(TSubclassOf<T> ObjectClass)
{
    if (!ObjectClass) return nullptr;

    T* Object = nullptr;
    UWorld* World = GEngine ? GEngine->GetWorld() : nullptr;

    // 首先尝试从对象池获取
    TArray<UObject*>* PooledObjects = ObjectPools.Find(ObjectClass);
    if (PooledObjects && PooledObjects->Num() > 0)
    {
        Object = Cast<T>(PooledObjects->Pop());
        if (Object)
        {
            ActiveObjects.Add(Object);

            // 重置对象状态（如果对象实现了重置接口）
            if (Object->template Implements<UPoolableInterface>())
            {
                IPoolableInterface::Execute_Reset(Object);
                IPoolableInterface::Execute_OnUnpooled(Object);
            }
        }
    }
    else if (World)
    {
        // 对象池为空，创建新对象
        Object = World->SpawnActor<T>(ObjectClass);
        if (Object)
        {
            ActiveObjects.Add(Object);
        }
    }

    return Object;
}

template<typename T>
void UObjectPoolManager::ReturnObjectToPool(T* Object)
{
    if (!Object) return;

    // 重置对象状态
    if (Object->template Implements<UPoolableInterface>())
    {
        IPoolableInterface::Execute_OnPooled(Object);
        IPoolableInterface::Execute_Reset(Object);
    }

    // 添加到对应类的对象池
    TSubclassOf<UObject> ObjectClass = Object->GetClass();
    TArray<UObject*>* PooledObjects = ObjectPools.Find(ObjectClass);
    if (!PooledObjects)
    {
        PooledObjects = &ObjectPools.Add(ObjectClass, TArray<UObject*>());
    }

    if (PooledObjects->Num() < MaxPoolSizePerClass)
    {
        PooledObjects->Add(Object);
    }
    else
    {
        // 超过池大小限制，直接销毁
        if (Object->template IsA<AActor>())
        {
            Cast<AActor>(Object)->Destroy();
        }
        else
        {
            Object->ConditionalBeginDestroy();
        }
    }

    // 从活跃对象列表中移除
    ActiveObjects.Remove(Object);
}

void UObjectPoolManager::ReturnObjectToPoolImpl(UObject* Object)
{
    ReturnObjectToPool(Object);
}

template<typename T>
void UObjectPoolManager::PreallocateObjects(TSubclassOf<T> ObjectClass, int32 Count)
{
    if (!ObjectClass || Count <= 0) return;

    UWorld* World = GEngine ? GEngine->GetWorld() : nullptr;
    if (!World) return;

    TArray<UObject*>* PooledObjects = ObjectPools.Find(ObjectClass);
    if (!PooledObjects)
    {
        PooledObjects = &ObjectPools.Add(ObjectClass, TArray<UObject*>());
    }

    for (int32 i = 0; i < Count; ++i)
    {
        T* Object = World->SpawnActor<T>(ObjectClass);
        if (Object)
        {
            PooledObjects->Add(Object);
        }
    }
}

void UObjectPoolManager::CleanupPool()
{
    // 清理每个对象池
    for (auto& Pair : ObjectPools)
    {
        TArray<UObject*>& Pool = Pair.Value;

        // 移除无效对象
        Pool.RemoveAll([](UObject* Object) {
            return !IsValid(Object);
        });

        // 限制池大小
        while (Pool.Num() > MaxPoolSizePerClass)
        {
            UObject* ObjectToDestroy = Pool.Pop();
            if (IsValid(ObjectToDestroy))
            {
                if (ObjectToDestroy->IsA<AActor>())
                {
                    Cast<AActor>(ObjectToDestroy)->Destroy();
                }
                else
                {
                    ObjectToDestroy->ConditionalBeginDestroy();
                }
            }
        }
    }

    // 清理活跃对象中的无效对象
    TArray<UObject*> InvalidObjects;
    for (UObject* Object : ActiveObjects)
    {
        if (!IsValid(Object))
        {
            InvalidObjects.Add(Object);
        }
    }
    for (UObject* InvalidObject : InvalidObjects)
    {
        ActiveObjects.Remove(InvalidObject);
    }
}

void UObjectPoolManager::CleanupPoolForClass(TSubclassOf<UObject> ObjectClass)
{
    if (!ObjectClass) return;

    TArray<UObject*>* Pool = ObjectPools.Find(ObjectClass);
    if (Pool)
    {
        // 销毁该类的所有池化对象
        for (UObject* Object : *Pool)
        {
            if (IsValid(Object))
            {
                if (Object->IsA<AActor>())
                {
                    Cast<AActor>(Object)->Destroy();
                }
                else
                {
                    Object->ConditionalBeginDestroy();
                }
            }
        }
        Pool->Empty();
    }
}

void UObjectPoolManager::GetPoolStatistics(TMap<FString, int32>& OutStatistics) const
{
    OutStatistics.Empty();

    for (const auto& Pair : ObjectPools)
    {
        FString ClassName = Pair.Key->GetName();
        OutStatistics.Add(ClassName, Pair.Value.Num());
    }

    OutStatistics.Add(TEXT("ActiveObjects"), ActiveObjects.Num());
}

UObject* UObjectPoolManager::GetObjectFromPoolImpl(TSubclassOf<UObject> ObjectClass)
{
    return GetObjectFromPool(ObjectClass);
}

// 显式实例化常用类型
template AInventoryItem* UObjectPoolManager::GetObjectFromPool<AInventoryItem>(TSubclassOf<AInventoryItem>);
template void UObjectPoolManager::ReturnObjectToPool<AInventoryItem>(AInventoryItem*);
template void UObjectPoolManager::PreallocateObjects<AInventoryItem>(TSubclassOf<AInventoryItem>, int32);