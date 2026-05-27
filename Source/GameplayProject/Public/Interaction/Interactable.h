// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interaction/InteractionTypes.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable, BlueprintType)
class UInteractable : public UInterface
{
    GENERATED_BODY()
};

/** 可交互对象接口：实现者自行决定提示内容与被交互时的行为 */
class GAMEPLAYPROJECT_API IInteractable
{
    GENERATED_BODY()

public:
    // 返回提示信息（文字/图标/是否可用）。BP 可 override。
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    FInteractionPrompt GetInteractionPrompt() const;

    // 被交互时调用，Instigator 通常是角色。BP 可 override 写实际效果。
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnInteract(AActor* Instigator);
};
