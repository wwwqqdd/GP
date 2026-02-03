// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify/AnimNotifyState_AttackWindow.h"

#include "AbilitySystemComponent.h"
#include "Components/SkeletalMeshComponent.h"

void UAnimNotifyState_AttackWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (!IsValid(MeshComp)) return;
	UAbilitySystemComponent* ASC = MeshComp->GetOwner() ? MeshComp->GetOwner()->FindComponentByClass<UAbilitySystemComponent>() : nullptr;
	if (!IsValid(ASC)) return;
	if (const bool bHasTag = ASC->HasMatchingGameplayTag(AttackWindowTag); !bHasTag)
	{
		ASC->AddLooseGameplayTag(AttackWindowTag);
	}
}

void UAnimNotifyState_AttackWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (!IsValid(MeshComp)) return;
	UAbilitySystemComponent* ASC = MeshComp->GetOwner() ? MeshComp->GetOwner()->FindComponentByClass<UAbilitySystemComponent>() : nullptr;
	if (!IsValid(ASC)) return;
	if (const bool bHasTag = ASC->HasMatchingGameplayTag(AttackWindowTag))
	{
		ASC->RemoveLooseGameplayTag(AttackWindowTag);
	}
}
