// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinition.h"

#include "InventorySlot.generated.h"

class AInventoryItem;

// 槽位类型
UENUM(BlueprintType)
enum class ESlotType : uint8
{
	Inventory      UMETA(DisplayName = "Inventory"),
	Equipment      UMETA(DisplayName = "Equipment"),
	QuickAccess    UMETA(DisplayName = "QuickAccess"),
	Storage        UMETA(DisplayName = "Storage")
};

USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 SlotIndex;
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	ESlotType SlotType;
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	EEquipmentSlot EquipmentSlot;
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	AInventoryItem* Item;
    
	// 是否被锁定（不能移动物品）
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool bIsLocked;
    
	// 是否为空
	bool IsEmpty() const;
    
	// 清空槽位
	void Clear()
	{
		Item = nullptr;
		bIsLocked = false;
	}
    
	// 获取槽位显示名称
	FText GetSlotDisplayName() const;
    
	FInventorySlot()
		: SlotIndex(-1)
		, SlotType(ESlotType::Inventory)
		, EquipmentSlot(EEquipmentSlot::MainHand)
		, Item(nullptr)
		, bIsLocked(false)
	{}
};