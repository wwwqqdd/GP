// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction/InteractionComponent.h"
#include "Interaction/Interactable.h"
#include "Interaction/InteractionScoring.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogInteraction, Log, All);

UInteractionComponent::UInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::BeginPlay()
{
    Super::BeginPlay();

    AActor* Owner = GetOwner();
    if (!Owner) return;

    DetectionSphere = NewObject<USphereComponent>(Owner, TEXT("InteractionDetectionSphere"));
    DetectionSphere->RegisterComponent();
    DetectionSphere->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
    DetectionSphere->SetSphereRadius(DetectionRadius);
    DetectionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    DetectionSphere->SetGenerateOverlapEvents(true);
    DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &UInteractionComponent::OnSphereBeginOverlap);
    DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &UInteractionComponent::OnSphereEndOverlap);

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().SetTimer(ScanTimerHandle, this, &UInteractionComponent::ScanAndUpdateTarget, ScanInterval, true);
    }
}

void UInteractionComponent::EndPlay(const EEndPlayReason::Type Reason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(ScanTimerHandle);
    }
    if (DetectionSphere)
    {
        DetectionSphere->OnComponentBeginOverlap.RemoveDynamic(this, &UInteractionComponent::OnSphereBeginOverlap);
        DetectionSphere->OnComponentEndOverlap.RemoveDynamic(this, &UInteractionComponent::OnSphereEndOverlap);
    }
    Super::EndPlay(Reason);
}

// 以下在 Task 5 填充实现
void UInteractionComponent::OnSphereBeginOverlap(UPrimitiveComponent*, AActor*, UPrimitiveComponent*, int32, bool, const FHitResult&) {}
void UInteractionComponent::OnSphereEndOverlap(UPrimitiveComponent*, AActor*, UPrimitiveComponent*, int32) {}
void UInteractionComponent::ScanAndUpdateTarget() {}
AActor* UInteractionComponent::PickBestCandidate() const { return nullptr; }
void UInteractionComponent::SetCurrentTarget(AActor*) {}
FInteractionPrompt UInteractionComponent::GetPromptFor(AActor*) const { return FInteractionPrompt(); }
bool UInteractionComponent::TryInteract() { return false; }
