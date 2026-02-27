// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventorySettings.h"

#include "IDetailTreeNode.h"
#include "Inventory/ItemDefinition.h"


const UItemDefinition* UInventorySettings::GetItemDefinition() const
{
	if (!ItemDataAsset.IsNull())
	{
		return ItemDataAsset.LoadSynchronous();
	}
	return nullptr;
}

const UConsumableItem* UInventorySettings::GetConsumableItem() const
{
	if (!ConsumableDataAsset.IsNull())
	{
		return ConsumableDataAsset.LoadSynchronous();
	}
	return nullptr;
}

bool UInventorySettings::GetItemData(FName ItemID, FItemData& OutItemData) const
{
	const UItemDefinition* ItemDef = GetItemDefinition();
	if (!ItemDef)
	{
		return false;
	}

	const FItemData* Found = ItemDef->ItemDataMap.Find(ItemID);
	if (Found)
	{
		OutItemData = *Found;
		return true;
	}
	return false;
}




