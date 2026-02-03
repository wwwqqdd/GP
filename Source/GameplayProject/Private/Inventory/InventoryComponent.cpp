#include "Inventory/InventoryComponent.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Inventory/ConsumableItem.h"
#include "Inventory/InventoryItem.h"
#include "Inventory/InventorySettings.h"


UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	if (InventorySlots.Num() == 0)
	{
		InitializeInventory(InventorySize, EquipmentSlotCount, QuickAccessSize);
	}
}

void UInventoryComponent::InitializeInventory(int32 InInventorySize, int32 InEquipmentSlotCount, int32 InQuickAccessSize)
{
	InventorySlots.Empty();
	InventorySize = FMath::Max(1, InInventorySize);
	EquipmentSlotCount = FMath::Max(0, InEquipmentSlotCount);
	QuickAccessSize = FMath::Max(0, InQuickAccessSize);
	
	for (int32 i = 0; i < InventorySize; ++i)
	{
		FInventorySlot Slot;
		Slot.SlotIndex = i;
		Slot.SlotType = ESlotType::Inventory;
		Slot.EquipmentSlot = EEquipmentSlot::MainHand;
		InventorySlots.Add(Slot);
	}

	// 初始化装备槽位
	TArray<EEquipmentSlot> EquipmentSlots = {
		EEquipmentSlot::Head,
		EEquipmentSlot::Chest,
		EEquipmentSlot::Legs,
		EEquipmentSlot::Feet,
		EEquipmentSlot::MainHand,
		EEquipmentSlot::OffHand,
		EEquipmentSlot::Accessory1,
		EEquipmentSlot::Accessory2
	};
	
	if (EquipmentSlotCount < EquipmentSlots.Num())
	{
		EquipmentSlots.SetNum(EquipmentSlotCount);
	}

	int32 CurrentSlotIndex = InventorySize;
	for (EEquipmentSlot EquipSlot : EquipmentSlots)
	{
		FInventorySlot Slot;
		Slot.SlotIndex = CurrentSlotIndex;
		Slot.SlotType = ESlotType::Equipment;
		Slot.EquipmentSlot = EquipSlot;
		InventorySlots.Add(Slot);
		CurrentSlotIndex++;
	}
	for (int32 i = 0; i < QuickAccessSize; ++i)
	{
		FInventorySlot Slot;
		Slot.SlotIndex = CurrentSlotIndex;
		Slot.SlotType = ESlotType::QuickAccess;
		Slot.EquipmentSlot = EEquipmentSlot::MainHand;
		InventorySlots.Add(Slot);
		CurrentSlotIndex++;
	}
	
	OnInventoryChanged.Broadcast(-1);
}

int32 UInventoryComponent::AddItem(FName ItemID, int32 Quantity, bool bForceToSpecificSlot, int32 TargetSlotIndex)
{
	if (Quantity <= 0 || ItemID == NAME_None) return 0;
	
	FItemData ItemData;
	if (!GetItemData(ItemID, ItemData)) return 0;
	
	return AddItemWithData(ItemData, Quantity, bForceToSpecificSlot, TargetSlotIndex);
}

