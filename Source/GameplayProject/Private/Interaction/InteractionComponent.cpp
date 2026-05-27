// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction/InteractionComponent.h"
#include "Interaction/Interactable.h"
#include "Interaction/InteractionScoring.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogInteraction, Log, All);

namespace
{
    // "无目标"语义的空提示：不显示、不可交互
    static const FInteractionPrompt EmptyPrompt{ FText::GetEmpty(), nullptr, false };
}

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
    // 在 RegisterComponent 之前配置半径与碰撞，顺序更稳
    DetectionSphere->SetSphereRadius(DetectionRadius);
    DetectionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    DetectionSphere->SetGenerateOverlapEvents(true);
    DetectionSphere->RegisterComponent();
    // 挂载前校验 RootComponent 非空，避免无根 Actor 崩溃
    if (USceneComponent* Root = Owner->GetRootComponent())
    {
        DetectionSphere->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
    }
    DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &UInteractionComponent::OnSphereBeginOverlap);
    DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &UInteractionComponent::OnSphereEndOverlap);

    if (UWorld* World = GetWorld())
    {
        const float SafeInterval = FMath::Max(ScanInterval, 0.01f);
        World->GetTimerManager().SetTimer(ScanTimerHandle, this, &UInteractionComponent::ScanAndUpdateTarget, SafeInterval, true);
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

void UInteractionComponent::OnSphereBeginOverlap(UPrimitiveComponent* /*OverlappedComp*/, AActor* /*Other*/, UPrimitiveComponent* /*OtherComp*/, int32 /*BodyIndex*/, bool /*bFromSweep*/, const FHitResult& /*Sweep*/)
{
    // 候选集统一在 ScanAndUpdateTarget 中权威重建，无需在此增删。
    // 保留回调以供未来即时性触发使用。
}

void UInteractionComponent::OnSphereEndOverlap(UPrimitiveComponent* /*OverlappedComp*/, AActor* Other, UPrimitiveComponent* /*OtherComp*/, int32 /*BodyIndex*/)
{
    // 仅保留低延迟行为：离开的是当前目标则立即重选。
    // 注意：多 primitive Actor 任一碰撞体离开都会触发，但重建逻辑会用
    // GetOverlappingActors 重新确认该 Actor 是否仍有其它碰撞体在范围内。
    if (Other && CurrentTargetActor.Get() == Other)
    {
        ScanAndUpdateTarget();
    }
}

void UInteractionComponent::ScanAndUpdateTarget()
{
    // 权威重建候选集：以球体当前 overlap 的 Actor 为准，避免 Begin/End 计数
    // 在多碰撞体 Actor 上不匹配（任一离开误删整个 Actor）的问题。
    Candidates.Reset();

    if (DetectionSphere)
    {
        TArray<AActor*> Overlapping;
        DetectionSphere->GetOverlappingActors(Overlapping);

        const AActor* Owner = GetOwner();
        for (AActor* Actor : Overlapping)
        {
            if (Actor && Actor != Owner && Actor->Implements<UInteractable>())
            {
                Candidates.AddUnique(Actor);
            }
        }
    }

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
    const FInteractionPrompt Prompt = NewTarget ? GetPromptFor(NewTarget) : EmptyPrompt;
    UE_LOG(LogInteraction, Verbose, TEXT("Target -> %s"), *GetNameSafe(NewTarget));
    OnTargetChanged.Broadcast(Prompt);
}

FInteractionPrompt UInteractionComponent::GetPromptFor(AActor* TargetActor) const
{
    if (TargetActor && TargetActor->Implements<UInteractable>())
    {
        return IInteractable::Execute_GetInteractionPrompt(TargetActor);
    }
    return EmptyPrompt;
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
