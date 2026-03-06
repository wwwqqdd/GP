// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ConversationDefinition.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationNodeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	FString NodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	FString SpeakerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	FText DialogueText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	float DisplayDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	USoundBase* VoiceSound = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	TArray<FString> NextNodeIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	FGameplayTagContainer TriggerConditions;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	//FBlueprintDelegate OnExecuteActions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation Node")
	bool IsSkipable = true;
};
