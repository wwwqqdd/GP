// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/GameplayEffectActor.h"
#include "Components/BoxComponent.h"
#include "ElectricArrow.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYPROJECT_API AElectricArrow : public AGameplayEffectActor
{
	GENERATED_BODY()
public:
	AElectricArrow();
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> Box;
};
