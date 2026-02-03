// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayProjectAttributeSet.h"
#include "GameplayProjectCharacter.h"
#include "Net/UnrealNetwork.h"

UGameplayProjectAttributeSet::UGameplayProjectAttributeSet()
{
	MaxHealth = 100.0f;
	CurrentHealth = 100.0f;
	MaxStamina = 100.0f;
	CurrentStamina = 100.0f;
	AttackPower = 10.0f;
	MaxTotalBulletNum = 200.0f;
	TotalBulletNum = 200.0f;
	BulletNum = 20.0f;
}

AGameplayProjectCharacter* UGameplayProjectAttributeSet::GetGameplayProjectCharacter() const
{
	return Cast<AGameplayProjectCharacter>(GetOuter());
}

void UGameplayProjectAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, CurrentStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, MaxTotalBulletNum, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, TotalBulletNum, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameplayProjectAttributeSet, BulletNum, COND_None, REPNOTIFY_Always);
}

void UGameplayProjectAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.1f);
	}
	if (Attribute == GetCurrentHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetMaxStaminaAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.1f);
	} 
	if (Attribute == GetCurrentStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxStamina());
	}
	if (Attribute == GetAttackPowerAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.0f);
	}
}

void UGameplayProjectAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
}

void UGameplayProjectAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	
	if (Attribute == GetMaxHealthAttribute())
	{
		if (GetCurrentHealth() > NewValue)
		{
			SetCurrentHealth(NewValue);
			OnHealthChangedDelegate.ExecuteIfBound(GetCurrentHealth(),GetMaxHealth());
		}
	}
	if (Attribute == GetCurrentHealthAttribute())
	{
		OnHealthChangedDelegate.ExecuteIfBound(GetCurrentHealth(),GetMaxHealth());
		if (GetCurrentHealth() <= 0.0f)
		{
			AGameplayProjectCharacter* Character = GetGameplayProjectCharacter();
			const FVector PlayerLocation = Character->GetActorLocation();
			Character->Die(PlayerLocation);
		}
	}
	if (Attribute == GetMaxStaminaAttribute())
	{
		OnStaminaChangedDelegate.ExecuteIfBound(GetCurrentStamina(),GetMaxStamina());
		if (GetCurrentStamina() > NewValue)
		{
			SetCurrentStamina(NewValue);
		}
	}
	if (Attribute == GetCurrentStaminaAttribute())
	{
		OnStaminaChangedDelegate.ExecuteIfBound(GetCurrentStamina(),GetMaxStamina());
		if (GetCurrentStamina() < 0.0f)
		{
			SetCurrentStamina(0.0f);
		}
	}
}
