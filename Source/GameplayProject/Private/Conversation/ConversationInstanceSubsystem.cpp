// Fill out your copyright notice in the Description page of Project Settings.

#include "Conversation/ConversationInstanceSubsystem.h"

#include "Conversation/ConversationSettings.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "GameplayProject.h"

namespace ConversationSubsystemPrivate
{
	UAbilitySystemComponent* GetAbilitySystemComponentForActor(AActor* Actor)
	{
		return Actor != nullptr ? UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor) : nullptr;
	}

	bool HasRequiredTags(AActor* TargetActor, const FGameplayTagContainer& RequiredTags)
	{
		if (RequiredTags.IsEmpty())
		{
			return true;
		}

		UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponentForActor(TargetActor);
		if (AbilitySystemComponent == nullptr)
		{
			return false;
		}

		return AbilitySystemComponent->HasAllMatchingGameplayTags(RequiredTags);
	}

	void ApplyTagChanges(AActor* TargetActor, const FGameplayTagContainer& TagsToAdd, const FGameplayTagContainer& TagsToRemove)
	{
		UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponentForActor(TargetActor);
		if (AbilitySystemComponent == nullptr)
		{
			return;
		}

		for (const FGameplayTag& Tag : TagsToAdd)
		{
			AbilitySystemComponent->AddLooseGameplayTag(Tag);
		}

		for (const FGameplayTag& Tag : TagsToRemove)
		{
			AbilitySystemComponent->RemoveLooseGameplayTag(Tag);
		}
	}
}

void UConversationInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadDialogueTrees();
}

void UConversationInstanceSubsystem::Deinitialize()
{
	ActiveConversations.Empty();
	CachedDialogueTrees.Empty();
	ConversationDataTableAsset = nullptr;
	ConversationTreeDataTableAsset = nullptr;
	Super::Deinitialize();
}

bool UConversationInstanceSubsystem::StartDialogue(UObject* WorldContextObject, const FString& DialogueTreeID,
	AActor* TargetActor, const FName& StartNodeID)
{
	if (DialogueTreeID.IsEmpty())
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("StartDialogue failed: DialogueTreeID is empty."));
		return false;
	}

	const FString SessionKey = BuildConversationSessionKey(DialogueTreeID, TargetActor);
	if (ActiveConversations.Contains(SessionKey))
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("StartDialogue failed: dialogue '%s' is already active for target '%s'."),
			*DialogueTreeID, *GetPathNameSafe(TargetActor));
		return false;
	}

	const FConversationTreeDefinition* TreeDefinition = FindDialogueTree(DialogueTreeID);
	if (TreeDefinition == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("StartDialogue failed: could not find dialogue tree '%s'."), *DialogueTreeID);
		return false;
	}

	if (!ConversationSubsystemPrivate::HasRequiredTags(TargetActor, TreeDefinition->ExecuteConditionTags))
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("StartDialogue failed: target '%s' does not satisfy execute condition tags for dialogue '%s'."),
			*GetPathNameSafe(TargetActor), *DialogueTreeID);
		return false;
	}

	FName ResolvedStartNodeID = StartNodeID;
	if (ResolvedStartNodeID.IsNone() && !TreeDefinition->NodeReferences.IsEmpty())
	{
		// 从第一个节点引用获取NodeID
		if (TreeDefinition->NodeReferences[0].DataTable != nullptr)
		{
			UDataTable* SourceTable = const_cast<UDataTable*>(TreeDefinition->NodeReferences[0].DataTable.Get());
			if (const FConversationNodeData* FirstNode = SourceTable->FindRow<FConversationNodeData>(
				TreeDefinition->NodeReferences[0].RowName, TEXT("StartDialogue")))
			{
				ResolvedStartNodeID = FirstNode->NodeID;
			}
		}
	}

	const FConversationNodeData* StartNode = FindNodeData(TreeDefinition, ResolvedStartNodeID);
	if (StartNode == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("StartDialogue failed: could not find start node '%s' for dialogue '%s'."),
			*ResolvedStartNodeID.ToString(), *DialogueTreeID);
		return false;
	}

	if (WorldContextObject != nullptr)
	{
		WorldContext = WorldContextObject->GetWorld();
	}

	FConversationRuntimeState RuntimeState;
	RuntimeState.DialogueTreeID = DialogueTreeID;
	RuntimeState.TargetActor = TargetActor;
	RuntimeState.CurrentNodeID = StartNode->NodeID;
	RuntimeState.CurrentNodeData = *StartNode;

	ActiveConversations.Add(SessionKey, RuntimeState);
	ConversationSubsystemPrivate::ApplyTagChanges(TargetActor, TreeDefinition->TagsToAddOnStart, TreeDefinition->TagsToRemoveOnStart);
	OnDialogueStarted.Broadcast(DialogueTreeID, TargetActor, RuntimeState.CurrentNodeID);
	UE_LOG(LogGameplayProject, Log, TEXT("Dialogue '%s' started for target '%s' at node '%s'."),
		*DialogueTreeID, *GetPathNameSafe(TargetActor), *RuntimeState.CurrentNodeID.ToString());
	return true;
}

