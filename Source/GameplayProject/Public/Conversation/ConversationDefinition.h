// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ConversationDefinition.generated.h"

class USoundBase;
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

	/** 对应跳转的节点ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FString TargetNodeID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FGameplayTagContainer EnableConditionTags;

	/** 分支被选中时触发的蓝图委托 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FConversationBlueprintDelegate OnOptionSelected;
	
};
/**
 * 
 */
USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversationNodeData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FString NodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FString SpeakerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FString SpeakerDisplayName;

	/** 对话文本 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	FText DialogueText;

	/** 文本显示速度（字符/秒，0=瞬间显示） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	float TextDisplaySpeed = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	float DisplayDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	TArray<FString> NextNodeIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Audio")
	USoundBase* VoiceSoundAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Audio")
	float VoiceVolume = 0.8f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Audio")
	float VoicePlayDelay = 0.0f;

	/** 是否同步文本显示和语音播放 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Audio")
	bool bSyncTextWithVoice = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	bool IsSkipable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
	bool bIsEndNode = false;

	/** 对话分支选项列表（为空则线性跳转NextNodeID） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	TArray<FConversationBranchOption> BranchOptions;

	/** 默认下一个节点ID（无分支时生效） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Branch")
	FString DefaultNextNodeID;
};

/*USTRUCT(BlueprintType)
struct GAMEPLAYPROJECT_API FConversation
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Basic")
    FString DialogueTreeID;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
    FGameplayTagContainer ExecuteConditionTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
    FGameplayTagContainer TagsToAddAfterExecute;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Condition")
    FGameplayTagContainer TagsToRemoveAfterExecute;
};
*/

