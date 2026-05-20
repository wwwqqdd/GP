// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GameplayProjectCharacter.h"
#include "GameplayProjectAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAttributeChangedDelegate,float,CurrentValue,float,MaxValue);
UCLASS()
class GAMEPLAYPROJECT_API UGameplayProjectAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UGameplayProjectAttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FOnAttributeChangedDelegate OnHealthChangedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FOnAttributeChangedDelegate OnStaminaChangedDelegate;

	AGameplayProjectCharacter* GetGameplayProjectCharacter() const;
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_CurrentHealth, Category = "Attributes")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_MaxStamina, Category = "Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, MaxStamina)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_CurrentStamina, Category = "Attributes")
	FGameplayAttributeData CurrentStamina;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, CurrentStamina)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_AttackPower, Category = "Attributes")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, AttackPower)

	/* Gun */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_MaxTotalBulletNum, Category = "Attributes")
	FGameplayAttributeData MaxTotalBulletNum;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, MaxTotalBulletNum)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_TotalBulletNum, Category = "Attributes")
	FGameplayAttributeData TotalBulletNum;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, TotalBulletNum)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_BulletNum, Category = "Attributes")
	FGameplayAttributeData BulletNum;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, BulletNum)

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth) const;
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	UFUNCTION()
	void OnRep_CurrentStamina(const FGameplayAttributeData& OldCurrentStamina) const;
	UFUNCTION()
	void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower) const;
	UFUNCTION()
	void OnRep_MaxTotalBulletNum(const FGameplayAttributeData& OldMaxTotalBulletNum) const;
	UFUNCTION()
	void OnRep_TotalBulletNum(const FGameplayAttributeData& OldTotalBulletNum) const;
	UFUNCTION()
	void OnRep_BulletNum(const FGameplayAttributeData& OldBulletNum) const;
};
