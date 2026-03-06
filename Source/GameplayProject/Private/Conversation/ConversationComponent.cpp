// Fill out your copyright notice in the Description page of Project Settings.


#include "Conversation/ConversationComponent.h"

UConversationComponent::UConversationComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;
}

void UConversationComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UConversationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

