// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventorySlot.h"
#include "ItemDefinition.h"
#include "InventoryComponent.generated.h"

// 库存变更委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryChanged, int32, SlotIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemAdded, const FName&, ItemID, int32, Quantity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemRemoved, const FName&, ItemID, int32, Quantity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemEquipped, const FInventorySlot&, EquippedSlot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemUsed, const FName&, ItemID);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEPLAYPROJECT_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

protected:
    virtual void BeginPlay() override;

public:
    // ========== 库存初始化 ==========
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void InitializeInventory(int32 InInventorySize, int32 InEquipmentSlotCount, int32 InQuickAccessSize);

    // ========== 物品操作 ==========
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 AddItem(FName ItemID, int32 Quantity, bool bForceToSpecificSlot = false, int32 TargetSlotIndex = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 AddItemWithData(const FItemData& ItemData, int32 Quantity, bool bForceToSpecificSlot = false, int32 TargetSlotIndex = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 RemoveItem(const FName& ItemID, int32 Quantity);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 RemoveItemFromSlot(int32 SlotIndex, int32 Quantity);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void ClearSlot(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool SplitItemInSlot(int32 SourceSlotIndex, int32 SplitAmount, int32 TargetSlotIndex = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 MergeItemSlots(int32 SourceSlotIndex, int32 TargetSlotIndex);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool SwapSlots(int32 SlotIndex1, int32 SlotIndex2);

    // ========== 装备系统 ==========
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool EquipItem(int32 ItemSlotIndex, EEquipmentSlot TargetEquipmentSlot);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool UnequipItem(EEquipmentSlot EquipmentSlot);
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Equipment")
    FInventorySlot GetEquippedItemInSlot(EEquipmentSlot EquipmentSlot) const;

    // ========== 物品使用 ==========
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    bool UseItem(int32 SlotIndex);

    // ========== 查询功能 ==========
    UFUNCTION(BlueprintPure, Category = "Inventory")
    FInventorySlot GetInventorySlot(int32 SlotIndex) const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory")
    TArray<FInventorySlot> GetAllInventorySlots() const { return InventorySlots; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    int32 GetItemCount(const FName& ItemID) const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory")
    bool HasEnoughSpace(FName ItemID, int32 Quantity) const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 FindEmptySlot(ESlotType SlotType = ESlotType::Inventory) const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 FindStackableSlot(FName ItemID) const;

    // ========== 辅助功能 ==========
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void SetSlotLocked(int32 SlotIndex, bool bLocked);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void ClearAllInventory();
    
    UFUNCTION(BlueprintPure, Category = "Inventory")
    bool IsValidSlotIndex(int32 SlotIndex) const;

    // ========== 委托 ==========
    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnInventoryChanged OnInventoryChanged;

    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnItemAdded OnItemAdded;

    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnItemRemoved OnItemRemoved;

    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnItemEquipped OnItemEquipped;

    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnItemUsed OnItemUsed;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool ApplyConsumableEffect(AInventoryItem* ConsumableItem);
private:
    UPROPERTY(VisibleAnywhere, Category = "Inventory")
    TArray<FInventorySlot> InventorySlots;

    // 库存配置
    UPROPERTY(EditAnywhere, Category = "Inventory|Settings")
    int32 InventorySize = 24;

    UPROPERTY(EditAnywhere, Category = "Inventory|Settings")
    int32 EquipmentSlotCount = 8;

    UPROPERTY(EditAnywhere, Category = "Inventory|Settings")
    int32 QuickAccessSize = 8;

    // 获取物品定义
    const UItemDefinition* GetItemDefinition() const;
    
    // 根据ItemID获取物品数据
    bool GetItemData(FName ItemID, FItemData& OutItemData) const;
    
    /** 获取装备槽位对应的索引 */
    int32 GetEquipmentSlotIndex(EEquipmentSlot EquipmentSlot) const;
    
    /** 触发库存变更事件 */
    void NotifyInventoryChanged(int32 SlotIndex);
    
    /** 应用消耗品效果 */
};