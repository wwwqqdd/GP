// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/Playerproperty.h"

#include "AbilitySystemInterface.h"
#include "GameplayProjectAttributeSet.h"
#include "Components/ProgressBar.h"

void UPlayerproperty::NativeConstruct()
{
	Super::NativeConstruct();
	
	AActor* OwnerActor = Cast<AActor>(GetOwningPlayerPawn());
	if (!OwnerActor) return;
	
	
	IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OwnerActor);
	if (!AbilitySystemInterface) return;
	
	UAbilitySystemComponent* AbilitySystemComponent = AbilitySystemInterface->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;
	
	UGameplayProjectAttributeSet* AttributeSet = const_cast<UGameplayProjectAttributeSet*>(AbilitySystemComponent->GetSet<UGameplayProjectAttributeSet>());
	if (!AttributeSet) return;
	
	SetHealthBarPercent(AttributeSet->GetCurrentHealth(), AttributeSet->GetMaxHealth());
	SetStaminaBarPercent(AttributeSet->GetCurrentStamina(), AttributeSet->GetMaxStamina());
	
 
	// 绑定属性变化委托：血量与体力变化时回调本 Widget 的更新函数
	AttributeSet->OnHealthChangedDelegate.BindUFunction(this, FName("SetHealthBarPercent"));
	AttributeSet->OnStaminaChangedDelegate.BindUFunction(this, FName("SetStaminaBarPercent"));
}

void UPlayerproperty::SetHealthBarPercent(float CurrentHealth, float MaxHealth)
{
	if (!HealthBar) return;
		
	HealthBar->SetPercent(CurrentHealth / MaxHealth);
}

void UPlayerproperty::SetStaminaBarPercent(float CurrentHealth, float MaxHealth)
{
	if (!StaminaBar) return;
	
	StaminaBar->SetPercent(CurrentHealth / MaxHealth);
}
