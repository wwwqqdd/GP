// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ConversationDefinition.generated.h"

class UUserWidget;

DECLARE_DYNAMIC_DELEGATE(FConversationBlueprintDelegate);

/**
 * 对话节点行名引用 - 包装 FName 以支持编辑器下拉选择
 */
USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationRowNameRef
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName RowName;

	FConversationRowNameRef() : RowName(NAME_None) {}
	FConversationRowNameRef(FName InName) : RowName(InName) {}

	bool IsNone() const { return RowName.IsNone(); }
	operator FName() const { return RowName; }
};

/**
 * 对话节点类型
 * Direct: 线性跳转，使用 DefaultNextNodeRowName 指向下一节点
 * Select: 分支选择，使用 BranchOptions 提供多个分支
 */
UENUM(BlueprintType)
enum class EConversationNodeType : uint8
{
	Direct UMETA(DisplayName = "Direct"),
	Select UMETA(DisplayName = "Select")
};

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
	FConversationRowNameRef TargetNodeRowName;
	
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

	/** 节点唯一标识符（自动从行名同步，只读） */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Conversation|Basic")
	FName NodeID;

	virtual void OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName) override
	{
		NodeID = InRowName;
	}

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

	/** 节点类型：Direct 线性跳转，Select 分支选择 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	EConversationNodeType Type = EConversationNodeType::Direct;

	/** 对话分支选项列表（仅 Select 类型生效） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch",
		meta = (EditCondition = "Type == EConversationNodeType::Select", EditConditionHides))
	TArray<FConversationBranchOption> BranchOptions;

	/** 默认下一个节点行名（仅 Direct 类型生效，在DataTable中选择） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch",
		meta = (EditCondition = "Type == EConversationNodeType::Direct && bIsEndNode == false", EditConditionHides))
	FConversationRowNameRef DefaultNextNodeRowName;
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