bool UConversationInstanceSubsystem::EndDialogue(UObject* WorldContextObject, const FString& DialogueTreeID,
	AActor* TargetActor, const FName& EndNodeID)
{
	if (DialogueTreeID.IsEmpty())
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("EndDialogue failed: DialogueTreeID is empty."));
		return false;
	}

	if (WorldContextObject != nullptr)
	{
		WorldContext = WorldContextObject->GetWorld();
	}

	const FString SessionKey = BuildConversationSessionKey(DialogueTreeID, TargetActor);
	const FConversationRuntimeState* RuntimeState = ActiveConversations.Find(SessionKey);
	if (RuntimeState == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("EndDialogue failed: dialogue '%s' is not active for target '%s'."),
			*DialogueTreeID, *GetPathNameSafe(TargetActor));
		return false;
	}

	const FConversationTreeDefinition* TreeDefinition = FindDialogueTree(DialogueTreeID);
	if (TreeDefinition == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("EndDialogue failed: could not find dialogue tree '%s' while ending active session."), *DialogueTreeID);
		return false;
	}

	const FName ResolvedEndNodeID = !EndNodeID.IsNone() ? EndNodeID : RuntimeState->CurrentNodeID;
	ConversationSubsystemPrivate::ApplyTagChanges(TargetActor, TreeDefinition->TagsToAddOnEnd, TreeDefinition->TagsToRemoveOnEnd);
	ActiveConversations.Remove(SessionKey);
	OnDialogueEnded.Broadcast(DialogueTreeID, TargetActor, ResolvedEndNodeID);
	UE_LOG(LogGameplayProject, Log, TEXT("Dialogue '%s' ended for target '%s' at node '%s'."),
		*DialogueTreeID, *GetPathNameSafe(TargetActor), *ResolvedEndNodeID.ToString());
	return true;
}

bool UConversationInstanceSubsystem::SelectBranchOption(const FString& DialogueTreeID, AActor* TargetActor,
	const FString& SelectedOption)
{
	if (DialogueTreeID.IsEmpty())
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("SelectBranchOption failed: DialogueTreeID is empty."));
		return false;
	}

	const FString SessionKey = BuildConversationSessionKey(DialogueTreeID, TargetActor);
	const FConversationRuntimeState* RuntimeState = ActiveConversations.Find(SessionKey);
	if (RuntimeState == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("SelectBranchOption failed: dialogue '%s' is not active for target '%s'."),
			*DialogueTreeID, *GetPathNameSafe(TargetActor));
		return false;
	}

	const FConversationTreeDefinition* TreeDefinition = FindDialogueTree(DialogueTreeID);
	if (TreeDefinition == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("SelectBranchOption failed: could not find dialogue tree '%s'."),
			*DialogueTreeID);
		return false;
	}

	const FConversationBranchOption* SelectedBranch = nullptr;
	for (const FConversationBranchOption& BranchOption : RuntimeState->CurrentNodeData.BranchOptions)
	{
		if (BranchOption.Option != SelectedOption)
		{
			continue;
		}

		if (!ConversationSubsystemPrivate::HasRequiredTags(TargetActor, BranchOption.EnableConditionTags))
		{
			UE_LOG(LogGameplayProject, Warning,
				TEXT("SelectBranchOption failed: option '%s' does not satisfy tag requirements for dialogue '%s'."),
				*SelectedOption, *DialogueTreeID);
			return false;
		}

		SelectedBranch = &BranchOption;
		break;
	}

	if (SelectedBranch == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("SelectBranchOption failed: option '%s' was not found on current node '%s' for dialogue '%s'."),
			*SelectedOption, *RuntimeState->CurrentNodeID.ToString(), *DialogueTreeID);
		return false;
	}

	if (SelectedBranch->TargetNodeRowName.IsNone())
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("SelectBranchOption failed: option '%s' on node '%s' has no target node."),
			*SelectedOption, *RuntimeState->CurrentNodeID.ToString());
		return false;
	}

	OnBranchSelected.Broadcast(DialogueTreeID, TargetActor, SelectedOption);
	UE_LOG(LogGameplayProject, Log,
		TEXT("Dialogue '%s' selected branch '%s' on node '%s'."),
		*DialogueTreeID, *SelectedOption, *RuntimeState->CurrentNodeID.ToString());

	return AdvanceConversationToNode(WorldContext.Get(), DialogueTreeID, TargetActor, SelectedBranch->TargetNodeRowName);
}

