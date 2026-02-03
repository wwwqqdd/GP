// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Playerproperty.generated.h"

class UProgressBar;
/**
 * 
 */

UCLASS()
class GAMEPLAYPROJECT_API UPlayerproperty : public UUserWidget
{
	GENERATED_BODY()
	virtual void NativeConstruct() override;
	
private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UProgressBar> HealthBar;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UProgressBar> StaminaBar;
 
public:
	
	UFUNCTION(BlueprintCallable,DisplayName="SetHealthBar")
	void SetHealthBarPercent(float CurrentHealth,float MaxHealth);
	
	UFUNCTION(BlueprintCallable,DisplayName="SetStaminaBar")
	void SetStaminaBarPercent(float CurrentHealth,float MaxHealth);
	
public:
	UProgressBar* GetHealthBar() const { return HealthBar; }
	UProgressBar* GetStaminaBar() const { return StaminaBar; }
};
