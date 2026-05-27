// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionTypes.generated.h"

/** 交互提示数据：单选项交互的展示信息 */
USTRUCT(BlueprintType)
struct FInteractionPrompt
{
    GENERATED_BODY()

    // 提示文字，例如 "[E] 拾取苹果"
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    FText Text;

    // 可选图标，可为空，UI 容错
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    TObjectPtr<UTexture2D> Icon = nullptr;

    // 为 false 时即便被检测到也不显示提示、不可交互
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    bool bEnabled = true;
};
