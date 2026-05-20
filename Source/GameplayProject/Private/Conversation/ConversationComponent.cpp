// Fill out your copyright notice in the Description page of Project Settings.

#include "Conversation/ConversationComponent.h"
#include "Conversation/ConversationInstanceSubsystem.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

UConversationComponent::UConversationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UConversationComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// 获取对话子系统
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			ConversationSubsystem = GameInstance->GetSubsystem<UConversationInstanceSubsystem>();
		}
	}

	// 绑定子系统事件
	BindSubsystemEvents();
}

void UConversationComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// 解绑子系统事件
	UnbindSubsystemEvents();
	
	Super::EndPlay(EndPlayReason);
}

// ========== 对话生命周期控制 ==========

bool UConversationComponent::StartConversation(const FString& DialogueTreeID, const FName& StartNodeID)
{
	if (ConversationSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StartConversation failed: ConversationSubsystem is null."));
		return false;
	}

	if (DialogueTreeID.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("StartConversation failed: DialogueTreeID is empty."));
		return false;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StartConversation failed: Owner actor is null."));
		return false;
	}

	// 调用子系统启动对话
	bool bSuccess = ConversationSubsystem->StartDialogue(GetOwner(), DialogueTreeID, OwnerActor, StartNodeID);
	
	if (bSuccess)
	{
		CurrentDialogueTreeID = DialogueTreeID;
	}
	
	return bSuccess;
}

bool UConversationComponent::StartDefaultConversation(const FName& StartNodeID)
{
	if (DefaultDialogueTreeID.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("StartDefaultConversation failed: DefaultDialogueTreeID is not set."));
		return false;
	}

	return StartConversation(DefaultDialogueTreeID, StartNodeID);
}

bool UConversationComponent::EndConversation(const FName& EndNodeID)
{
	if (ConversationSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("EndConversation failed: ConversationSubsystem is null."));
		return false;
	}

	if (CurrentDialogueTreeID.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("EndConversation failed: No active conversation."));
		return false;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("EndConversation failed: Owner actor is null."));
		return false;
	}

	// 调用子系统结束对话
	bool bSuccess = ConversationSubsystem->EndDialogue(GetOwner(), CurrentDialogueTreeID, OwnerActor, EndNodeID);
	
	if (bSuccess)
	{
		CurrentDialogueTreeID = TEXT("");
	}
	
	return bSuccess;
}

bool UConversationComponent::AdvanceConversation()
{
	if (ConversationSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AdvanceConversation failed: ConversationSubsystem is null."));
		return false;
	}

	if (CurrentDialogueTreeID.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("AdvanceConversation failed: No active conversation."));
		return false;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AdvanceConversation failed: Owner actor is null."));
		return false;
	}

	return ConversationSubsystem->AdvanceDialogue(GetOwner(), CurrentDialogueTreeID, OwnerActor);
}

bool UConversationComponent::SelectBranchOption(const FString& SelectedOption)
{
	if (ConversationSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectBranchOption failed: ConversationSubsystem is null."));
		return false;
	}

	if (CurrentDialogueTreeID.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectBranchOption failed: No active conversation."));
		return false;
	}

	if (SelectedOption.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectBranchOption failed: SelectedOption is empty."));
		return false;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectBranchOption failed: Owner actor is null."));
		return false;
	}

	return ConversationSubsystem->SelectBranchOption(CurrentDialogueTreeID, OwnerActor, SelectedOption);
}

// ========== 对话查询功能 ==========

bool UConversationComponent::GetCurrentNodeData(FConversationNodeData& OutNodeData) const
{
	if (ConversationSubsystem == nullptr || CurrentDialogueTreeID.IsEmpty())
	{
		return false;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		return false;
	}

	return ConversationSubsystem->GetCurrentNodeData(CurrentDialogueTreeID, OwnerActor, OutNodeData);
}

