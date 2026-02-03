// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameplayTagContainer.h"
#include "GameplayDamageTypes.generated.h"

class UAbilitySystemComponent;

/**
 * 伤害参数结构体，用于传递伤害相关的所有参数
 */
USTRUCT(BlueprintType)
struct FDamageEffectParams
{
	GENERATED_BODY()
	
	FDamageEffectParams()
	{
	}
	
	// ===== 基础上下文 =====
	
	/** 世界上下文对象（可选） */
	UPROPERTY(BlueprintReadWrite, Category = "Context")
	TObjectPtr<UObject> WorldContextObject = nullptr;
	
	/** 伤害的GameplayEffect类 */
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	TSubclassOf<UGameplayEffect> DamageGameplayEffectClass;
	
	/** 来源的AbilitySystemComponent */
	UPROPERTY(BlueprintReadWrite, Category = "Components")
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent = nullptr;
	
	/** 目标的AbilitySystemComponent */
	UPROPERTY(BlueprintReadWrite, Category = "Components")
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent = nullptr;
	
	// ===== 伤害属性 =====
	
	/** 基础伤害值 */
	UPROPERTY(BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0"))
	float BaseDamage = 0.0f;
	
	/** 技能等级 */
	UPROPERTY(BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "1.0"))
	float AbilityLevel = 1.0f;
	
	/** 伤害类型标签 */
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	FGameplayTag DamageType;
	
	/** 暴击率（0-100） */
	UPROPERTY(BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float CriticalHitChance = 0.0f;
	
	/** 暴击伤害倍率 */
	UPROPERTY(BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "1.0"))
	float CriticalHitMultiplier = 2.0f;
	
