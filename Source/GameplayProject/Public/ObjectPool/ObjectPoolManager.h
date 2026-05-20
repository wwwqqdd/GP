// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "ObjectPoolManager.generated.h"

USTRUCT()
struct FPoolTypeConfig
{
    GENERATED_BODY()

    UPROPERTY(Config)
    int32 MaxPoolSize = 20;

    UPROPERTY(Config)
    float CleanupInterval = 30.0f;
};

struct FObjectPoolBucket
{
    TArray<UObject*> PooledObjects;
    TSet<UObject*> ActiveObjects;
    FCriticalSection Lock;
    FPoolTypeConfig Config;
    double LastCleanupTime = 0.0;

    int32 TotalAllocations = 0;
    int32 TotalReuses = 0;
};

USTRUCT(BlueprintType)
struct FPoolStatistics
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    int32 PooledCount = 0;

    UPROPERTY(BlueprintReadOnly)
    int32 ActiveCount = 0;

    UPROPERTY(BlueprintReadOnly)
    int32 TotalAllocations = 0;

    UPROPERTY(BlueprintReadOnly)
    int32 TotalReuses = 0;
};

USTRUCT()
struct FPerClassConfigEntry
{
    GENERATED_BODY()

    UPROPERTY(Config)
    FString ClassName;

    UPROPERTY(Config)
    int32 MaxPoolSize = 20;

    UPROPERTY(Config)
    float CleanupInterval = 30.0f;
};

UCLASS(Config=Game)
class GAMEPLAYPROJECT_API UObjectPoolManager : public UObject
{
    GENERATED_BODY()

public:
    UObjectPoolManager();

    static UObjectPoolManager* Get(UWorld* World);

    template<typename T>
    T* Acquire(TSubclassOf<T> ObjectClass);

    template<typename T>
    void Release(T* Object);

    template<typename T>
    void Preallocate(TSubclassOf<T> ObjectClass, int32 Count);

    void CleanupAll();
    void CleanupForClass(TSubclassOf<UObject> ObjectClass);
    void DrainAll();

    void SetPoolConfig(TSubclassOf<UObject> ObjectClass, const FPoolTypeConfig& Config);
    FPoolTypeConfig GetPoolConfig(TSubclassOf<UObject> ObjectClass) const;

    void GetPoolStatistics(TMap<FString, FPoolStatistics>& OutStats) const;

private:
    UObject* AcquireImpl(TSubclassOf<UObject> ObjectClass);
    void ReleaseImpl(UObject* Object);
    void PreallocateImpl(TSubclassOf<UObject> ObjectClass, int32 Count);

    FObjectPoolBucket& FindOrCreateBucket(TSubclassOf<UObject> ObjectClass);
    void DestroyObject(UObject* Object);
    void StartCleanupTimer();

    TMap<TSubclassOf<UObject>, TUniquePtr<FObjectPoolBucket>> Buckets;
    FCriticalSection BucketsMapLock;

    UPROPERTY(Config)
    int32 DefaultMaxPoolSize = 20;

    UPROPERTY(Config)
    float DefaultCleanupInterval = 30.0f;

    UPROPERTY(Config)
    TArray<FPerClassConfigEntry> PerClassConfigs;

    FPoolTypeConfig DefaultConfig;

    FTimerHandle CleanupTimerHandle;

    UPROPERTY()
    TWeakObjectPtr<UWorld> CachedWorld;

    static UObjectPoolManager* Instance;
};

// Template implementations
template<typename T>
T* UObjectPoolManager::Acquire(TSubclassOf<T> ObjectClass)
{
    return Cast<T>(AcquireImpl(ObjectClass));
}

template<typename T>
void UObjectPoolManager::Release(T* Object)
{
    ReleaseImpl(Object);
}

template<typename T>
void UObjectPoolManager::Preallocate(TSubclassOf<T> ObjectClass, int32 Count)
{
    PreallocateImpl(ObjectClass, Count);
}
