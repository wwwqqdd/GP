// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility_PlayMontage.h"
#include "GameplayAbility_DoubleJump.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYPROJECT_API UGameplayAbility_DoubleJump : public UGameplayAbility_PlayMontage
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="设置",DisplayName="二段跳起跳速度")
	float JumpLaunchVelocity = 600.f;
 
public:
	virtual void OnMontageStarted() override;
	virtual void OnMontageCancelled() override;
	virtual void OnMontageInterrupted() override;
	virtual void OnMontageComplete() override;
 
	UFUNCTION()
	void CancelAbilityOnLanded(const FHitResult& Hit);

private:
	virtual bool CanActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayTagContainer* SourceTags = nullptr,
		const FGameplayTagContainer* TargetTags = nullptr,
		FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
							const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
							bool bWasCancelled) override;
};
