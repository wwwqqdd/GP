// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/Interactable.h"
#include "Interaction/InteractionTypes.h"
#include "PickupActor.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class GAMEPLAYPROJECT_API APickupActor : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    APickupActor();

    // Inventory 数据键（对应 UItemDefinition::ItemDataMap 的 key）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    FName ItemID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    int32 Quantity = 1;

    // 策划直接填提示文字；为空时回退通用文案
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    FInteractionPrompt PromptOverride;

    // IInteractable
    virtual FInteractionPrompt GetInteractionPrompt_Implementation() const override;
    virtual void OnInteract_Implementation(AActor* Instigator) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    TObjectPtr<UStaticMeshComponent> Mesh;
};