	/** 护甲穿透（0-100） */
	UPROPERTY(BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float ArmorPenetration = 0.0f;
	
	// ===== 负面效果属性 =====
	
	/** 施加负面效果的几率（0-100） */
	UPROPERTY(BlueprintReadWrite, Category = "Debuff", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float DebuffChance = 0.0f;
	
	/** 负面效果持续时间（秒） */
	UPROPERTY(BlueprintReadWrite, Category = "Debuff", meta = (ClampMin = "0.0"))
	float DebuffDuration = 0.0f;
	
	/** 负面效果造成的额外伤害 */
	UPROPERTY(BlueprintReadWrite, Category = "Debuff", meta = (ClampMin = "0.0"))
	float DebuffDamage = 0.0f;
	
	/** 负面效果触发频率（秒） */
	UPROPERTY(BlueprintReadWrite, Category = "Debuff", meta = (ClampMin = "0.0"))
	float DebuffFrequency = 0.0f;
	
	/** 负面效果的GameplayEffect类 */
	UPROPERTY(BlueprintReadWrite, Category = "Debuff")
	TSubclassOf<UGameplayEffect> DebuffGameplayEffectClass;
	
	// ===== 物理效果属性 =====
	
	/** 死亡冲击力大小 */
	UPROPERTY(BlueprintReadWrite, Category = "Physics", meta = (ClampMin = "0.0"))
	float DeathImpulseMagnitude = 0.0f;
	
	/** 死亡冲击力向量 */
	UPROPERTY(BlueprintReadWrite, Category = "Physics")
	FVector DeathImpulse = FVector::ZeroVector;
	
	/** 击退大小 */
	UPROPERTY(BlueprintReadWrite, Category = "Physics", meta = (ClampMin = "0.0"))
	float KnockbackMagnitude = 1000.0f;
	
	/** 击退几率（0-100） */
	UPROPERTY(BlueprintReadWrite, Category = "Physics", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float KnockbackChance = 0.0f;
	
	/** 击退力向量 */
	UPROPERTY(BlueprintReadWrite, Category = "Physics")
	FVector KnockbackForce = FVector::ZeroVector;
	
	// ===== 范围伤害属性 =====
	
	/** 是否是范围伤害 */
	UPROPERTY(BlueprintReadWrite, Category = "Radial Damage")
	bool bIsRadialDamage = false;
	
	/** 范围伤害内圈半径 */
	UPROPERTY(BlueprintReadWrite, Category = "Radial Damage", meta = (EditCondition = "bIsRadialDamage", ClampMin = "0.0"))
	float RadialDamageInnerRadius = 0.0f;
	
	/** 范围伤害外圈半径 */
	UPROPERTY(BlueprintReadWrite, Category = "Radial Damage", meta = (EditCondition = "bIsRadialDamage", ClampMin = "0.0"))
	float RadialDamageOuterRadius = 0.0f;
	
	/** 范围伤害衰减系数 */
	UPROPERTY(BlueprintReadWrite, Category = "Radial Damage", meta = (EditCondition = "bIsRadialDamage", ClampMin = "0.0", ClampMax = "1.0"))
	float RadialDamageFalloff = 1.0f;
	
	// ===== 命中信息 =====
	
	/** 命中位置 */
	UPROPERTY(BlueprintReadWrite, Category = "Hit Info")
	FVector HitLocation = FVector::ZeroVector;
	
	/** 命中法线 */
	UPROPERTY(BlueprintReadWrite, Category = "Hit Info")
	FVector HitNormal = FVector::ZeroVector;
	
	/** 命中方向 */
	UPROPERTY(BlueprintReadWrite, Category = "Hit Info")
	FVector HitDirection = FVector::ZeroVector;
	
	/** 命中的Actor（弱引用，避免循环引用） */
	UPROPERTY(BlueprintReadWrite, Category = "Hit Info")
	TWeakObjectPtr<AActor> HitActor = nullptr;
	
	// ===== 杂项 =====
	
	/** 自定义数据，可以用于传递额外信息 */
	UPROPERTY(BlueprintReadWrite, Category = "Misc")
	TMap<FName, float> CustomFloatParams;
	
	UPROPERTY(BlueprintReadWrite, Category = "Misc")
	TMap<FName, FString> CustomStringParams;
	
	// ===== 实用函数 =====
	
	/** 检查是否暴击 */
	bool CheckCriticalHit() const
	{
		return FMath::RandRange(0.0f, 100.0f) < CriticalHitChance;
	}
	
	/** 获取最终伤害值（考虑暴击） */
	float GetFinalDamage() const
	{
		float Damage = BaseDamage;
		if (CheckCriticalHit())
		{
			Damage *= CriticalHitMultiplier;
		}
		return Damage;
	}
	
	/** 检查是否触发击退 */
	bool CheckKnockback() const
	{
		return FMath::RandRange(0.0f, 100.0f) < KnockbackChance;
	}
	
	bool CheckDebuff() const
	{
		return FMath::RandRange(0.0f, 100.0f) < DebuffChance;
	}
	
	void InitializeFromHitResult(const FHitResult& HitResult)
	{
		HitLocation = HitResult.Location;
		HitNormal = HitResult.Normal;
    
		HitActor = HitResult.GetActor();
	}
	
	/** 计算死亡冲击力（基于给定的方向） */
	void CalculateDeathImpulse(const FVector& Direction)
	{
		if (DeathImpulseMagnitude > 0.0f && !Direction.IsNearlyZero())
		{
			DeathImpulse = Direction.GetSafeNormal() * DeathImpulseMagnitude;
		}
	}
	
	/** 计算击退力（基于给定的方向和角度） */
	void CalculateKnockbackForce(const FVector& Direction, float UpwardAngle = 45.0f)
	{
		if (KnockbackMagnitude > 0.0f && !Direction.IsNearlyZero() && CheckKnockback())
		{
			FRotator Rotation = Direction.Rotation();
			Rotation.Pitch = UpwardAngle;
			KnockbackForce = Rotation.Vector() * KnockbackMagnitude;
		}
	}
	
	/** 验证参数是否有效 */
	bool IsValid() const
	{
		return DamageGameplayEffectClass != nullptr && 
			   SourceAbilitySystemComponent != nullptr && 
			   TargetAbilitySystemComponent != nullptr;
	}
	
	/** 创建参数的副本 */
	FDamageEffectParams GetCopy() const
	{
		return *this;
	}
};