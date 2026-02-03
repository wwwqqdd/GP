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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, MaxHealth)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, CurrentHealth)
 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, MaxStamina)
 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData CurrentStamina;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, CurrentStamina)
 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, AttackPower)

	/* Gun */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData MaxTotalBulletNum;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, MaxTotalBulletNum)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData TotalBulletNum;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, TotalBulletNum)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	FGameplayAttributeData BulletNum;
	ATTRIBUTE_ACCESSORS(UGameplayProjectAttributeSet, BulletNum) 
};
