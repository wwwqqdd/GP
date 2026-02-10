// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ALSCharacterStructLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ALSMathLibrary.generated.h"

class UCapsuleComponent;
/**
 * 
 */
UCLASS()
class ALS_SYSTEM_API UALSMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//UFUNCTION(BlueprintCallable, Category = "ALS|Math Utils")
	//static FTransform MantleComponentLocation(const FALSComponentAndTransform& CompAndTransform);

	UFUNCTION(BlueprintPure, Category = "ALS|Math Utils")
	static FTransform TransformSub(const FTransform& T1, const FTransform& T2)
	{
		return FTransform(T1.GetRotation().Rotator() - T2.GetRotation().Rotator(),
			              T1.GetLocation() - T2.GetLocation(), T1.GetScale3D() - T2.GetScale3D());
	}

	UFUNCTION(BlueprintCallable, Category = "ALS|Math Utils")
	static FTransform TransformAdd(const FTransform& T1, const FTransform& T2)
	{
		return FTransform(T1.GetRotation().Rotator() + T2.GetRotation().Rotator(),
						  T1.GetLocation() + T2.GetLocation(), T1.GetScale3D() + T2.GetScale3D());
	}

	/*UFUNCTION(BlueprintCallable, Category = "ALS|Math Utils")
	static FVector GetCapsuleBaseLocation(float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable, Category = "ALS|Math Utils")
	static FVector GetCapsuleLocationFromBase(FVector BaseLocation, float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable)*/
};
