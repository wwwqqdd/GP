// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventorySlot.h"

bool FInventorySlot::IsEmpty() const
{
	return Item == nullptr;
}

FText FInventorySlot::GetSlotDisplayName() const
{
	switch (SlotType)
	{
	case ESlotType::Inventory:
		return FText::Format(NSLOCTEXT("Inventory", "InventorySlotDisplayName", "Inventory Slot {0}"), FText::AsNumber(SlotIndex + 1));
		
	case ESlotType::Equipment:
		{
			FString SlotName = UEnum::GetValueAsString(EquipmentSlot);
			return FText::FromString(SlotName);
		}
		
	case ESlotType::QuickAccess:
		{
			return FText::Format(NSLOCTEXT("Inventory", "QuickAccessSlotDisplayName", "Quick Access {0}"), FText::AsNumber(SlotIndex /*- InventorySize - EquipmentSlotCount + 1)*/));
		}

	case ESlotType::Storage:
		return FText::Format(NSLOCTEXT("Inventory", "StorageSlotDisplayName", "Storage Slot {0}"), FText::AsNumber(SlotIndex + 1));
		
	default:
		return FText::NSLOCTEXT("Inventory", "UnknownSlotDisplayName", "Unknown Slot");
	}
}
