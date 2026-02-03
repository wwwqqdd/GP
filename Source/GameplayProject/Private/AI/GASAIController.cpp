// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GASAIController.h"

AGASAIController::AGASAIController()
{
	
}

void AGASAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (Behaviour && InPawn)
	{
		RunBehaviorTree(Behaviour);
	}
}

FVector AGASAIController::GetFocalPointOnActor(const AActor* Actor) const
{
	if (Actor == nullptr)
	{
		return FAISystem::InvalidLocation;
	}
	if (Cast<APawn>(Actor))
	{
		// Focus on pawn's eye view point
		return Cast<APawn>(Actor)->GetPawnViewLocation();
	}
	return Actor->GetActorLocation();
	
}
