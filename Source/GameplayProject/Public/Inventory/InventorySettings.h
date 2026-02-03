// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConsumableItem.h"
#include "ItemDefinition.h"
#include "Engine/DeveloperSettings.h"
#include "InventorySettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, BlueprintType)
class GAMEPLAYPROJECT_API UInventorySettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowedClasses = "ItemDataAsset"))
	TSoftObjectPtr<UItemDefinition> ItemDataAsset;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowedClasses = "ItemDataAsset"))
	TSoftObjectPtr<UConsumableItem> ConsumableDataAsset;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory")
	const UItemDefinition* GetItemDefinition() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory")
	const UConsumableItem* GetConsumableItem() const;
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool GetItemData(FName ItemID, FItemData& OutItemData) const;
};
