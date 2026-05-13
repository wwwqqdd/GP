// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConversationDefinition.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ConversationInstanceSubsystem.generated.h"

class AActor;
class UDataTable;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDialogueStarted, const FString&, DialogueTreeID, AActor*, TargetActor, const FGuid&, StartNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDialogueEnded, const FString&, DialogueTreeID, AActor*, TargetActor, const FGuid&, EndNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnNodeChanged, const FString&, DialogueTreeID, AActor*, TargetActor, const FGuid&, OldNodeID, const FGuid&, NewNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnBranchSelected, const FString&, DialogueTreeID, AActor*, TargetActor, const FString&, SelectedOption);

USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationRuntimeState
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Conversation|Runtime")
	FString DialogueTreeID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Conversation|Runtime")
	TObjectPtr<AActor> TargetActor = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Conversation|Runtime")
	FGuid CurrentNodeID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Conversation|Runtime")
	FConversationNodeData CurrentNodeData;
};

UCLASS()
class GAMEPLAYPROJECT_API UConversationInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool StartDialogue(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor, const FGuid& StartNodeID);

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool EndDialogue(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor, const FGuid& EndNodeID);

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool SelectBranchOption(const FString& DialogueTreeID, AActor* TargetActor, const FString& SelectedOption);

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool AdvanceDialogue(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category = "Conversation|Query")
	bool GetCurrentNodeData(const FString& DialogueTreeID, AActor* TargetActor, FConversationNodeData& OutNodeData) const;

	UFUNCTION(BlueprintCallable, Category = "Conversation|Query")
	TArray<FConversationBranchOption> GetAvailableBranchOptions(const FString& DialogueTreeID, AActor* TargetActor) const;

	UFUNCTION(BlueprintCallable, Category = "Conversation|Query")
	bool IsDialogueActive(const FString& DialogueTreeID, AActor* TargetActor) const;

	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnDialogueStarted OnDialogueStarted;

	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnDialogueEnded OnDialogueEnded;

	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnNodeChanged OnNodeChanged;

	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnBranchSelected OnBranchSelected;

private:
	void LoadDialogueTrees();

	const FConversationTreeDefinition* FindDialogueTree(const FString& DialogueTreeID) const;
	const FConversationNodeData* FindNodeData(const FConversationTreeDefinition* TreeDef, const FGuid& NodeID) const;
	FString BuildConversationSessionKey(const FString& DialogueTreeID, const AActor* TargetActor) const;
	bool AdvanceConversationToNode(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor, const FGuid& NextNodeID);

	UPROPERTY()
	TMap<FString, FConversationRuntimeState> ActiveConversations;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> ConversationDataTableAsset = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> ConversationTreeDataTableAsset = nullptr;

	TMap<FString, FConversationTreeDefinition> CachedDialogueTrees;
	TWeakObjectPtr<UWorld> WorldContext;
};
