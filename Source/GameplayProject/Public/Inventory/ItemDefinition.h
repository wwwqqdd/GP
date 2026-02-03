// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "ItemDefinition.generated.h"


class AInventoryItem;

UENUM(BlueprintType)
enum class EItemType : uint8
{
    Consumable    UMETA(DisplayName = "Consumable"),
    Equipment     UMETA(DisplayName = "Equipment"),
    Resource      UMETA(DisplayName = "Resource"),
    Quest         UMETA(DisplayName = "Quest"),
    Currency      UMETA(DisplayName = "Currency")
};

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
    Common        UMETA(DisplayName = "Common"),
    Uncommon      UMETA(DisplayName = "Uncommon"),
    Rare          UMETA(DisplayName = "Rare"),
    Epic          UMETA(DisplayName = "Epic"),
    Legendary     UMETA(DisplayName = "Legendary"),
    Mythic        UMETA(DisplayName = "Mythic")
};

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8
{
    Head           UMETA(DisplayName = "Head"),
    Chest          UMETA(DisplayName = "Chest"),
    Legs           UMETA(DisplayName = "Legs"),
    Feet           UMETA(DisplayName = "Feet"),
    MainHand       UMETA(DisplayName = "MainHand"),
    OffHand        UMETA(DisplayName = "offHand"),
    Accessory1     UMETA(DisplayName = "Accessory1"),
    Accessory2     UMETA(DisplayName = "Accessory2")
};

USTRUCT(BlueprintType)
struct FItemData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    EItemType ItemType;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    FName ItemID;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
    FText DisplayName;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
    FText Description;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
    EItemRarity Rarity;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    TSoftObjectPtr<UTexture2D> IconTexture;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    TSoftObjectPtr<UStaticMesh> WorldMesh;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    TSubclassOf<AInventoryItem> Item;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stacking")
    bool bCanStack;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stacking", meta = (EditCondition = "bCanStack", ClampMin = "1", ClampMax = "99"))
    int32 MaxStackSize;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
    int32 BuyValue;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
    int32 SellValue;
    
    // 物品使用条件
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Usage")
    bool bCanUseInCombat = true;
    
    // 使用冷却时间
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Usage")
    float UseCooldown = 1.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment", meta = (EditCondition = "ItemType == EItemType::Equipment"))
    EEquipmentSlot EquipmentSlot = EEquipmentSlot::MainHand;
    
    FItemData()
        : ItemType(EItemType::Equipment)
        , ItemID(NAME_None)
        , Rarity(EItemRarity::Common)
        , bCanStack(true)
        , MaxStackSize(99)
        , BuyValue(0)
        , SellValue(0)
    {}
};

UCLASS(Blueprintable, BlueprintType)
class GAMEPLAYPROJECT_API UItemDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    TMap<FName,FItemData> ItemDataMap;
};
