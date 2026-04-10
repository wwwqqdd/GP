// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryItem.h"
#include "Inventory/InventorySettings.h"

AInventoryItem::AInventoryItem()
{
    PrimaryActorTick.bCanEverTick = false;
    Quantity = 1;
    ItemState = EItemState::Normal;
    UniqueID = FGuid::NewGuid();
    LastUsedTime = 0.0f;
}

void AInventoryItem::Initialize(FName InItemID, int32 InQuantity)
{
    ItemID = InItemID;
    const UItemDefinition* ItemDefinition = GetItemDefinition();
    
    if (!ItemDefinition || !ItemDefinition->ItemDataMap.Contains(ItemID))
    {
        Destroy();
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
    if (!OtherItem && ItemID != OtherItem->ItemID) return false;
    
    if (!CanStack() || !OtherItem->CanStack() && ItemState != OtherItem->ItemState) return false;
    
    return Quantity < GetMaxStackSize();
}

int32 AInventoryItem::GetRemainingStackSpace() const
{
    return CanStack() ? (GetMaxStackSize() - Quantity) : 0;
}

int32 AInventoryItem::AddQuantity(int32 Amount)
{
    if (!CanStack() || Amount <= 0) return 0;
    
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
        SplitItem->InitializeWithData(ItemData, SplitAmount);
        SplitItem->ItemState = ItemState;
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
        }
        else if (ItemState == EItemState::Equipped)
        {
            
        }
    }
}

bool AInventoryItem::CanUse() const
{
    if (GetWorld())
    {
        float CurrentTime = GetWorld()->GetTimeSeconds();
        
        if (CurrentTime - LastUsedTime < ItemData.UseCooldown) return false;
    }
    if (ItemState == EItemState::Broken) return false;
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
        
    }
}

void AInventoryItem::Reset()
{
    // 重置物品状态到初始值
    Quantity = 1;
    ItemState = EItemState::Normal;
    ItemID = NAME_None;
    LastUsedTime = 0.0f;

    // 清除物品数据
    ItemData = FItemData();

    // 生成新的唯一ID
    UniqueID = FGuid::NewGuid();
}

const UItemDefinition* AInventoryItem::GetItemDefinition() const
{
    const UInventorySettings* Settings = GetDefault<UInventorySettings>();
    return Settings ? Settings->GetItemDefinition() : nullptr;
}