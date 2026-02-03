// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinition.h"
#include "InventoryItem.generated.h"

// 物品状态
UENUM(BlueprintType)
enum class EItemState : uint8
{
	Normal      UMETA(DisplayName = "正常"),
	Equipped    UMETA(DisplayName = "已装备"),
	Broken      UMETA(DisplayName = "损坏"),
	QuestActive UMETA(DisplayName = "任务激活")
};

/**
 * 
 */
UCLASS(Blueprintable)
class GAMEPLAYPROJECT_API AInventoryItem : public AActor
{
	GENERATED_BODY()
    
public:
    
    AInventoryItem();
	
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    void Initialize(FName InItemID, int32 InQuantity);
	
    void InitializeWithData(const FItemData& InItemData, int32 InQuantity);
    
   
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    FName GetItemID() const { return ItemID; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    FText GetDisplayName() const { return ItemData.DisplayName; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    FText GetDescription() const { return ItemData.Description; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    UTexture2D* GetIcon() const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    UStaticMesh* GetWorldMesh() const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    EItemType GetItemType() const { return ItemData.ItemType; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    EItemRarity GetRarity() const { return ItemData.Rarity; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    const FItemData& GetItemData() const { return ItemData; }
    
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    bool CanStack() const { return ItemData.bCanStack; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    int32 GetMaxStackSize() const { return ItemData.MaxStackSize; }
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    bool CanMergeWith(const AInventoryItem* OtherItem) const;
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    int32 GetRemainingStackSpace() const;
    
    // 数量操作
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    int32 AddQuantity(int32 Amount);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    int32 RemoveQuantity(int32 Amount);
    
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    bool SplitItem(int32 SplitAmount, AInventoryItem*& OutSplitItem);
    
    // 状态管理
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    void SetItemState(EItemState NewState);
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    EItemState GetItemState() const { return ItemState; }
    
    // 自定义属性
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    void SetCustomProperty(FName PropertyName, float Value);
    
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    float GetCustomProperty(FName PropertyName, float DefaultValue = 0.0f) const;
    
    // 使用相关
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    bool CanUse() const;
    
    UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
    void MarkUsed();
    
    // 装备相关
    UFUNCTION(BlueprintPure, Category = "Inventory|Item")
    EEquipmentSlot GetEquipmentSlot() const { return ItemData.EquipmentSlot; }
    
    // 运行时数据
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Item")
    int32 Quantity;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Item")
    EItemState ItemState;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Item")
    FGuid UniqueID;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Item")
    FName ItemID;
    
    // 耐久度等自定义属性
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Item")
    TMap<FName, float> CustomProperties;
    
private:
    // 物品数据
    UPROPERTY()
    FItemData ItemData;
    
    float LastUsedTime;
	
    const UItemDefinition* GetItemDefinition() const;
};