bool UConversationInstanceSubsystem::AdvanceDialogue(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor)
{
	if (DialogueTreeID.IsEmpty())
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("AdvanceDialogue failed: DialogueTreeID is empty."));
		return false;
	}

	const FString SessionKey = BuildConversationSessionKey(DialogueTreeID, TargetActor);
	const FConversationRuntimeState* RuntimeState = ActiveConversations.Find(SessionKey);
	if (RuntimeState == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceDialogue failed: dialogue '%s' is not active for target '%s'."),
			*DialogueTreeID, *GetPathNameSafe(TargetActor));
		return false;
	}

	if (RuntimeState->CurrentNodeData.bIsEndNode)
	{
		return EndDialogue(WorldContextObject, DialogueTreeID, TargetActor, RuntimeState->CurrentNodeID);
	}

	if (!RuntimeState->CurrentNodeData.BranchOptions.IsEmpty())
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceDialogue failed: current node '%s' in dialogue '%s' requires branch selection."),
			*RuntimeState->CurrentNodeID.ToString(), *DialogueTreeID);
		return false;
	}

	if (RuntimeState->CurrentNodeData.DefaultNextNodeRowName.IsNone())
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceDialogue failed: current node '%s' in dialogue '%s' has no default next node."),
			*RuntimeState->CurrentNodeID.ToString(), *DialogueTreeID);
		return false;
	}

	return AdvanceConversationToNode(WorldContextObject, DialogueTreeID, TargetActor, RuntimeState->CurrentNodeData.DefaultNextNodeRowName);
}

bool UConversationInstanceSubsystem::GetCurrentNodeData(const FString& DialogueTreeID, AActor* TargetActor,
	FConversationNodeData& OutNodeData) const
{
	const FConversationRuntimeState* RuntimeState = ActiveConversations.Find(BuildConversationSessionKey(DialogueTreeID, TargetActor));
	if (RuntimeState == nullptr)
	{
		return false;
	}

	OutNodeData = RuntimeState->CurrentNodeData;
	return true;
}

bool UConversationInstanceSubsystem::IsDialogueActive(const FString& DialogueTreeID, AActor* TargetActor) const
{
	return ActiveConversations.Contains(BuildConversationSessionKey(DialogueTreeID, TargetActor));
}

TArray<FConversationBranchOption> UConversationInstanceSubsystem::GetAvailableBranchOptions(const FString& DialogueTreeID, AActor* TargetActor) const
{
	TArray<FConversationBranchOption> AvailableOptions;
	
	if (DialogueTreeID.IsEmpty() || TargetActor == nullptr)
	{
		return AvailableOptions;
	}

	const FString SessionKey = BuildConversationSessionKey(DialogueTreeID, TargetActor);
	const FConversationRuntimeState* RuntimeState = ActiveConversations.Find(SessionKey);
	if (RuntimeState == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning, TEXT("GetAvailableBranchOptions failed: dialogue '%s' is not active for target '%s'."),
			*DialogueTreeID, *GetPathNameSafe(TargetActor));
		return AvailableOptions;
	}

	// 如果当前节点没有分支选项，返回空数组
	if (RuntimeState->CurrentNodeData.BranchOptions.IsEmpty())
	{
		return AvailableOptions;
	}

	// 过滤出满足条件的分支选项
	for (const FConversationBranchOption& BranchOption : RuntimeState->CurrentNodeData.BranchOptions)
	{
		// 检查是否满足标签条件
		if (ConversationSubsystemPrivate::HasRequiredTags(TargetActor, BranchOption.EnableConditionTags))
		{
			AvailableOptions.Add(BranchOption);
		}
	}

	return AvailableOptions;
}

void UConversationInstanceSubsystem::LoadDialogueTrees()
{
	CachedDialogueTrees.Empty();

	const UConversationSettings* Settings = GetDefault<UConversationSettings>();
	if (Settings == nullptr)
	{
		return;
	}

	ConversationDataTableAsset = const_cast<UConversationSettings*>(Settings)->GetConversationDataTable();
	ConversationTreeDataTableAsset = const_cast<UConversationSettings*>(Settings)->GetConversationTreeDataTable();
	if (ConversationTreeDataTableAsset == nullptr)
	{
		return;
	}

	for (const FName& RowName : ConversationTreeDataTableAsset->GetRowNames())
	{
		const FConversationTreeDefinition* TreeDefinition = ConversationTreeDataTableAsset->FindRow<FConversationTreeDefinition>(RowName, TEXT("ConversationTreeLoad"));
		if (TreeDefinition == nullptr)
		{
			continue;
		}

		const FString TreeID = TreeDefinition->DialogueTreeID.IsNone() ? RowName.ToString() : TreeDefinition->DialogueTreeID.ToString();
		CachedDialogueTrees.Add(TreeID, *TreeDefinition);
	}
}

