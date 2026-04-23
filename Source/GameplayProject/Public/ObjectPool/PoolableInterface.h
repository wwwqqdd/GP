// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PoolableInterface.generated.h"

/**
 * 可池化接口 - 实现此接口的对象可以被对象池管理
 */
UINTERFACE(MinimalAPI)
class UPoolableInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 可池化接口 - 实现此接口的对象可以被对象池管理
 */
class GAMEPLAYPROJECT_API IPoolableInterface
{
    GENERATED_BODY()

public:
    /**
     * 重置对象状态到初始状态
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void Reset();

    /**
     * 对象被创建时调用
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnCreated();

    /**
     * 对象被回收到池时调用
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnPooled();

    /**
     * 对象从池中取出时调用
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnUnpooled();
};