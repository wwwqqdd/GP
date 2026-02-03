// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_Aim.h"

#include "GameplayProjectCharacter.h"
#include "GameplayProjectAttributeSet.h"

void UGameplayAbility_Aim::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	float CurrentBulletNum = 0.f;
	float MaxTotalBulletNum = 0.f;

	if (!ActorInfo && !ActorInfo->AvatarActor.IsValid()) return;

	const AGameplayProjectCharacter* Character = Cast<AGameplayProjectCharacter>(ActorInfo->AvatarActor.Get());
	
	if (Character && Character->GetAttributeSet())
	{
		CurrentBulletNum = Character->GetAttributeSet()->GetBulletNum();
		MaxTotalBulletNum = Character->GetAttributeSet()->GetTotalBulletNum();
	}
	if (MaxTotalBulletNum <= 0.f) return;
	if (CurrentBulletNum > 0)
	{
		
		if (AimMontage)
		{
			MontagePlayInfo.MontageToPlay = AimMontage;
			CurrentBulletNum = 0.f;
			Character->GetAttributeSet()->SetBulletNum(CurrentBulletNum);
			Character->GetAttributeSet()->SetTotalBulletNum(MaxTotalBulletNum - 20.0f);
		}
	}
	else
	{
		if (ReloadMontage)
		{
			MontagePlayInfo.MontageToPlay = ReloadMontage;
			CurrentBulletNum += 1.f;
			Character->GetAttributeSet()->SetBulletNum(CurrentBulletNum);
		}
	}
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UGameplayAbility_Aim::OnMontageStarted()
{
	
}

void UGameplayAbility_Aim::OnMontageCancelled()
{
	
}

void UGameplayAbility_Aim::OnMontageInterrupted()
{
	
}

void UGameplayAbility_Aim::OnMontageComplete()
{
	
}



bool UGameplayAbility_Aim::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UGameplayAbility_Aim::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
