// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ALSMantleComponent.h"


const FName NAME_MantleEnd(TEXT("MantleEnd"));
const FName NAME_MantleUpdate(TEXT("MantleUpdate"));
const FName NAME_MantleTimeline(TEXT("MantleTimeline"));


UALSMantleComponent::UALSMantleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	
	
}

bool UALSMantleComponent::MantleCheck(const FALSMantleTraceSettings& TraceSettings, EDrawDebugTrace::Type DebugType)
{
	
}

bool UALSMantleComponent::MantleStart(float MantleHeight, const FALSComponentAndTransform& MantleLedgeWS,
	EALSMantleType MantleType)
{
	
}


// Called when the game starts
void UALSMantleComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
}


// Called every frame
void UALSMantleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

