// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ConversationDefinition.generated.h"

class UUserWidget;

DECLARE_DYNAMIC_DELEGATE(FConversationBlueprintDelegate);
/**
 * 
 */
USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationBranchOption
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FString Option;
	
	/** 目标节点行名（在DataTable中选择） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FName TargetNodeRowName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FGameplayTagContainer EnableConditionTags;

	/** 分支被选中时触发的蓝图委托 */
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	//FConversationBlueprintDelegate OnOptionSelected;
};
/**
 * 
 */
USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationNodeData : public FTableRowBase
{
	GENERATED_BODY()

	/** 节点唯一标识符（自动使用行名） */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FName NodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FString SpeakerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FString SpeakerDisplayName;

	/** 对话文本 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FText DialogueText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	bool IsSkipable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	bool bIsEndNode = false;

	/** 对话分支选项列表（为空则线性跳转DefaultNextNodeRowName） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	TArray<FConversationBranchOption> BranchOptions;

	/** 默认下一个节点行名（无分支时生效，在DataTable中选择） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FName DefaultNextNodeRowName;
};

USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationTreeDefinition : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FName DialogueTreeID;

	// 触发该对话树所需满足的标签条件（与已有系统兼容）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
	FGameplayTagContainer ExecuteConditionTags;

	// 对话树开始前/结束后自动修改的标签
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
	FGameplayTagContainer TagsToAddOnStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
	FGameplayTagContainer TagsToRemoveOnStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
	FGameplayTagContainer TagsToAddOnEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
	FGameplayTagContainer TagsToRemoveOnEnd;

	// 节点列表（可由外部DataTable引用，也可以直接内嵌）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Nodes")
	TArray<FDataTableRowHandle> NodeReferences;
};

