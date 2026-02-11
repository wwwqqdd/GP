// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Components/ActorComponent.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Library/ALSCharacterEnumLibrary.h"
#include "Library/ALSCharacterStructLibrary.h"
#include "ALSMantleComponent.generated.h"


class UALSDebugComponent;
class AALSBaseCharacter;

UCLASS(Blueprintable, BlueprintType)
class ALS_SYSTEM_API UALSMantleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UALSMantleComponent();

	UFUNCTION(BlueprintCallable, Category= "ALS|Mantle System")
	bool MantleCheck(const FALSMantleTraceSettings& TraceSettings, EDrawDebugTrace::Type DebugType);

	UFUNCTION(BlueprintCallable, Category = "ALS|Mantle System")
	void MantleStart(float MantleHeight, const FALSComponentAndTransform& MantleLedgeWS, EALSMantleType MantleType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "ALS|Mantle System")
	FALSMantleAsset GetMantleAsset(EALSMantleType MantleType, EALSOverlayState CurrentOverlayState);

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "ALS|Mantle System")
	void Server_MantleStart(float MantleHeight, const FALSComponentAndTransform& MantleLedgeWS,
							EALSMantleType MantleType);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "ALS|Mantle System")
	void Multicast_MantleStart(float MantleHeight, const FALSComponentAndTransform& MantleLedgeWS,
							   EALSMantleType MantleType);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Mantle System")
	TObjectPtr<UTimelineComponent> MantleTimeline = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Mantle System")
	FALSMantleTraceSettings GroundedTraceSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Mantle System")
	FALSMantleTraceSettings AutomaticTraceSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Mantle System")
	FALSMantleTraceSettings FallingTraceSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Mantle System")
	TObjectPtr<UCurveFloat> MantleTimelineCurve;

	static FName NAME_IgnoreOnlyPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ALS|Mantle System")
	FName MantleObjectDetectionProfile = NAME_IgnoreOnlyPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ALS|Mantle System")
	TEnumAsByte<ECollisionChannel> WalkableSurfaceDetectionChannel = ECC_Visibility;

	UPROPERTY(BlueprintReadOnly, Category = "ALS|Mantle System")
	FALSMantleParams MantleParams;

	UPROPERTY(BlueprintReadOnly, Category = "ALS|Mantle System")
	FALSComponentAndTransform MantleLedgeLS;

	UPROPERTY(BlueprintReadOnly, Category = "ALS|Mantle System")
	FTransform MantleTarget = FTransform::Identity;

	UPROPERTY(BlueprintReadOnly, Category = "ALS|Mantle System")
	FTransform MantleActualStartOffset = FTransform::Identity;

	UPROPERTY(BlueprintReadOnly, Category = "ALS|Mantle System")
	FTransform MantleAnimatedStartOffset = FTransform::Identity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ALS|Mantle System")
	float AcceptableVelocityWhileMantling = 10.0f;
private:
	UPROPERTY()
	TObjectPtr<AALSBaseCharacter> OwnerCharacter;

	UPROPERTY()
	TObjectPtr<UALSDebugComponent> ALSDebugComponent = nullptr;
		
};
