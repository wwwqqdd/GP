// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_PlayMontage.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FMontagePlayInfo
{
	GENERATED_BODY()
 
	/**
	 * 构造播放信息。
	 * @param TaskInstanceName 任务实例名称，用于区分同类播放任务。
	 * @param MontageToPlay 要播放的动画蒙太奇资源。
	 * @param Rate 播放速度倍率，1\.0 为正常速度。
	 * @param StartSection 起始播放的 Section 名称，None 表示从头开始。
	 * @param bStopWhenAbilityEnds 能力结束时是否立即停止该蒙太奇。
	 * @param AnimRootMotionTranslationScale 根运动平移缩放，用于调整位移幅度。
	 * @param StartTimeSeconds 从蒙太奇的指定时间偏移（秒）开始播放。
	 * @param bAllowInterruptAfterBlendOut 在 BlendOut 结束后是否允许被中断。
	 */
	
	[[nodiscard]] FMontagePlayInfo() = default;
 
	[[nodiscard]] FMontagePlayInfo(const FName& TaskInstanceName, UAnimMontage* const MontageToPlay, const float Rate,
								   const FName& StartSection, const bool bStopWhenAbilityEnds, const float AnimRootMotionTranslationScale,
								   const float StartTimeSeconds, const bool bAllowInterruptAfterBlendOut)
		: TaskInstanceName(TaskInstanceName),
		  MontageToPlay(MontageToPlay),
		  Rate(Rate),
		  StartSection(StartSection),
		  bStopWhenAbilityEnds(bStopWhenAbilityEnds),
		  AnimRootMotionTranslationScale(AnimRootMotionTranslationScale),
		  StartTimeSeconds(StartTimeSeconds),
		  bAllowInterruptAfterBlendOut(bAllowInterruptAfterBlendOut)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TaskInstanceName = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* MontageToPlay = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Rate = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName StartSection = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bStopWhenAbilityEnds = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AnimRootMotionTranslationScale = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartTimeSeconds = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAllowInterruptAfterBlendOut = false;
};
/**
 * 
 */
UCLASS()
class GAMEPLAYPROJECT_API UGameplayAbility_PlayMontage : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Montage")
	FMontagePlayInfo MontagePlayInfo;

	UFUNCTION(BlueprintCallable, Category="Ability|Montage")
	virtual void OnMontageStarted();
	
	UFUNCTION(BlueprintCallable, Category="Ability|Montage")
	virtual void OnMontageComplete();
	
	UFUNCTION(BlueprintCallable, Category="Ability|Montage")
	virtual void OnMontageCancelled();
	
	UFUNCTION(BlueprintCallable, Category="Ability|Montage")
	virtual void OnMontageInterrupted();

	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
								 const FGameplayAbilityActivationInfo ActivationInfo,
								 const FGameplayEventData* TriggerEventData) override;
	
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
							const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
							bool bWasCancelled) override;
	
};
