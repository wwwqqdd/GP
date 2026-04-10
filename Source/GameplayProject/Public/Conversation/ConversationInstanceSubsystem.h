// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConversationDefinition.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ConversationInstanceSubsystem.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDialogueStarted, const FString&, DialogueTreeID, AActor*, TargetActor, const FString&, StartNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDialogueEnded, const FString&, DialogueTreeID, AActor*, TargetActor, const FString&, EndNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnNodeChanged, const FString&, DialogueTreeID, AActor*, TargetActor, const FString&, OldNodeID, const FString&, NewNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnBranchSelected, const FString&, DialogueTreeID, AActor*, TargetActor, const FString&, SelectedOption);
/**
 * 
 */
UCLASS()
class GAMEPLAYPROJECT_API UConversationInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool StartDialogue(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor, const FString& StartNodeID);

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool EndDialogue(UObject* WorldContextObject, const FString& DialogueTreeID, AActor* TargetActor, const FString& EndNodeID);

	UFUNCTION(BlueprintCallable, Category = "Conversation|LifeCycle")
	bool SelectBranchOption(const FString& DialogueTreeID, AActor* TargetActor, const FString& SelectedOption);

	UFUNCTION(BlueprintCallable, Category = "Conversation|Query")
	bool GetCurrentNodeData(const FString& DialogueTreeID, AActor* TargetActor, FConversationNodeData& OutNodeData) const;
	/**
	 * 获取当前对话可用的分支选项（过滤条件后的）
	 */
	//UFUNCTION(BlueprintCallable, Category = "Conversation|Query")
	//TArray<FConversationBranchOption> GetAvailableBranchOptions(const FString& DialogueTreeID, AActor* TargetActor) const;

	UFUNCTION(BlueprintCallable, Category = "Conversation|Query")
	bool IsDialogueActive(const FString& DialogueTreeID, AActor* TargetActor) const;

	// 委托
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
	
	//const FConversationTreeDefinition* FindDialogueTree(const FString& DialogueTreeID) const;
	
	//const FConversationNodeData* FindNodeData(const FConversationTreeDefinition* TreeDef, const FString& NodeID) const;

	UPROPERTY()
	TMap<FString, FConversationNodeData> ActiveConversations;

	/** 缓存的对话树数据（从数据表加载） */
	TMap<FString, const FConversationTreeDefinition*> CachedDialogueTrees;
	// 世界上下文
	TWeakObjectPtr<UWorld> WorldContext;
};
