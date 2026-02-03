// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryItem.h"
#include "Inventory/InventorySettings.h"

AInventoryItem::AInventoryItem()
    : Quantity(1)
    , ItemState(EItemState::Normal)
    , LastUsedTime(0.0f)
{
    PrimaryActorTick.bCanEverTick = false;
    UniqueID = FGuid::NewGuid();
}

void AInventoryItem::Initialize(FName InItemID, int32 InQuantity)
{
    ItemID = InItemID;
    const UItemDefinition* ItemDefinition = GetItemDefinition();
    
    if (!ItemDefinition || !ItemDefinition->ItemDataMap.Contains(ItemID))
    {
        return;
    }
    
    ItemData = ItemDefinition->ItemDataMap[ItemID];
    InitializeWithData(ItemData, InQuantity);
}

void AInventoryItem::InitializeWithData(const FItemData& InItemData, int32 InQuantity)
{
    ItemData = InItemData;
    ItemID = ItemData.ItemID;
    Quantity = FMath::Clamp(InQuantity, 1, GetMaxStackSize());
    
    
    CustomProperties.Reset();
    
    // 根据物品类型设置默认自定义属性
    if (ItemData.ItemType == EItemType::Equipment)
    {
        CustomProperties.Add(TEXT("Durability"), 100.0f);
        CustomProperties.Add(TEXT("MaxDurability"), 100.0f);
        CustomProperties.Add(TEXT("AttackPower"), 0.0f);
        CustomProperties.Add(TEXT("DefensePower"), 0.0f);
    }
    else if (ItemData.ItemType == EItemType::Consumable)
    {
        CustomProperties.Add(TEXT("HealAmount"), 0.0f);
        CustomProperties.Add(TEXT("BuffDuration"), 0.0f);
    }
    
   
    if (!CanStack())
    {
        UniqueID = FGuid::NewGuid();
    }
}

UTexture2D* AInventoryItem::GetIcon() const
{
    if (ItemData.IconTexture.IsNull())
    {
        return nullptr;
    }
    return ItemData.IconTexture.LoadSynchronous();
}

UStaticMesh* AInventoryItem::GetWorldMesh() const
{
    if (ItemData.WorldMesh.IsNull())
    {
        return nullptr;
    }
    return ItemData.WorldMesh.LoadSynchronous();
}

bool AInventoryItem::CanMergeWith(const AInventoryItem* OtherItem) const
{
    if (!OtherItem)
        return false;
    
    if (ItemID != OtherItem->ItemID)
        return false;
    
    if (!CanStack() || !OtherItem->CanStack())
        return false;
    
    if (ItemState != OtherItem->ItemState)
        return false;
    
    // 检查自定义属性是否相同（对于堆叠物品，属性应该一致）
    if (CustomProperties.Num() != OtherItem->CustomProperties.Num())
        return false;
    
    for (const auto& Prop : CustomProperties)
    {
        const float* OtherValue = OtherItem->CustomProperties.Find(Prop.Key);
        if (!OtherValue || !FMath::IsNearlyEqual(Prop.Value, *OtherValue))
        {
            return false;
        }
    }
    
    return Quantity < GetMaxStackSize();
}

int32 AInventoryItem::GetRemainingStackSpace() const
{
    return CanStack() ? (GetMaxStackSize() - Quantity) : 0;
}

int32 AInventoryItem::AddQuantity(int32 Amount)
{
    if (!CanStack() || Amount <= 0)
        return 0;
    
    const int32 MaxStack = GetMaxStackSize();
    const int32 ActualAdd = FMath::Min(Amount, MaxStack - Quantity);
    
    if (ActualAdd > 0)
    {
        Quantity += ActualAdd;
    }
    
    return ActualAdd;
}

int32 AInventoryItem::RemoveQuantity(int32 Amount)
{
    if (Amount <= 0) return 0;
    
    const int32 ActualRemove = FMath::Min(Amount, Quantity);
    Quantity -= ActualRemove;
    
    return ActualRemove;
}

bool AInventoryItem::SplitItem(int32 SplitAmount, AInventoryItem*& OutSplitItem)
{
    if (!CanStack() || SplitAmount <= 0 || SplitAmount >= Quantity)
        return false;
    
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = GetOwner();
    SpawnParams.Instigator = GetInstigator();
    
    AInventoryItem* SplitItem = GetWorld()->SpawnActor<AInventoryItem>(GetClass(), GetActorLocation(), GetActorRotation(), SpawnParams);
    
    if (SplitItem)
    {
        // 复制当前物品的数据
        SplitItem->InitializeWithData(ItemData, SplitAmount);
        
        // 复制自定义属性
        SplitItem->CustomProperties = CustomProperties;
        SplitItem->ItemState = ItemState;
        
        // 减少原物品数量
        Quantity -= SplitAmount;
        
        OutSplitItem = SplitItem;
        return true;
    }
    
    return false;
}

void AInventoryItem::SetItemState(EItemState NewState)
{
    if (ItemState != NewState)
    {
        ItemState = NewState;
        
        // 状态变化时的特殊处理
        if (ItemState == EItemState::Broken)
        {
            UE_LOG(LogTemp, Warning, TEXT("Item %s is now broken"), *ItemData.DisplayName.ToString());
            // 这里可以添加物品损坏时的逻辑，比如触发事件等
        }
        else if (ItemState == EItemState::Equipped)
        {
            // 装备时的逻辑
        }
    }
}

void AInventoryItem::SetCustomProperty(FName PropertyName, float Value)
{
    CustomProperties.Add(PropertyName, Value);
}

float AInventoryItem::GetCustomProperty(FName PropertyName, float DefaultValue) const
{
    const float* ValuePtr = CustomProperties.Find(PropertyName);
    return ValuePtr ? *ValuePtr : DefaultValue;
}

bool AInventoryItem::CanUse() const
{
    if (GetWorld())
    {
        float CurrentTime = GetWorld()->GetTimeSeconds();
        
        if (CurrentTime - LastUsedTime < ItemData.UseCooldown) return false;
    }
    
    if (ItemState == EItemState::Broken)
        return false;
    
    // 检查是否可以在战斗中使用
    // 这里可以根据实际需求添加更多条件
    
    return true;
}

void AInventoryItem::MarkUsed()
{
    if (GetWorld())
    {
        LastUsedTime = GetWorld()->GetTimeSeconds();
    }
    
    // 减少耐久度（如果是装备）
    if (ItemData.ItemType == EItemType::Equipment)
    {
        float CurrentDurability = GetCustomProperty(TEXT("Durability"), 100.0f);
        float NewDurability = FMath::Max(0.0f, CurrentDurability - 1.0f);
        SetCustomProperty(TEXT("Durability"), NewDurability);
        
        if (NewDurability <= 0.0f)
        {
            SetItemState(EItemState::Broken);
        }
    }
}

const UItemDefinition* AInventoryItem::GetItemDefinition() const
{
    UInventorySettings* Settings = GetMutableDefault<UInventorySettings>();
    if (Settings)
    {
        return Settings->GetItemDefinition();
    }
    return nullptr;
}