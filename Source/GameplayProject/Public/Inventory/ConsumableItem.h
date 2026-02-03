// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinition.h"
#include "Engine/DataAsset.h"
#include "ConsumableItem.generated.h"

class UGameplayEffect;

/**
 * 
 */
USTRUCT(BlueprintType)
struct FConsumableItemData
{
	GENERATED_BODY()
	FConsumableItemData()
		: CooldownTime(0.0f)
		, bCanUseInCombat(true)
	{
	}		
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	FItemData ConsumableItemData;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	TSubclassOf<UGameplayEffect> Effect;
    
	// 使用冷却时间
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	float CooldownTime;
    
	// 使用条件
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	bool bCanUseInCombat;
    
	// 动画蒙太奇
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	TSoftObjectPtr<UAnimMontage> UseMontage;
	
};

UCLASS()
class GAMEPLAYPROJECT_API UConsumableItem : public UDataAsset
{
	GENERATED_BODY()
public:
	UConsumableItem();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	TArray<FConsumableItemData> ConsumableItems;
};
