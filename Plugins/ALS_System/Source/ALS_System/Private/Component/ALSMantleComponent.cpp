// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ALSMantleComponent.h"

#include "ALSBaseCharacter.h"


const FName NAME_MantleEnd(TEXT("MantleEnd"));
const FName NAME_MantleUpdate(TEXT("MantleUpdate"));
const FName NAME_MantleTimeline(TEXT("MantleTimeline"));

FName UALSMantleComponent::NAME_IgnoreOnlyPawn(TEXT("IgnoreOnlyPawn"));

UALSMantleComponent::UALSMantleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	MantleTimeline = CreateDefaultSubobject<UTimelineComponent>(NAME_MantleTimeline);
	
}

bool UALSMantleComponent::MantleCheck(const FALSMantleTraceSettings& TraceSettings, EDrawDebugTrace::Type DebugType)
{
	return true;
}

void UALSMantleComponent::MantleStart(float MantleHeight, const FALSComponentAndTransform& MantleLedgeWS,
	EALSMantleType MantleType)
{
	if (OwnerCharacter == nullptr || !IsValid(MantleLedgeWS.Component) || !IsValid(MantleTimeline)) return;

	/*if (MantleType != EALSMantleType::LowMantle && OwnerCharacter->IsA(AALSCharacter::StaticClass()))
	{
		
	}*/
}

void UALSMantleComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetOwner())
	{
		OwnerCharacter = Cast<AALSBaseCharacter>(GetOwner());
		if (OwnerCharacter)
		{
			ALSDebugComponent = OwnerCharacter->FindComponentByClass<UALSDebugComponent>();

			AddTickPrerequisiteActor(OwnerCharacter);
			
			FOnTimelineFloat TimelineUpdated;
			FOnTimelineEvent TimelineFinished;
			TimelineUpdated.BindUFunction(this, NAME_MantleUpdate);
			TimelineFinished.BindUFunction(this, NAME_MantleEnd);
			MantleTimeline->SetTimelineFinishedFunc(TimelineFinished);
			MantleTimeline->SetLooping(false);
			MantleTimeline->SetTimelineLengthMode(TL_TimelineLength);
			MantleTimeline->AddInterpFloat(MantleTimelineCurve, TimelineUpdated);

			//OwnerCharacter->JumpPressedDelegate.AddUniqueDynamic(this, &UALSMantleComponent::OnOner)
		}
	}
}

void UALSMantleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (OwnerCharacter && OwnerCharacter->GetMovementState() == EALSMovementState::InAir)
	{
		if (OwnerCharacter->HasMovementInput())
		{
			MantleCheck(FallingTraceSettings, EDrawDebugTrace::Type::ForOneFrame);
		}
	}
}

