// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ALSMantleComponent.h"

#include "ALSBaseCharacter.h"
#include "ALSCharacter.h"
#include "Curves/CurveVector.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Library/ALSMathLibrary.h"


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

void UALSMantleComponent::MantleStart(float MantleHeight, const FALSComponentAndTransform& MantleLedgeWS,
	EALSMantleType MantleType)
{
	if (OwnerCharacter == nullptr || !IsValid(MantleLedgeWS.Component) || !IsValid(MantleTimeline)) return;

	if (MantleType != EALSMantleType::LowMantle && OwnerCharacter->IsA(AALSCharacter::StaticClass()))
	{
		Cast<AALSCharacter>(OwnerCharacter)->ClearHeldObject();
	}

	SetComponentTickEnabledAsync(false);

	const FALSMantleAsset MantleAsset = GetMantleAsset(MantleType, OwnerCharacter->GetOverlayState());
	check(MantleAsset.PositionCorrectionCurve)

	MantleParams.AnimMontage = MantleAsset.AnimMontage;
	MantleParams.PositionCorrectionCurve = MantleAsset.PositionCorrectionCurve;
	MantleParams.StartingOffset = MantleAsset.StartingOffset;
	MantleParams.StartingPosition = FMath::GetMappedRangeValueClamped<float, float>({MantleAsset.LowHeight, MantleAsset.HighHeight},
														{
																		MantleAsset.LowStartPosition,
																		MantleAsset.HighStartPosition
														              },MantleHeight);
	MantleParams.PlayRate = FMath::GetMappedRangeValueClamped<float, float>({MantleAsset.LowHeight, MantleAsset.HighHeight},
		                                       {MantleAsset.LowPlayRate, MantleAsset.HighPlayRate},
		                                                     MantleHeight);

	MantleLedgeLS.Component = MantleLedgeWS.Component;
	MantleLedgeLS.Transform = MantleLedgeWS.Transform * MantleLedgeWS.Component->GetComponentToWorld().Inverse();

	MantleTarget = MantleLedgeWS.Transform;
	MantleActualStartOffset = UALSMathLibrary::TransformSub(OwnerCharacter->GetActorTransform(), MantleTarget);

	FVector RotatedVector = MantleTarget.GetRotation().Vector() * MantleParams.StartingOffset.Y;
	RotatedVector.Z = MantleParams.StartingOffset.Z;
	const FTransform StartOffset(MantleTarget.Rotator(), MantleTarget.GetLocation() - RotatedVector, FVector::OneVector);
	MantleAnimatedStartOffset = UALSMathLibrary::TransformSub(StartOffset, MantleTarget);

	OwnerCharacter->GetCharacterMovement()->SetMovementMode(MOVE_None);
	OwnerCharacter->SetMovementState(EALSMovementState::Mantling);

	float MinTime = 0.0f;
	float MaxTime = 0.0f;
	MantleParams.PositionCorrectionCurve->GetTimeRange(MinTime, MaxTime);
	MantleTimeline->SetTimelineLength(MaxTime - MantleParams.StartingPosition);
	MantleTimeline->SetPlayRate(MantleParams.PlayRate);
	MantleTimeline->PlayFromStart();

	OwnerCharacter->GetMesh()->GetAnimInstance()->Montage_Play(MantleParams.AnimMontage, MantleParams.PlayRate, EMontagePlayReturnType::MontageLength,MantleParams.StartingPosition,false);
}