const FConversationTreeDefinition* UConversationInstanceSubsystem::FindDialogueTree(const FString& DialogueTreeID) const
{
	return CachedDialogueTrees.Find(DialogueTreeID);
}

const FConversationNodeData* UConversationInstanceSubsystem::FindNodeData(const FConversationTreeDefinition* TreeDef,
	const FName& NodeID) const
{
	if (TreeDef == nullptr || NodeID.IsNone())
	{
		return nullptr;
	}

	for (const FDataTableRowHandle& NodeReference : TreeDef->NodeReferences)
	{
		UDataTable* SourceTable = nullptr;
		if (NodeReference.DataTable != nullptr)
		{
			SourceTable = const_cast<UDataTable*>(NodeReference.DataTable.Get());
		}
		else
		{
			SourceTable = ConversationDataTableAsset;
		}
		
		if (SourceTable == nullptr || NodeReference.RowName.IsNone())
		{
			continue;
		}

		const FConversationNodeData* CandidateNode = SourceTable->FindRow<FConversationNodeData>(NodeReference.RowName, TEXT("ConversationNodeLookup"));
		if (CandidateNode != nullptr && CandidateNode->NodeID == NodeID)
		{
			return CandidateNode;
		}
	}

	if (ConversationDataTableAsset != nullptr)
	{
		// 直接通过行名查找
		if (const FConversationNodeData* DirectNode = ConversationDataTableAsset->FindRow<FConversationNodeData>(NodeID, TEXT("ConversationNodeLookup")))
		{
			return DirectNode;
		}
	}

	return nullptr;
}

FString UConversationInstanceSubsystem::BuildConversationSessionKey(const FString& DialogueTreeID, const AActor* TargetActor) const
{
	return FString::Printf(TEXT("%s::%s"), *DialogueTreeID, *GetPathNameSafe(TargetActor));
}

bool UConversationInstanceSubsystem::AdvanceConversationToNode(UObject* WorldContextObject, const FString& DialogueTreeID,
	AActor* TargetActor, const FName& NextNodeID)
{
	if (NextNodeID.IsNone())
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceConversationToNode failed: next node ID is invalid for dialogue '%s'."),
			*DialogueTreeID);
		return false;
	}

	const FString SessionKey = BuildConversationSessionKey(DialogueTreeID, TargetActor);
	FConversationRuntimeState* RuntimeState = ActiveConversations.Find(SessionKey);
	if (RuntimeState == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceConversationToNode failed: dialogue '%s' is not active for target '%s'."),
			*DialogueTreeID, *GetPathNameSafe(TargetActor));
		return false;
	}

	const FConversationTreeDefinition* TreeDefinition = FindDialogueTree(DialogueTreeID);
	if (TreeDefinition == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceConversationToNode failed: could not find dialogue tree '%s'."),
			*DialogueTreeID);
		return false;
	}

	const FConversationNodeData* NextNode = FindNodeData(TreeDefinition, NextNodeID);
	if (NextNode == nullptr)
	{
		UE_LOG(LogGameplayProject, Warning,
			TEXT("AdvanceConversationToNode failed: could not find node '%s' for dialogue '%s'."),
			*NextNodeID.ToString(), *DialogueTreeID);
		return false;
	}

	const FName PreviousNodeID = RuntimeState->CurrentNodeID;
	RuntimeState->CurrentNodeID = NextNode->NodeID;
	RuntimeState->CurrentNodeData = *NextNode;

	OnNodeChanged.Broadcast(DialogueTreeID, TargetActor, PreviousNodeID, RuntimeState->CurrentNodeID);
	UE_LOG(LogGameplayProject, Log,
		TEXT("Dialogue '%s' moved from node '%s' to node '%s'."),
		*DialogueTreeID, *PreviousNodeID.ToString(), *RuntimeState->CurrentNodeID.ToString());

	if (RuntimeState->CurrentNodeData.bIsEndNode)
	{
		return EndDialogue(WorldContextObject, DialogueTreeID, TargetActor, RuntimeState->CurrentNodeID);
	}

	return true;
}
