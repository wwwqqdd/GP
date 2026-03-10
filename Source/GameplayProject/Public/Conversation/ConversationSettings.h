// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ConversationSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Conversation System"))
class GAMEPLAYPROJECT_API UConversationSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Conversation", meta = (AllowedClasses = "ConversationDataTable"))
	TSoftObjectPtr<UDataTable> ConversationDataTable;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Conversation", meta = (AllowedClasses = "ConversationTreeDataTable"))
	TSoftObjectPtr<UDataTable> ConversationTreeDataTable;
    /**
     * 获取对话系统配置的DataTable
     * @return 配置实例
     */
	UFUNCTION(BlueprintCallable, Category = "Conversation|Settings")
	UDataTable* GetConversationDataTable();

	UFUNCTION(BlueprintCallable, Category = "Conversation|Settings")
	UDataTable* GetConversationTreeDataTable();
	
	
	
};
