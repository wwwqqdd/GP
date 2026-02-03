// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_DoubleJump.h"

#include "ReplayTypes.h"
 
#include "GameplayProjectCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
bool UGameplayAbility_DoubleJump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	const bool bCanActivate = Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
	if (!bCanActivate)
	{
		return false;
	}
	
	const AGameplayProjectCharacter* Character = Cast<AGameplayProjectCharacter>(ActorInfo->OwnerActor);
	if (!Character)
	{
		return false;
	}
	const UCharacterMovementComponent* CharacterMovement = Character->GetCharacterMovement();
	if (!CharacterMovement)
	{
		return false;
	}
 
	//检测一下角色是否在空中
	const bool bCanDoubleJump = CharacterMovement->IsFalling();
	return bCanDoubleJump;
}
 
void UGameplayAbility_DoubleJump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	AGameplayProjectCharacter* Character = Cast<AGameplayProjectCharacter>(GetOwningActorFromActorInfo());
	if (!IsValid(Character)) return;
	
	Character->LandedDelegate.RemoveDynamic(this, &UGameplayAbility_DoubleJump::CancelAbilityOnLanded);
	
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
 

void UGameplayAbility_DoubleJump::OnMontageStarted()
{
	AGameplayProjectCharacter* Character = Cast<AGameplayProjectCharacter>(GetOwningActorFromActorInfo());
	if (!IsValid(Character)) return;
	
	Character->LandedDelegate.AddDynamic(this, &UGameplayAbility_DoubleJump::CancelAbilityOnLanded);
	
	Character->LaunchCharacter(FVector(0.f,0.f,JumpLaunchVelocity),false,true);
}

void UGameplayAbility_DoubleJump::OnMontageCancelled()
{
	
}

void UGameplayAbility_DoubleJump::OnMontageInterrupted()
{
	
}

void UGameplayAbility_DoubleJump::OnMontageComplete()
{
	
}


void UGameplayAbility_DoubleJump::CancelAbilityOnLanded(const FHitResult& Hit)
{
	CancelAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false);
}
