// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Actor/ElectricArrow.h"
#include "SpawnElectricArrow.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;

UCLASS()
class GAMEPLAYPROJECT_API USpawnElectricArrow : public UGameplayAbility
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Electric Arrow")
	TSubclassOf<AElectricArrow> ElectricArrow;
};