bool UALSMantleComponent::MantleCheck(const FALSMantleTraceSettings& TraceSettings, EDrawDebugTrace::Type DebugType)
{
	if (!OwnerCharacter) return false;

	const FVector& TraceDirection = OwnerCharacter->GetActorForwardVector();
	const FVector& CapsuleBaseLocation = UALSMathLibrary::GetCapsuleBaseLocation(2.0f, OwnerCharacter->GetCapsuleComponent());
	FVector TraceStart = CapsuleBaseLocation + TraceDirection * -30.0f;
	TraceStart.Z += (TraceSettings.MaxLedgeHeight + TraceSettings.MinLedgeHeight) / 2.0f;
	const FVector TraceEnd = TraceStart + TraceDirection * TraceSettings.ReachDistance;
	const float HalfHeight = 1.0f + (TraceSettings.MaxLedgeHeight - TraceSettings.MinLedgeHeight) / 2.0f;

	UWorld* World = GetWorld();
	check(World);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerCharacter);

	FHitResult HitResult;
	{
		const FCollisionShape CapsuleCollisionShape = FCollisionShape::MakeCapsule(TraceSettings.ForwardTraceRadius, HalfHeight);
		const bool bHit = World->SweepSingleByProfile(HitResult, TraceStart, TraceEnd, FQuat::Identity, MantleObjectDetectionProfile, CapsuleCollisionShape, Params);
		
		if (ALSDebugComponent && ALSDebugComponent->GetShowTraces())
		{
			UALSDebugComponent::DrawDebugCapsuleTraceSingle(World, TraceStart, TraceEnd, CapsuleCollisionShape, DebugType, bHit, HitResult, FLinearColor::Black, FLinearColor::Black, 1.0f);
		}
	}

	if (!HitResult.IsValidBlockingHit() ||OwnerCharacter->GetCharacterMovement()->IsWalkable(HitResult))
	{
		return false;
	}

	if (HitResult.GetComponent() != nullptr)
	{
		UPrimitiveComponent* PrimitiveComponent = HitResult.GetComponent();
		if (PrimitiveComponent && PrimitiveComponent->GetComponentVelocity().Size() > AcceptableVelocityWhileMantling)
		{
			return false;
		}
	}

	const FVector InitialTraceImpactPoint = HitResult.ImpactPoint;
	const FVector InitialTraceNormal = HitResult.ImpactNormal;

	FVector DownwardTraceEnd = InitialTraceImpactPoint;
	DownwardTraceEnd.Z = CapsuleBaseLocation.Z;
	DownwardTraceEnd += InitialTraceNormal * -15.0f;
	FVector DownwardTraceStart = DownwardTraceEnd;
	DownwardTraceStart.Z += TraceSettings.MaxLedgeHeight + TraceSettings.DownwardTraceRadius + 1.0f;
	
	{
		const FCollisionShape SphereCollisionShape = FCollisionShape::MakeSphere(TraceSettings.DownwardTraceRadius);
		const bool bHit = World->SweepSingleByChannel(HitResult, DownwardTraceStart, DownwardTraceEnd, FQuat::Identity, WalkableSurfaceDetectionChannel, SphereCollisionShape, Params);

		if (ALSDebugComponent && ALSDebugComponent->GetShowTraces())
		{
			UALSDebugComponent::DrawDebugCapsuleTraceSingle(World, TraceStart, TraceEnd, SphereCollisionShape, DebugType, bHit, HitResult, FLinearColor::Black, FLinearColor::Black, 1.0f);
		}
	}

	if (!OwnerCharacter->GetCharacterMovement()->IsWalkable(HitResult))
	{
		return false;
	}

	const FVector DownTraceLocation(HitResult.Location.X, HitResult.Location.Y, HitResult.ImpactPoint.Z);
	UPrimitiveComponent* HitComponent = HitResult.GetComponent();

	const FVector& CapsuleLocationFBase = UALSMathLibrary::GetCapsuleLocationFromBase(DownTraceLocation, 2.0f, OwnerCharacter->GetCapsuleComponent());
	const bool bCapsuleHasRoom = UALSMathLibrary::CapsuleHasRoomCheck(OwnerCharacter->GetCapsuleComponent(), CapsuleLocationFBase, 0.0f, 0.0f, DebugType, ALSDebugComponent && ALSDebugComponent->GetShowTraces());

	if (!bCapsuleHasRoom) return false;

	const FTransform TargetTransform((InitialTraceNormal * FVector(-0.1f, -1.0f, 0.0f)).ToOrientationRotator(), CapsuleLocationFBase, FVector::OneVector);
	const float MantleHeight = (CapsuleLocationFBase - OwnerCharacter->GetActorLocation()).Z;
		
	EALSMantleType MantleType;
	if (OwnerCharacter->GetMovementState() == EALSMovementState::InAir)
	{
		MantleType = EALSMantleType::FallingCatch;
	}
	else
	{
		MantleType = MantleHeight > 125.0f ? EALSMantleType::HighMantle : EALSMantleType::LowMantle;
	}

	FALSComponentAndTransform MantleWS;
	MantleWS.Component = HitComponent;
	MantleWS.Transform = TargetTransform;
	MantleStart(MantleHeight, MantleWS, MantleType);
	Server_MantleStart(MantleHeight, MantleWS, MantleType);
	return true;
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

			//OwnerCharacter->JumpPressedDelegate.AddUniqueDynamic(this, &UALSMantleComponent::)
		}
	}
}

void UALSMantleComponent::Multicast_MantleStart_Implementation(float MantleHeight,
	const FALSComponentAndTransform& MantleLedgeWS, EALSMantleType MantleType)
{
	
}

void UALSMantleComponent::Server_MantleStart_Implementation(float MantleHeight,
                                                            const FALSComponentAndTransform& MantleLedgeWS, EALSMantleType MantleType)
{
	
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

