// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_SetFocusToPlayer.h"

#include "AIController.h"
#include "Kismet/GameplayStatics.h"


UBTTask_SetFocusToPlayer::UBTTask_SetFocusToPlayer()
{
	NodeName = TEXT("SetFocusToPlayer");
}

EBTNodeResult::Type UBTTask_SetFocusToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Pawn)
	{
		OwnerComp.GetAIOwner()->SetFocus(Pawn);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

FString UBTTask_SetFocusToPlayer::GetStaticDescription() const
{
	return "Set Focus to player's pawn";
}
