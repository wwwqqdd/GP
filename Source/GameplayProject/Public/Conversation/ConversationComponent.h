// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConversationDefinition.h"
#include "ConversationComponent.generated.h"

class UConversationInstanceSubsystem;

// 对话组件事件委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConversationStarted, const FString&, DialogueTreeID, const FString&, StartNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConversationEnded, const FString&, DialogueTreeID, const FString&, EndNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnConversationNodeChanged, const FString&, DialogueTreeID, const FString&, OldNodeID, const FString&, NewNodeID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConversationBranchSelected, const FString&, SelectedOption);

/**
 * 对话组件 - 提供Actor级别的对话交互接口
 * 封装ConversationInstanceSubsystem的功能，提供便捷的对话控制方法
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYPROJECT_API UConversationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UConversationComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// ========== 对话生命周期控制 ==========
	
	/**
	 * 开始对话
	 * @param DialogueTreeID 对话树ID
	 * @param StartNodeID 起始节点ID（可选，为空则使用默认起始节点）
	 * @return 是否成功开始对话
	 */
	UFUNCTION(BlueprintCallable, Category = "Conversation|Control")
	bool StartConversation(const FString& DialogueTreeID, const FString& StartNodeID = TEXT(""));

	/**
	 * 使用默认对话树ID开始对话
	 * @param StartNodeID 起始节点ID（可选，为空则使用默认起始节点）
	 * @return 是否成功开始对话
	 */
	UFUNCTION(BlueprintCallable, Category = "Conversation|Control")
	bool StartDefaultConversation(const FString& StartNodeID = TEXT(""));

	/**
	 * 结束当前对话
	 * @param EndNodeID 结束节点ID（可选，为空则使用当前节点）
	 * @return 是否成功结束对话
	 */
	UFUNCTION(BlueprintCallable, Category = "Conversation|Control")
	bool EndConversation(const FString& EndNodeID = TEXT(""));

	/**
	 * 推进对话到下一个节点
	 * @return 是否成功推进
	 */
	UFUNCTION(BlueprintCallable, Category = "Conversation|Control")
	bool AdvanceConversation();

	/**
	 * 选择分支选项
	 * @param SelectedOption 选择的选项文本
	 * @return 是否成功选择
	 */
	UFUNCTION(BlueprintCallable, Category = "Conversation|Control")
	bool SelectBranchOption(const FString& SelectedOption);

	// ========== 对话查询功能 ==========

	/**
	 * 获取当前对话节点数据
	 * @param OutNodeData 输出的节点数据
	 * @return 是否成功获取
	 */
	UFUNCTION(BlueprintPure, Category = "Conversation|Query")
	bool GetCurrentNodeData(FConversationNodeData& OutNodeData) const;

	/**
	 * 获取当前可用的分支选项
	 * @return 分支选项数组
	 */
	UFUNCTION(BlueprintPure, Category = "Conversation|Query")
	TArray<FConversationBranchOption> GetAvailableBranchOptions() const;

	/**
	 * 检查是否正在进行对话
	 * @return 是否正在对话中
	 */
	UFUNCTION(BlueprintPure, Category = "Conversation|Query")
	bool IsInConversation() const;

	/**
	 * 获取当前对话树ID
	 * @return 当前对话树ID
	 */
	UFUNCTION(BlueprintPure, Category = "Conversation|Query")
	FString GetCurrentDialogueTreeID() const;

	/**
	 * 检查当前节点是否为结束节点
	 * @return 是否为结束节点
	 */
	UFUNCTION(BlueprintPure, Category = "Conversation|Query")
	bool IsCurrentNodeEndNode() const;

	/**
	 * 检查当前节点是否有分支选项
	 * @return 是否有分支选项
	 */
	UFUNCTION(BlueprintPure, Category = "Conversation|Query")
	bool HasBranchOptions() const;

	// ========== 事件委托 ==========

	/** 对话开始事件 */
	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnConversationStarted OnConversationStarted;

	/** 对话结束事件 */
	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnConversationEnded OnConversationEnded;

	/** 对话节点变更事件 */
	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnConversationNodeChanged OnConversationNodeChanged;

	/** 分支选择事件 */
	UPROPERTY(BlueprintAssignable, Category = "Conversation|Events")
	FOnConversationBranchSelected OnConversationBranchSelected;

public:
	/** 默认对话树ID - 可以在编辑器中预设，用于自动开始对话 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conversation|Settings")
	FString DefaultDialogueTreeID;

protected:
	/** 当前运行的对话树ID - 运行时状态，由系统自动管理 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Conversation|State")
	FString CurrentDialogueTreeID;

	/** 对话子系统引用 */
	UPROPERTY()
	UConversationInstanceSubsystem* ConversationSubsystem;

private:
	/** 绑定子系统事件 */
	void BindSubsystemEvents();

	/** 解绑子系统事件 */
	void UnbindSubsystemEvents();

	/** 子系统事件处理函数 */
	UFUNCTION()
	void HandleDialogueStarted(const FString& DialogueTreeID, AActor* TargetActor, const FString& StartNodeID);

	UFUNCTION()
	void HandleDialogueEnded(const FString& DialogueTreeID, AActor* TargetActor, const FString& EndNodeID);

	UFUNCTION()
	void HandleNodeChanged(const FString& DialogueTreeID, AActor* TargetActor, const FString& OldNodeID, const FString& NewNodeID);

	UFUNCTION()
	void HandleBranchSelected(const FString& DialogueTreeID, AActor* TargetActor, const FString& SelectedOption);
};
