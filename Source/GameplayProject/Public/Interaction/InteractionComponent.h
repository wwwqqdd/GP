// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interaction/InteractionTypes.h"
#include "InteractionComponent.generated.h"

class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionTargetChanged, const FInteractionPrompt&, Prompt);

UCLASS(ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent))
class GAMEPLAYPROJECT_API UInteractionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInteractionComponent();

    UPROPERTY(EditAnywhere, Category = "Interaction")
    float DetectionRadius = 250.f;

    UPROPERTY(EditAnywhere, Category = "Interaction")
    float ScanInterval = 0.1f;

    // 0 = 不过滤朝向；>0 仅取角色前方候选
    UPROPERTY(EditAnywhere, Category = "Interaction")
    float FacingDotThreshold = 0.f;

    // Target 变化时广播；Prompt.bEnabled=false 表示当前无目标
    UPROPERTY(BlueprintAssignable, Category = "Interaction")
    FOnInteractionTargetChanged OnTargetChanged;

    // 供 Enhanced Input 调用：对当前目标执行交互
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    bool TryInteract();

    UFUNCTION(BlueprintPure, Category = "Interaction")
    AActor* GetCurrentTargetActor() const { return CurrentTargetActor.Get(); }

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;

private:
    UPROPERTY()
    TObjectPtr<USphereComponent> DetectionSphere;

    TArray<TWeakObjectPtr<AActor>> Candidates;
    TWeakObjectPtr<AActor> CurrentTargetActor;
    FTimerHandle ScanTimerHandle;

    UFUNCTION()
    void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult& Sweep);

    UFUNCTION()
    void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 BodyIndex);

    void ScanAndUpdateTarget();
    AActor* PickBestCandidate() const;
    void SetCurrentTarget(AActor* NewTarget);
    FInteractionPrompt GetPromptFor(AActor* TargetActor) const;
};
