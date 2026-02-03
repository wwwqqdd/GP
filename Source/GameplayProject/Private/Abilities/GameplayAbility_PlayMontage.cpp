// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_PlayMontage.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

void UGameplayAbility_PlayMontage::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo)) 
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, /*bReplicateEndAbility*/ true, /*bWasCancelled*/ true);
		return;
	}
	
	if (!MontagePlayInfo.MontageToPlay)
	{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
		UE_LOG(LogTemp, Warning, TEXT("UGameplayAbility_PlayMontage: MontageOnPlay is null."));
#endif
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}
	
	UAbilityTask_PlayMontageAndWait* PlayMontageAndWait =
		UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(
			this,
			MontagePlayInfo.TaskInstanceName,
			MontagePlayInfo.MontageToPlay,
			MontagePlayInfo.Rate,
			MontagePlayInfo.StartSection,
			MontagePlayInfo.bStopWhenAbilityEnds,
			MontagePlayInfo.AnimRootMotionTranslationScale,
			MontagePlayInfo.StartTimeSeconds,
			MontagePlayInfo.bAllowInterruptAfterBlendOut
		);
	if (PlayMontageAndWait)
	{
		PlayMontageAndWait->OnCompleted.AddDynamic(this, &UGameplayAbility_PlayMontage::OnMontageComplete);
		PlayMontageAndWait->OnCancelled.AddDynamic(this, &UGameplayAbility_PlayMontage::OnMontageCancelled);
		PlayMontageAndWait->OnInterrupted.AddDynamic(this, &UGameplayAbility_PlayMontage::OnMontageInterrupted);
		PlayMontageAndWait->ReadyForActivation();

		OnMontageStarted();
	}
	else
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
	}
}
 
void UGameplayAbility_PlayMontage::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UGameplayAbility_PlayMontage::OnMontageStarted()
{
	
}

void UGameplayAbility_PlayMontage::OnMontageComplete()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}
 
void UGameplayAbility_PlayMontage::OnMontageCancelled()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
 
void UGameplayAbility_PlayMontage::OnMontageInterrupted()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
