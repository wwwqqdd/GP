// Fill out your copyright notice in the Description page of Project Settings.


#include "Conversation/ConversationInstanceSubsystem.h"

#include "Conversation/ConversationSettings.h"


void UConversationInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadDialogueTrees();
}

void UConversationInstanceSubsystem::Deinitialize()
{
	ActiveConversations.Empty();
	CachedDialogueTrees.Empty();
	Super::Deinitialize();
}

bool UConversationInstanceSubsystem::StartDialogue(UObject* WorldContextObject, const FString& DialogueTreeID,
                                                   AActor* TargetActor, const FString& StartNodeID)
{
	return true;
}

bool UConversationInstanceSubsystem::EndDialogue(UObject* WorldContextObject, const FString& DialogueTreeID,
	                                             AActor* TargetActor, const FString& EndNodeID)
{
	return true;
}

bool UConversationInstanceSubsystem::SelectBranchOption(const FString& DialogueTreeID, AActor* TargetActor,
	const FString& SelectedOption)
{
	return true;
}

bool UConversationInstanceSubsystem::GetCurrentNodeData(const FString& DialogueTreeID, AActor* TargetActor,
	FConversationNodeData& OutNodeData) const
{
	return true;
}

TArray<FConversationBranchOption> UConversationInstanceSubsystem::GetAvailableBranchOptions(
	const FString& DialogueTreeID, AActor* TargetActor) const
{
	
}

bool UConversationInstanceSubsystem::IsDialogueActive(const FString& DialogueTreeID, AActor* TargetActor) const
{
	return true;
}

void UConversationInstanceSubsystem::LoadDialogueTrees()
{
	
;
}

const FConversationTreeDefinition* UConversationInstanceSubsystem::FindDialogueTree(const FString& DialogueTreeID) const
{
}

const FConversationNodeData* UConversationInstanceSubsystem::FindNodeData(const FConversationTreeDefinition* TreeDef,
                                                                          const FString& NodeID) const
{
	
}
