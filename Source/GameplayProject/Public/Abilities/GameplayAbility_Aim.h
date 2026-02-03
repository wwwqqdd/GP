// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility_PlayMontage.h"
#include "GameplayAbility_Aim.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYPROJECT_API UGameplayAbility_Aim : public UGameplayAbility_PlayMontage
{
	GENERATED_BODY()
public:
	/** 根据子弹数选择瞄准或换弹蒙太奇，最终仍然调用父类播放逻辑 */
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void OnMontageStarted() override;
	virtual void OnMontageCancelled() override;
	virtual void OnMontageInterrupted() override;
	virtual void OnMontageComplete() override;

	/** 瞄准蒙太奇：BulletNum > 0 时使用 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Aim")
	UAnimMontage* AimMontage = nullptr;

	/** 换弹蒙太奇：BulletNum == 0 时使用 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Aim")
	UAnimMontage* ReloadMontage = nullptr;

private:
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
};