int32 UInventoryComponent::AddItemWithData(const FItemData& ItemData, int32 Quantity, bool bForceToSpecificSlot, int32 TargetSlotIndex)
{
	if (Quantity <= 0 || ItemData.ItemID == NAME_None) return 0;
	
	int32 RemainingQuantity = Quantity;
	UWorld* World = GetWorld();
	if (!World) return 0;
	
	if (bForceToSpecificSlot && IsValidSlotIndex(TargetSlotIndex))
	{
		FInventorySlot& TargetSlot = InventorySlots[TargetSlotIndex];
		if (TargetSlot.bIsLocked)
		{
			return 0;
		}
		AInventoryItem* NewItem = World->SpawnActor<AInventoryItem>(AInventoryItem::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
		
		if (TargetSlot.IsEmpty())
		{
			if (NewItem)
			{
				NewItem->InitializeWithData(ItemData, FMath::Min(RemainingQuantity, ItemData.MaxStackSize));
				TargetSlot.Item = NewItem;
				RemainingQuantity -= NewItem->Quantity;

				OnItemAdded.Broadcast(ItemData.ItemID, NewItem->Quantity);
				NotifyInventoryChanged(TargetSlotIndex);
			}
		}
		else if (TargetSlot.Item->CanMergeWith(NewItem)) 
		{
			AInventoryItem* ExistingItem = TargetSlot.Item;
			int32 AddedAmount = ExistingItem->AddQuantity(RemainingQuantity);
			RemainingQuantity -= AddedAmount;

			OnItemAdded.Broadcast(ItemData.ItemID, AddedAmount);
			NotifyInventoryChanged(TargetSlotIndex);
		}

		return Quantity - RemainingQuantity;
	}

	if (ItemData.bCanStack)
	{
		int32 StackableSlotIndex = FindStackableSlot(ItemData.ItemID);
		while (RemainingQuantity > 0 && StackableSlotIndex != -1)
		{
			FInventorySlot& StackSlot = InventorySlots[StackableSlotIndex];
			AInventoryItem* ExistingItem = StackSlot.Item;

			int32 AddedAmount = ExistingItem->AddQuantity(RemainingQuantity);
			RemainingQuantity -= AddedAmount;

			OnItemAdded.Broadcast(ItemData.ItemID, AddedAmount);
			NotifyInventoryChanged(StackableSlotIndex);
			
			StackableSlotIndex = FindStackableSlot(ItemData.ItemID);
		}
	}
	
	while (RemainingQuantity > 0)
	{
		int32 EmptySlotIndex = FindEmptySlot(ESlotType::Inventory);
		if (EmptySlotIndex == -1)
		{
			break;
		}

		FInventorySlot& EmptySlot = InventorySlots[EmptySlotIndex];
		int32 AddAmount = FMath::Min(RemainingQuantity, ItemData.MaxStackSize);
		
		AInventoryItem* NewItem = World->SpawnActor<AInventoryItem>(AInventoryItem::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
		if (NewItem)
		{
			NewItem->InitializeWithData(ItemData, AddAmount);
			EmptySlot.Item = NewItem;
			RemainingQuantity -= AddAmount;

			OnItemAdded.Broadcast(ItemData.ItemID, AddAmount);
			NotifyInventoryChanged(EmptySlotIndex);
		}
		else
		{
			break;
		}
	}

	return Quantity - RemainingQuantity;
}

int32 UInventoryComponent::RemoveItem(const FName& ItemID, int32 Quantity)
{
	if (Quantity <= 0 || ItemID == NAME_None)
	{
		return 0;
	}

	int32 RemovedQuantity = 0;
	int32 RemainingToRemove = Quantity;

	// 遍历所有库存槽位，查找对应物品
	for (int32 i = 0; i < InventorySlots.Num() && RemainingToRemove > 0; ++i)
	{
		FInventorySlot& Slot = InventorySlots[i];
		if (Slot.IsEmpty() || Slot.Item->GetItemID() != ItemID)
		{
			continue;
		}

		int32 RemovedFromSlot = RemoveItemFromSlot(i, RemainingToRemove);
		RemovedQuantity += RemovedFromSlot;
		RemainingToRemove -= RemovedFromSlot;
	}

	return RemovedQuantity;
}


int32 UInventoryComponent::RemoveItemFromSlot(int32 SlotIndex, int32 Quantity)
{
	if (!IsValidSlotIndex(SlotIndex) || Quantity <= 0) return 0;
	

	FInventorySlot& Slot = InventorySlots[SlotIndex];
	if (Slot.IsEmpty() || Slot.bIsLocked) return 0;

	AInventoryItem* Item = Slot.Item;
	int32 ActualRemoved = Item->RemoveQuantity(Quantity);

	// 物品数量为0时，清空槽位并销毁物品
	if (Item->Quantity <= 0)
	{
		Item->Destroy();
		Slot.Clear();
	}

	OnItemRemoved.Broadcast(Item->GetItemID(), ActualRemoved);
	NotifyInventoryChanged(SlotIndex);

	return ActualRemoved;
}

void UInventoryComponent::ClearSlot(int32 SlotIndex)
{
	if (!IsValidSlotIndex(SlotIndex)) return;

	FInventorySlot& Slot = InventorySlots[SlotIndex];
	if (Slot.IsEmpty() || Slot.bIsLocked) return;
	
	
	if (Slot.Item)
	{
		OnItemRemoved.Broadcast(Slot.Item->GetItemID(), Slot.Item->Quantity);
		Slot.Item->Destroy();
	}

	Slot.Clear();
	NotifyInventoryChanged(SlotIndex);
}

bool UInventoryComponent::SplitItemInSlot(int32 SourceSlotIndex, int32 SplitAmount, int32 TargetSlotIndex)
{
	if (!IsValidSlotIndex(SourceSlotIndex) || SplitAmount <= 0) return false;
	
	FInventorySlot& SourceSlot = InventorySlots[SourceSlotIndex];
	if (SourceSlot.IsEmpty() || SourceSlot.bIsLocked || !SourceSlot.Item->CanStack()) return false;
	

	AInventoryItem* SourceItem = SourceSlot.Item;
	if (SplitAmount >= SourceItem->Quantity) return false;
	
	int32 FinalTargetSlotIndex = TargetSlotIndex;
	if (!IsValidSlotIndex(FinalTargetSlotIndex))
	{
		FinalTargetSlotIndex = FindEmptySlot(ESlotType::Inventory);
	}

	if (FinalTargetSlotIndex == -1 || InventorySlots[FinalTargetSlotIndex].bIsLocked) return false;
	

	FInventorySlot& TargetSlot = InventorySlots[FinalTargetSlotIndex];
	if (!TargetSlot.IsEmpty()) return false;
	
	AInventoryItem* SplitItem = nullptr;
	if (SourceItem->SplitItem(SplitAmount, SplitItem) && SplitItem)
	{
		TargetSlot.Item = SplitItem;
		NotifyInventoryChanged(SourceSlotIndex);
		NotifyInventoryChanged(FinalTargetSlotIndex);
		return true;
	}

	return false;
}


int32 UInventoryComponent::MergeItemSlots(int32 SourceSlotIndex, int32 TargetSlotIndex)
{
	if (!IsValidSlotIndex(SourceSlotIndex) || !IsValidSlotIndex(TargetSlotIndex) || SourceSlotIndex == TargetSlotIndex)
	{
		return 0;
	}

	FInventorySlot& SourceSlot = InventorySlots[SourceSlotIndex];
	FInventorySlot& TargetSlot = InventorySlots[TargetSlotIndex];

	if (SourceSlot.IsEmpty() || TargetSlot.IsEmpty() || SourceSlot.bIsLocked || TargetSlot.bIsLocked)
	{
		return 0;
	}

	AInventoryItem* SourceItem = SourceSlot.Item;
	AInventoryItem* TargetItem = TargetSlot.Item;
	
	if (!SourceItem->CanMergeWith(TargetItem))
	{
		return 0;
	}
	
	int32 MergeAmount = TargetItem->AddQuantity(SourceItem->Quantity);
	int32 RemainingInSource = SourceItem->Quantity - MergeAmount;
	
	if (RemainingInSource <= 0)
	{
		SourceItem->Destroy();
		SourceSlot.Clear();
	}
	else
	{
		SourceItem->Quantity = RemainingInSource;
	}

	OnItemRemoved.Broadcast(SourceItem->GetItemID(), MergeAmount);
	NotifyInventoryChanged(SourceSlotIndex);
	NotifyInventoryChanged(TargetSlotIndex);

	return MergeAmount;
}

bool UInventoryComponent::SwapSlots(int32 SlotIndex1, int32 SlotIndex2)
{
	if (!IsValidSlotIndex(SlotIndex1) || !IsValidSlotIndex(SlotIndex2) || SlotIndex1 == SlotIndex2)
	{
		return false;
	}

	FInventorySlot& Slot1 = InventorySlots[SlotIndex1];
	FInventorySlot& Slot2 = InventorySlots[SlotIndex2];

	if (Slot1.bIsLocked || Slot2.bIsLocked)
	{
		return false; // 锁定槽位不可交换
	}

	// 交换槽位内的物品
	AInventoryItem* TempItem = Slot1.Item;
	Slot1.Item = Slot2.Item;
	Slot2.Item = TempItem;

	NotifyInventoryChanged(SlotIndex1);
	NotifyInventoryChanged(SlotIndex2);

	return true;
}

bool UInventoryComponent::EquipItem(int32 ItemSlotIndex, EEquipmentSlot TargetEquipmentSlot)
{
	if (!IsValidSlotIndex(ItemSlotIndex)) return false;
	

	FInventorySlot& ItemSlot = InventorySlots[ItemSlotIndex];
	if (ItemSlot.IsEmpty() || ItemSlot.bIsLocked || ItemSlot.SlotType == ESlotType::Equipment) return false;

	AInventoryItem* Item = ItemSlot.Item;
	if (Item->GetItemType() != EItemType::Equipment || Item->GetEquipmentSlot() != TargetEquipmentSlot) return false;
	
	int32 EquipSlotIndex = GetEquipmentSlotIndex(TargetEquipmentSlot);
	if (EquipSlotIndex == -1) return false;

	FInventorySlot& EquipSlot = InventorySlots[EquipSlotIndex];
	
	if (!EquipSlot.IsEmpty())
	{
		if (!UnequipItem(TargetEquipmentSlot))
		{
			return false;
		}
	}
	
	EquipSlot.Item = Item;
	ItemSlot.Clear();
	Item->SetItemState(EItemState::Equipped);
	
	OnItemEquipped.Broadcast(EquipSlot);
	NotifyInventoryChanged(ItemSlotIndex);
	NotifyInventoryChanged(EquipSlotIndex);

	return true;
}

bool UInventoryComponent::UnequipItem(EEquipmentSlot EquipmentSlot)
{
	// 获取装备槽位索引
	int32 EquipSlotIndex = GetEquipmentSlotIndex(EquipmentSlot);
	if (EquipSlotIndex == -1) return false;
	

	FInventorySlot& EquipSlot = InventorySlots[EquipSlotIndex];
	if (EquipSlot.IsEmpty()) return false;
	
	AInventoryItem* EquippedItem = EquipSlot.Item;
	
	int32 EmptyInventorySlot = FindEmptySlot(ESlotType::Inventory);
	if (EmptyInventorySlot == -1) return false; 
	
	FInventorySlot& EmptySlot = InventorySlots[EmptyInventorySlot];
	EmptySlot.Item = EquippedItem;
	EquipSlot.Clear();
	EquippedItem->SetItemState(EItemState::Normal);

	NotifyInventoryChanged(EquipSlotIndex);
	NotifyInventoryChanged(EmptyInventorySlot);

	return true;
}

FInventorySlot UInventoryComponent::GetEquippedItemInSlot(EEquipmentSlot EquipmentSlot) const
{
	int32 EquipSlotIndex = GetEquipmentSlotIndex(EquipmentSlot);
	
	if (EquipSlotIndex != -1 && IsValidSlotIndex(EquipSlotIndex))
	{
		return InventorySlots[EquipSlotIndex];
	}

	// 返回空槽位
	return FInventorySlot();
}

bool UInventoryComponent::UseItem(int32 SlotIndex)
{
	if (!IsValidSlotIndex(SlotIndex))  return false;
	
	FInventorySlot& Slot = InventorySlots[SlotIndex];
	if (Slot.IsEmpty()) return false;

	AInventoryItem* Item = Slot.Item;
	
	// 额外检查Item指针的有效性
	if (!IsValid(Item)) return false;
	
	if (!Item->CanUse())  return false;

	
	bool bUseSuccess = false;
	switch (Item->GetItemData().ItemType)
	{
	case EItemType::Consumable:
		bUseSuccess = ApplyConsumableEffect(Item);
		break;
            
	case EItemType::Equipment:
		bUseSuccess = EquipItem(SlotIndex, Item->GetItemData().EquipmentSlot);
		break;
            
	default:
		bUseSuccess = false;
		break;
	}

	if (bUseSuccess)
	{
		Item->MarkUsed();
        
		if (Item->GetItemData().ItemType == EItemType::Consumable)
		{
			RemoveItemFromSlot(SlotIndex, 1);
		}
		OnItemUsed.Broadcast(Item->GetItemID());
	}
	return bUseSuccess;
}

FInventorySlot UInventoryComponent::GetInventorySlot(int32 SlotIndex) const
{
	return InventorySlots[SlotIndex];
}

int32 UInventoryComponent::FindEmptySlot(ESlotType SlotType) const
{
	for (int32 i = 0; i < InventorySlots.Num(); ++i)
	{
		const FInventorySlot& Slot = InventorySlots[i];
		if (Slot.SlotType == SlotType && Slot.IsEmpty() && !Slot.bIsLocked)
		{
			return i;
		}
	}

	return -1;
}

int32 UInventoryComponent::FindStackableSlot(FName ItemID) const
{
	for (int32 i = 0; i < InventorySlots.Num(); ++i)
	{
		const FInventorySlot& Slot = InventorySlots[i];
		if (Slot.IsEmpty() || Slot.bIsLocked || Slot.SlotType != ESlotType::Inventory)
		{
			continue;
		}

		AInventoryItem* Item = Slot.Item;
		if (Item->GetItemID() == ItemID && Item->CanStack() && Item->GetRemainingStackSpace() > 0)
		{
			return i;
		}
	}

	return -1;
}

int32 UInventoryComponent::GetItemCount(const FName& ItemID) const
{
	if (ItemID == NAME_None)
	{
		return 0;
	}

	int32 TotalCount = 0;
	for (const FInventorySlot& Slot : InventorySlots)
	{
		if (!Slot.IsEmpty() && Slot.Item->GetItemID() == ItemID)
		{
			TotalCount += Slot.Item->Quantity;
		}
	}

	return TotalCount;
}

bool UInventoryComponent::HasEnoughSpace(FName ItemID, int32 Quantity) const
{
	if (Quantity <= 0 || ItemID == NAME_None) return true;
	
	FItemData ItemData;
	if (!GetItemData(ItemID, ItemData))
	{
		return false;
	}
	
	int32 RemainingStackSpace = 0;
	for (const FInventorySlot& Slot : InventorySlots)
	{
		if (Slot.IsEmpty() || Slot.bIsLocked || Slot.SlotType != ESlotType::Inventory)
		{
			continue;
		}

		if (!Slot.IsEmpty() && Slot.Item->GetItemID() == ItemID && Slot.Item->CanStack())
		{
			RemainingStackSpace += Slot.Item->GetRemainingStackSpace();
		}
	}
	
	int32 EmptySlotCount = 0;
	for (const FInventorySlot& Slot : InventorySlots)
	{
		if (Slot.SlotType == ESlotType::Inventory && Slot.IsEmpty() && !Slot.bIsLocked)
		{
			EmptySlotCount++;
		}
	}

	int32 EmptySlotCapacity = EmptySlotCount * ItemData.MaxStackSize;
	int32 TotalAvailableSpace = RemainingStackSpace + EmptySlotCapacity;

	return TotalAvailableSpace >= Quantity;
}

void UInventoryComponent::SetSlotLocked(int32 SlotIndex, bool bLocked)
{
	if (!IsValidSlotIndex(SlotIndex))
	{
		return;
	}

	InventorySlots[SlotIndex].bIsLocked = bLocked;
	NotifyInventoryChanged(SlotIndex);
}

void UInventoryComponent::ClearAllInventory()
{
	for (int32 i = 0; i < InventorySlots.Num(); ++i)
	{
		ClearSlot(i);
	}

	// 广播全局库存变更
	OnInventoryChanged.Broadcast(-1);
}

bool UInventoryComponent::IsValidSlotIndex(int32 SlotIndex) const
{
	return InventorySlots.IsValidIndex(SlotIndex) && SlotIndex >= 0;
}

const UItemDefinition* UInventoryComponent::GetItemDefinition() const
{
	UInventorySettings* Settings = GetMutableDefault<UInventorySettings>();
	if (Settings)
	{
		return Settings->GetItemDefinition();
	}
	return nullptr;
}

bool UInventoryComponent::GetItemData(FName ItemID, FItemData& OutItemData) const
{
	const UItemDefinition* ItemDef = GetItemDefinition();
	if (!ItemDef || !ItemDef->ItemDataMap.Contains(ItemID))
	{
		return false;
	}

	OutItemData = ItemDef->ItemDataMap[ItemID];
	return true;
}

int32 UInventoryComponent::GetEquipmentSlotIndex(EEquipmentSlot EquipmentSlot) const
{
	int32 EquipmentSlotStartIndex = InventorySize;
	
	for (int32 i = 0; i < EquipmentSlotCount; ++i)
	{
		if (InventorySlots.IsValidIndex(EquipmentSlotStartIndex + i))
		{
			const FInventorySlot& Slot = InventorySlots[EquipmentSlotStartIndex + i];
			if (Slot.EquipmentSlot == EquipmentSlot && Slot.SlotType == ESlotType::Equipment)
			{
				return EquipmentSlotStartIndex + i;
			}
		}
	}

	return -1;
}

void UInventoryComponent::NotifyInventoryChanged(int32 SlotIndex)
{
	if (IsValidSlotIndex(SlotIndex))
	{
		OnInventoryChanged.Broadcast(SlotIndex);
	}
}

bool UInventoryComponent::ApplyConsumableEffect(AInventoryItem* ConsumableItem)
{
	if (!ConsumableItem || ConsumableItem->GetItemData().ItemType != EItemType::Consumable) return false;
	

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return false;
	
	
	const UInventorySettings* InventorySettings = GetDefault<UInventorySettings>();
	if (!InventorySettings) return false;

	const UConsumableItem* ConsumableData = InventorySettings->GetConsumableItem();
	if (!ConsumableData) return false;
	
	
	const FName TargetItemID = ConsumableItem->GetItemID();
	UAbilitySystemComponent* ASC = OwnerCharacter->GetComponentByClass<UAbilitySystemComponent>();
	if (!ASC) return false;
	

	for (const FConsumableItemData& Data : ConsumableData->ConsumableItems)
	{
		if (Data.ConsumableItemData.ItemID != TargetItemID || !Data.Effect)
		{
			continue;
		}
		
		UGameplayEffect* DefaultGameplayEffect = Data.Effect->GetDefaultObject<UGameplayEffect>();
		if (!DefaultGameplayEffect)
		{
			continue;
		}
		
		FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
		EffectContext.AddSourceObject(ConsumableItem);
		const FActiveGameplayEffectHandle EffectHandle = ASC->ApplyGameplayEffectToSelf(DefaultGameplayEffect,1.0f, EffectContext);
		
		if (EffectHandle.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("ApplyConsumableEffect: 角色%s成功应用消耗品%s效果"), *OwnerCharacter->GetName(), *ConsumableItem->GetDisplayName().ToString());
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ApplyConsumableEffect: 角色%s应用消耗品%s效果失败（Effect应用返回无效句柄）"), *OwnerCharacter->GetName(), *TargetItemID.ToString());
			return false;
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("ApplyConsumableEffect: 消耗品%s未找到匹配的GameplayEffect（ItemID: %s）"), *ConsumableItem->GetDisplayName().ToString(), *TargetItemID.ToString());
	return false;
}
