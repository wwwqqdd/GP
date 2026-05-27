// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction/PickupActor.h"
#include "Components/StaticMeshComponent.h"
#include "Inventory/InventoryComponent.h"
#include "GameplayProjectCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogPickup, Log, All);

#define LOCTEXT_NAMESPACE "PickupActor"

APickupActor::APickupActor()
{
    PrimaryActorTick.bCanEverTick = false;
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    // 让 InteractionComponent 的球能 overlap 到：设为 WorldDynamic 且产生 overlap
    Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    Mesh->SetCollisionObjectType(ECC_WorldDynamic);
    Mesh->SetGenerateOverlapEvents(true);
}

FInteractionPrompt APickupActor::GetInteractionPrompt_Implementation() const
{
    if (!PromptOverride.Text.IsEmpty())
    {
        return PromptOverride;
    }
    FInteractionPrompt Fallback = PromptOverride;
    Fallback.Text = LOCTEXT("DefaultPickupPrompt", "[E] 拾取");
    return Fallback;
}

void APickupActor::OnInteract_Implementation(AActor* InteractInstigator)
{
    AGameplayProjectCharacter* Char = Cast<AGameplayProjectCharacter>(InteractInstigator);
    if (!Char)
    {
        UE_LOG(LogPickup, Verbose, TEXT("Pickup: Instigator 不是角色"));
        return;
    }
    UInventoryComponent* Inv = Char->FindComponentByClass<UInventoryComponent>();
    if (!Inv)
    {
        UE_LOG(LogPickup, Warning, TEXT("Pickup: 角色无 InventoryComponent"));
        return;
    }

    const int32 Added = Inv->AddItem(ItemID, Quantity);
    if (Added >= Quantity)
    {
        Destroy();
    }
    else if (Added > 0)
    {
        Quantity -= Added; // 部分入库，剩余留在场上
        UE_LOG(LogPickup, Verbose, TEXT("Pickup: 部分入库 %d，剩余 %d"), Added, Quantity);
    }
    else
    {
        UE_LOG(LogPickup, Verbose, TEXT("Pickup: 库存已满，未入库"));
    }
}

#undef LOCTEXT_NAMESPACE
