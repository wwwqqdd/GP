// Fill out your copyright notice in the Description page of Project Settings.


#include "Conversation/ConversationSettings.h"

UDataTable* UConversationSettings::GetConversationDataTable()
{
	if (ConversationDataTable.IsNull())
	{
		return nullptr;
	}
	return ConversationDataTable.LoadSynchronous();
}

UDataTable* UConversationSettings::GetConversationTreeDataTable()
{
	if (ConversationTreeDataTable.IsNull())
	{
		return nullptr;
	}
	return ConversationTreeDataTable.LoadSynchronous();
} 
