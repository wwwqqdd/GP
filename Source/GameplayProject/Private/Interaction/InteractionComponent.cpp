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

void UInteractionComponent::OnSphereBeginOverlap(UPrimitiveComponent* /*OverlappedComp*/, AActor* Other, UPrimitiveComponent* /*OtherComp*/, int32 /*BodyIndex*/, bool /*bFromSweep*/, const FHitResult& /*Sweep*/)
{
    if (Other && Other != GetOwner() && Other->Implements<UInteractable>())
    {
        Candidates.AddUnique(Other);
    }
}

void UInteractionComponent::OnSphereEndOverlap(UPrimitiveComponent* /*OverlappedComp*/, AActor* Other, UPrimitiveComponent* /*OtherComp*/, int32 /*BodyIndex*/)
{
    if (!Other) return;
    Candidates.RemoveAll([Other](const TWeakObjectPtr<AActor>& P) { return P.Get() == Other; });
    if (CurrentTargetActor.Get() == Other)
    {
        ScanAndUpdateTarget(); // 立即重选
    }
}

void UInteractionComponent::ScanAndUpdateTarget()
{
    // 清理失效弱引用
    Candidates.RemoveAll([](const TWeakObjectPtr<AActor>& P) { return !P.IsValid(); });

    AActor* Best = PickBestCandidate();
    if (Best != CurrentTargetActor.Get())
    {
        SetCurrentTarget(Best);
    }
}

AActor* UInteractionComponent::PickBestCandidate() const
{
    const AActor* Owner = GetOwner();
    if (!Owner) return nullptr;

    const FVector OwnerLoc = Owner->GetActorLocation();
    const FVector OwnerFwd = Owner->GetActorForwardVector();

    AActor* Best = nullptr;
    float BestScore = -FLT_MAX;

    for (const TWeakObjectPtr<AActor>& WeakActor : Candidates)
    {
        AActor* Cand = WeakActor.Get();
        if (!Cand) continue;

        const FInteractionPrompt Prompt = GetPromptFor(Cand);
        if (!Prompt.bEnabled) continue;

        const float Score = InteractionScoring::ScoreCandidate(
            OwnerLoc, OwnerFwd, Cand->GetActorLocation(), DetectionRadius, FacingDotThreshold);
        if (Score < 0.f) continue; // 被朝向阈值剔除

        if (Score > BestScore)
        {
            BestScore = Score;
            Best = Cand;
        }
    }
    return Best;
}

void UInteractionComponent::SetCurrentTarget(AActor* NewTarget)
{
    CurrentTargetActor = NewTarget;
    const FInteractionPrompt Prompt = NewTarget ? GetPromptFor(NewTarget) : FInteractionPrompt{ FText::GetEmpty(), nullptr, false };
    UE_LOG(LogInteraction, Verbose, TEXT("Target -> %s"), *GetNameSafe(NewTarget));
    OnTargetChanged.Broadcast(Prompt);
}

FInteractionPrompt UInteractionComponent::GetPromptFor(AActor* TargetActor) const
{
    if (TargetActor && TargetActor->Implements<UInteractable>())
    {
        return IInteractable::Execute_GetInteractionPrompt(TargetActor);
    }
    return FInteractionPrompt{ FText::GetEmpty(), nullptr, false };
}

bool UInteractionComponent::TryInteract()
{
    AActor* Target = CurrentTargetActor.Get();
    if (!Target || !Target->Implements<UInteractable>())
    {
        UE_LOG(LogInteraction, Verbose, TEXT("TryInteract: 无有效目标"));
        return false;
    }
    const FInteractionPrompt Prompt = IInteractable::Execute_GetInteractionPrompt(Target);
    if (!Prompt.bEnabled)
    {
        UE_LOG(LogInteraction, Verbose, TEXT("TryInteract: 目标当前不可交互"));
        return false;
    }
    IInteractable::Execute_OnInteract(Target, GetOwner());
    return true;
}
