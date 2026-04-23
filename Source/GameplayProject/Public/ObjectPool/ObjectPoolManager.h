// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "ObjectPoolManager.generated.h"

/**
 * 对象池管理器 - 负责统一管理所有对象池
 */
UCLASS()
class GAMEPLAYPROJECT_API UObjectPoolManager : public UObject
{
    GENERATED_BODY()

public:
    UObjectPoolManager();

    /** 获取单例实例 */
    static UObjectPoolManager* Get(UWorld* World);

    /** 从对象池获取对象 */
    template<typename T>
    T* GetObjectFromPool(TSubclassOf<T> ObjectClass);

    /** 将对象返回到对象池 */
    template<typename T>
    void ReturnObjectToPool(T* Object);

    /** 预分配对象到对象池 */
    template<typename T>
    void PreallocateObjects(TSubclassOf<T> ObjectClass, int32 Count);

    /** 清理对象池 */
    void CleanupPool();

    /** 获取对象池统计信息 */
    void GetPoolStatistics(TMap<FString, int32>& OutStatistics) const;

private:
    /** 从对象池获取对象（通用实现） */
    UObject* GetObjectFromPoolImpl(TSubclassOf<UObject> ObjectClass);

    /** 将对象返回到对象池（通用实现） */
    void ReturnObjectToPoolImpl(UObject* Object);

    /** 清理特定类的对象池 */
    void CleanupPoolForClass(TSubclassOf<UObject> ObjectClass);

private:
    /** 对象池 - 按类存储 */
    TMap<TSubclassOf<UObject>, TArray<UObject*>> ObjectPools;

    /** 活跃对象列表 - 跟踪正在使用的对象 */
    TSet<UObject*> ActiveObjects;

    /** 对象池配置 */
    UPROPERTY()
    int32 MaxPoolSizePerClass;

    /** 清理定时器 */
    FTimerHandle CleanupTimerHandle;

    /** 清理间隔（秒） */
    float CleanupInterval;

    /** 单例实例 */
    static UObjectPoolManager* Instance;
};