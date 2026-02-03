// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/SpawnElectricArrow.h"

#include "GameplayProjectCharacter.h"
#include "K2Node_SpawnActor.h"
#include "K2Node_SpawnActorFromClass.h"

void USpawnElectricArrow::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	AGameplayProjectCharacter* Character = Cast<AGameplayProjectCharacter>(GetAvatarActorFromActorInfo());
	if (!IsValid(Character)) return;

	FVector SpawnLocation = Character->GetActorLocation();
	FRotator SpawnRotation = Character->GetActorRotation();
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Character;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	UWorld* World = GetWorld();
	if (!World) return;

	AElectricArrow* Arrow = World->SpawnActor<AElectricArrow>(ElectricArrow, SpawnLocation, SpawnRotation, SpawnParams);
	
}

void USpawnElectricArrow::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	
}