TArray<FConversationBranchOption> UConversationComponent::GetAvailableBranchOptions() const
{
	if (ConversationSubsystem == nullptr || CurrentDialogueTreeID.IsEmpty())
	{
		return TArray<FConversationBranchOption>();
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		return TArray<FConversationBranchOption>();
	}

	return ConversationSubsystem->GetAvailableBranchOptions(CurrentDialogueTreeID, OwnerActor);
}

bool UConversationComponent::IsInConversation() const
{
	if (ConversationSubsystem == nullptr || CurrentDialogueTreeID.IsEmpty())
	{
		return false;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		return false;
	}

	return ConversationSubsystem->IsDialogueActive(CurrentDialogueTreeID, OwnerActor);
}

FString UConversationComponent::GetCurrentDialogueTreeID() const
{
	return CurrentDialogueTreeID;
}

bool UConversationComponent::IsCurrentNodeEndNode() const
{
	FConversationNodeData NodeData;
	if (!GetCurrentNodeData(NodeData))
	{
		return false;
	}

	return NodeData.bIsEndNode;
}

bool UConversationComponent::HasBranchOptions() const
{
	FConversationNodeData NodeData;
	if (!GetCurrentNodeData(NodeData))
	{
		return false;
	}

	return !NodeData.BranchOptions.IsEmpty();
}

// ========== 事件绑定 ==========

void UConversationComponent::BindSubsystemEvents()
{
	if (ConversationSubsystem == nullptr)
	{
		return;
	}

	// 绑定子系统事件
	ConversationSubsystem->OnDialogueStarted.AddDynamic(this, &UConversationComponent::HandleDialogueStarted);
	ConversationSubsystem->OnDialogueEnded.AddDynamic(this, &UConversationComponent::HandleDialogueEnded);
	ConversationSubsystem->OnNodeChanged.AddDynamic(this, &UConversationComponent::HandleNodeChanged);
	ConversationSubsystem->OnBranchSelected.AddDynamic(this, &UConversationComponent::HandleBranchSelected);
}

void UConversationComponent::UnbindSubsystemEvents()
{
	if (ConversationSubsystem == nullptr)
	{
		return;
	}

	// 解绑子系统事件
	ConversationSubsystem->OnDialogueStarted.RemoveDynamic(this, &UConversationComponent::HandleDialogueStarted);
	ConversationSubsystem->OnDialogueEnded.RemoveDynamic(this, &UConversationComponent::HandleDialogueEnded);
	ConversationSubsystem->OnNodeChanged.RemoveDynamic(this, &UConversationComponent::HandleNodeChanged);
	ConversationSubsystem->OnBranchSelected.RemoveDynamic(this, &UConversationComponent::HandleBranchSelected);
}

// ========== 子系统事件处理 ==========

void UConversationComponent::HandleDialogueStarted(const FString& DialogueTreeID, AActor* TargetActor, const FName& StartNodeID)
{
	// 只处理属于当前Actor的对话事件
	if (TargetActor == GetOwner())
	{
		CurrentDialogueTreeID = DialogueTreeID;
		OnConversationStarted.Broadcast(DialogueTreeID, StartNodeID);
	}
}

void UConversationComponent::HandleDialogueEnded(const FString& DialogueTreeID, AActor* TargetActor, const FName& EndNodeID)
{
	// 只处理属于当前Actor的对话事件
	if (TargetActor == GetOwner())
	{
		CurrentDialogueTreeID = TEXT("");
		OnConversationEnded.Broadcast(DialogueTreeID, EndNodeID);
	}
}

void UConversationComponent::HandleNodeChanged(const FString& DialogueTreeID, AActor* TargetActor, const FName& OldNodeID, const FName& NewNodeID)
{
	// 只处理属于当前Actor的对话事件
	if (TargetActor == GetOwner())
	{
		OnConversationNodeChanged.Broadcast(DialogueTreeID, OldNodeID, NewNodeID);
	}
}

void UConversationComponent::HandleBranchSelected(const FString& DialogueTreeID, AActor* TargetActor, const FString& SelectedOption)
{
	// 只处理属于当前Actor的对话事件
	if (TargetActor == GetOwner())
	{
		OnConversationBranchSelected.Broadcast(SelectedOption);
	}
}