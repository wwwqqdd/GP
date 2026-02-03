// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventorySettings.h"
#include "Inventory/ItemDefinition.h"


const UItemDefinition* UInventorySettings::GetItemDefinition() const
{
	return ItemDataAsset.LoadSynchronous();
}

const UConsumableItem* UInventorySettings::GetConsumableItem() const
{
	return ConsumableDataAsset.LoadSynchronous();
}

bool UInventorySettings::GetItemData(FName ItemID, FItemData& OutItemData) const
{
	const UItemDefinition* ItemDefinition = GetItemDefinition();
    
	if (!ItemDefinition || !ItemDefinition->ItemDataMap.Contains(ItemID))
	{
		return false;
	}
    
	OutItemData = ItemDefinition->ItemDataMap[ItemID];
	return true;
}




