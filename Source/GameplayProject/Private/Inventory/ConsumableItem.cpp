// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/ConsumableItem.h"

UConsumableItem::UConsumableItem()
{
	FItemData itemData;
	itemData.ItemType = EItemType::Consumable;
}
