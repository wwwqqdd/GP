# 交互系统（Interaction System）实现计划

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 为 GP 项目实现轻量交互系统——走近自动提示 + 按键确认，支持物品拾取（接现有 Inventory）和 NPC 对话触发（接现有 Conversation）。

**Architecture:** `UInteractionComponent`（C++，SphereOverlap 检测 + 0.1s 节流评分选最佳目标）通过 `IInteractable` 接口（2 个 BlueprintNativeEvent）直调目标的 `OnInteract`，目标自己处理业务（Pickup → InventoryComponent::AddItem，NPC → ConversationComponent::StartConversation）。提示 UI 经委托被动展示。评分逻辑抽成纯函数以便单元测试。

**Tech Stack:** UE 5.6、C++（GAMEPLAYPROJECT 模块）、Enhanced Input、UMG、UE Automation Test。引擎根 `D:\SoftWare\UE_5.6`，项目根 `D:\SoftWare\Project\GP`。

**Spec:** `docs/superpowers/specs/2026-05-27-interaction-system-design.md`

---

## 通用命令

**编译命令（每个 C++ 任务末尾跑）：**
```
"D:\SoftWare\UE_5.6\Engine\Build\BatchFiles\Build.bat" GameplayProjectEditor Win64 Development -Project="D:\SoftWare\Project\GP\GameplayProject.uproject" -WaitMutex
```
预期结尾：`Build succeeded` 或 `Target is up to date`。

**自动化测试运行命令：**
```
"D:\SoftWare\UE_5.6\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "D:\SoftWare\Project\GP\GameplayProject.uproject" -ExecCmds="Automation RunTests GameplayProject.Interaction.Scoring; Quit" -unattended -nopause -nullrhi -nosplash -log
```
在输出 log 中查找 `Test Completed. Result={Success}` 与 `... 1 test ... Succeeded`。

> 注：编译需关闭占用该模块 DLL 的编辑器实例，或加 `-WaitMutex` 等待。

---

## 文件结构

| 文件 | 职责 |
|------|------|
| `Source/GameplayProject/Public/Interaction/InteractionTypes.h` | `FInteractionPrompt` 数据 struct |
| `Source/GameplayProject/Public/Interaction/Interactable.h` | `IInteractable` 接口（UINTERFACE） |
| `Source/GameplayProject/Public/Interaction/InteractionScoring.h` | 纯评分函数（inline，可单测） |
| `Source/GameplayProject/Private/Interaction/InteractionScoringTest.cpp` | 评分函数的 Automation 测试 |
| `Source/GameplayProject/Public/Interaction/InteractionComponent.h` | 组件声明 |
| `Source/GameplayProject/Private/Interaction/InteractionComponent.cpp` | 组件实现 |
| `Source/GameplayProject/Public/Interaction/PickupActor.h` | Pickup 基类声明 |
| `Source/GameplayProject/Private/Interaction/PickupActor.cpp` | Pickup 实现 |
| `GameplayProjectCharacter.h` / `.cpp`（改） | 加 InteractionComponent 子对象 |
| `WBP_InteractionPrompt`（BP 资产） | 提示 UI |
| `IA_Interact` + IMC（输入资产） | 交互按键 |
| `BP_Pickup_*` / NPC BP（BP 资产） | 业务派生 |

---

## Task 1: 数据结构 FInteractionPrompt

**Files:**
- Create: `Source/GameplayProject/Public/Interaction/InteractionTypes.h`

- [ ] **Step 1: 写头文件**

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionTypes.generated.h"

/** 交互提示数据：单选项交互的展示信息 */
USTRUCT(BlueprintType)
struct FInteractionPrompt
{
    GENERATED_BODY()

    // 提示文字，例如 "[E] 拾取苹果"
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    FText Text;

    // 可选图标，可为空，UI 容错
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    TObjectPtr<UTexture2D> Icon = nullptr;

    // 为 false 时即便被检测到也不显示提示、不可交互
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    bool bEnabled = true;
};
```

- [ ] **Step 2: 编译验证**

Run: 通用编译命令
Expected: `Build succeeded`

- [ ] **Step 3: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/Public/Interaction/InteractionTypes.h
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add FInteractionPrompt data struct"
```

---

## Task 2: IInteractable 接口

**Files:**
- Create: `Source/GameplayProject/Public/Interaction/Interactable.h`

- [ ] **Step 1: 写接口头文件**

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interaction/InteractionTypes.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, meta = (CannotImplementInterfaceInBlueprint = "false"))
class UInteractable : public UInterface
{
    GENERATED_BODY()
};

/** 可交互对象接口：实现者自行决定提示内容与被交互时的行为 */
class GAMEPLAYPROJECT_API IInteractable
{
    GENERATED_BODY()

public:
    // 返回提示信息（文字/图标/是否可用）。BP 可 override。
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    FInteractionPrompt GetInteractionPrompt() const;

    // 被交互时调用，Instigator 通常是角色。BP 可 override 写实际效果。
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnInteract(AActor* Instigator);
};
```

- [ ] **Step 2: 编译验证**

Run: 通用编译命令
Expected: `Build succeeded`

- [ ] **Step 3: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/Public/Interaction/Interactable.h
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add IInteractable interface"
```

---

## Task 3: 纯评分函数 + 单元测试（TDD）

**Files:**
- Create: `Source/GameplayProject/Public/Interaction/InteractionScoring.h`
- Test: `Source/GameplayProject/Private/Interaction/InteractionScoringTest.cpp`

评分规则（来自 spec §5.2）：score = 0.7×距离分 + 0.3×朝向分。距离分 = `1 - Dist/Radius`（夹到 [0,1]）。朝向分 = `(Dot+1)/2`（Dot 是 Instigator 前向与「指向候选」单位向量的点积）。若 `FacingDotThreshold != 0` 且 Dot < threshold → 返回 -1（剔除）。

- [ ] **Step 1: 先写失败测试**

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#include "Misc/AutomationTest.h"
#include "Interaction/InteractionScoring.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FInteractionScoringTest,
    "GameplayProject.Interaction.Scoring",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInteractionScoringTest::RunTest(const FString& Parameters)
{
    using namespace InteractionScoring;

    const FVector Origin(0, 0, 0);
    const FVector Forward(1, 0, 0);
    const float Radius = 250.f;

    // 1) 更近的候选得分更高（不过滤朝向）
    const float Near = ScoreCandidate(Origin, Forward, FVector(50, 0, 0), Radius, 0.f);
    const float Far  = ScoreCandidate(Origin, Forward, FVector(200, 0, 0), Radius, 0.f);
    TestTrue(TEXT("近的候选评分高于远的"), Near > Far);

    // 2) 同距离下，正对前方的得分高于侧方
    const float Front = ScoreCandidate(Origin, Forward, FVector(100, 0, 0), Radius, 0.f);
    const float Side  = ScoreCandidate(Origin, Forward, FVector(0, 100, 0), Radius, 0.f);
    TestTrue(TEXT("正前方评分高于侧方"), Front > Side);

    // 3) 朝向阈值剔除：背后候选在 threshold=0.3 下被剔除（返回负）
    const float Behind = ScoreCandidate(Origin, Forward, FVector(-100, 0, 0), Radius, 0.3f);
    TestTrue(TEXT("阈值下背后候选被剔除"), Behind < 0.f);

    // 4) 评分始终在合理上界内（非剔除时 <= 1）
    TestTrue(TEXT("正常评分不超过1"), Front <= 1.0f + KINDA_SMALL_NUMBER);

    return true;
}
```

- [ ] **Step 2: 编译验证测试失败**

Run: 通用编译命令
Expected: 编译失败，报 `InteractionScoring.h` 找不到 / `ScoreCandidate` 未定义。

- [ ] **Step 3: 实现评分函数**

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace InteractionScoring
{
    /**
     * 给一个候选交互物打分。分越高越优先。
     * @param InstigatorLocation 交互者位置
     * @param InstigatorForward  交互者前向（应为单位向量）
     * @param CandidateLocation  候选物位置
     * @param DetectionRadius    检测半径（cm），用于归一化距离
     * @param FacingDotThreshold 朝向点积阈值；为 0 表示不过滤；>0 时 Dot 低于它的候选返回 -1
     * @return [0,1] 的评分；被剔除返回 -1
     */
    inline float ScoreCandidate(
        const FVector& InstigatorLocation,
        const FVector& InstigatorForward,
        const FVector& CandidateLocation,
        float DetectionRadius,
        float FacingDotThreshold)
    {
        const FVector ToCandidate = CandidateLocation - InstigatorLocation;
        const float Dist = ToCandidate.Size();

        // 朝向点积（候选与正前方夹角）
        const FVector Dir = Dist > KINDA_SMALL_NUMBER ? (ToCandidate / Dist) : InstigatorForward;
        const float Dot = FVector::DotProduct(InstigatorForward.GetSafeNormal(), Dir);

        if (FacingDotThreshold != 0.f && Dot < FacingDotThreshold)
        {
            return -1.f; // 朝向不满足，剔除
        }

        const float SafeRadius = FMath::Max(DetectionRadius, KINDA_SMALL_NUMBER);
        const float DistScore = FMath::Clamp(1.f - Dist / SafeRadius, 0.f, 1.f);
        const float FacingScore = (Dot + 1.f) * 0.5f; // [-1,1] → [0,1]

        return 0.7f * DistScore + 0.3f * FacingScore;
    }
}
```

- [ ] **Step 4: 编译并运行测试**

Run: 通用编译命令，然后自动化测试运行命令
Expected: 编译 `Build succeeded`；测试 log 含 `GameplayProject.Interaction.Scoring` 且 `Result={Success}`。

- [ ] **Step 5: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/Public/Interaction/InteractionScoring.h Source/GameplayProject/Private/Interaction/InteractionScoringTest.cpp
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add candidate scoring fn with automation test"
```

---

## Task 4: UInteractionComponent 骨架

**Files:**
- Create: `Source/GameplayProject/Public/Interaction/InteractionComponent.h`
- Create: `Source/GameplayProject/Private/Interaction/InteractionComponent.cpp`

本任务只搭骨架：构造、BeginPlay 创建 Sphere + 启 Timer、EndPlay 清理、空的扫描函数。检测/选择逻辑放 Task 5。

- [ ] **Step 1: 写组件头文件**

```cpp
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
```

- [ ] **Step 2: 写组件实现（骨架）**

```cpp
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
```

- [ ] **Step 3: 编译验证**

Run: 通用编译命令
Expected: `Build succeeded`

- [ ] **Step 4: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/Public/Interaction/InteractionComponent.h Source/GameplayProject/Private/Interaction/InteractionComponent.cpp
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add InteractionComponent skeleton (sphere + timer)"
```

---

## Task 5: 组件检测与目标选择逻辑

**Files:**
- Modify: `Source/GameplayProject/Private/Interaction/InteractionComponent.cpp`（替换 Task 4 的空实现）

- [ ] **Step 1: 替换 6 个函数的实现**

把 Task 4 Step 2 中标记 `// 以下在 Task 5 填充实现` 的 7 个空实现行整体替换为：

```cpp
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
```

- [ ] **Step 2: 编译验证**

Run: 通用编译命令
Expected: `Build succeeded`

- [ ] **Step 3: 复跑评分单测确认未回归**

Run: 自动化测试运行命令
Expected: `GameplayProject.Interaction.Scoring` 仍 `Result={Success}`。

- [ ] **Step 4: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/Private/Interaction/InteractionComponent.cpp
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): implement detection, scoring select, TryInteract"
```

---

## Task 6: APickupActor C++ 基类

**Files:**
- Create: `Source/GameplayProject/Public/Interaction/PickupActor.h`
- Create: `Source/GameplayProject/Private/Interaction/PickupActor.cpp`

依赖已核实的 Inventory API：`int32 UInventoryComponent::AddItem(FName, int32, bool, int32)` 返回实际入库数。

- [ ] **Step 1: 写头文件**

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/Interactable.h"
#include "Interaction/InteractionTypes.h"
#include "PickupActor.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class GAMEPLAYPROJECT_API APickupActor : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    APickupActor();

    // Inventory 数据键（对应 UItemDefinition::ItemDataMap 的 key）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    FName ItemID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    int32 Quantity = 1;

    // 策划直接填提示文字；为空时回退通用文案
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    FInteractionPrompt PromptOverride;

    // IInteractable
    virtual FInteractionPrompt GetInteractionPrompt_Implementation() const override;
    virtual void OnInteract_Implementation(AActor* Instigator) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    TObjectPtr<UStaticMeshComponent> Mesh;
};
```

- [ ] **Step 2: 写实现**

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction/PickupActor.h"
#include "Components/StaticMeshComponent.h"
#include "Inventory/InventoryComponent.h"
#include "GameplayProjectCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogPickup, Log, All);

APickupActor::APickupActor()
{
    PrimaryActorTick.bCanEverTick = false;
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    // 让 InteractionComponent 的球能 overlap 到：设为 WorldDynamic 且产生 overlap
    Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    Mesh->SetCollisionObjectType(ECC_WorldDynamic);
    Mesh->SetGenerateOverlapEvents(true);
}

FInteractionPrompt APickupActor::GetInteractionPrompt_Implementation() const
{
    if (!PromptOverride.Text.IsEmpty())
    {
        return PromptOverride;
    }
    FInteractionPrompt Fallback = PromptOverride;
    Fallback.Text = FText::FromString(TEXT("[E] 拾取"));
    return Fallback;
}

void APickupActor::OnInteract_Implementation(AActor* Instigator)
{
    AGameplayProjectCharacter* Char = Cast<AGameplayProjectCharacter>(Instigator);
    if (!Char)
    {
        UE_LOG(LogPickup, Verbose, TEXT("Pickup: Instigator 不是角色"));
        return;
    }
    UInventoryComponent* Inv = Char->FindComponentByClass<UInventoryComponent>();
    if (!Inv)
    {
        UE_LOG(LogPickup, Warning, TEXT("Pickup: 角色无 InventoryComponent"));
        return;
    }

    const int32 Added = Inv->AddItem(ItemID, Quantity);
    if (Added >= Quantity)
    {
        Destroy();
    }
    else if (Added > 0)
    {
        Quantity -= Added; // 部分入库，剩余留在场上
        UE_LOG(LogPickup, Verbose, TEXT("Pickup: 部分入库 %d，剩余 %d"), Added, Quantity);
    }
    else
    {
        UE_LOG(LogPickup, Verbose, TEXT("Pickup: 库存已满，未入库"));
    }
}
```

- [ ] **Step 3: 编译验证**

Run: 通用编译命令
Expected: `Build succeeded`

> 若报 `AGameplayProjectCharacter` 不完整类型，确认 `GameplayProjectCharacter.h` 路径正确（位于模块根，include 写 `"GameplayProjectCharacter.h"`，Build.cs 已含 `PublicIncludePaths "GameplayProject"`）。

- [ ] **Step 4: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/Public/Interaction/PickupActor.h Source/GameplayProject/Private/Interaction/PickupActor.cpp
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add APickupActor base implementing IInteractable"
```

---

## Task 7: 角色挂载 InteractionComponent

**Files:**
- Modify: `Source/GameplayProject/GameplayProjectCharacter.h`
- Modify: `Source/GameplayProject/GameplayProjectCharacter.cpp`

- [ ] **Step 1: 头文件加 include 与成员**

在 `GameplayProjectCharacter.h` 的 include 区（已有 `#include "Conversation/ConversationComponent.h"` 之后）加：

```cpp
#include "Interaction/InteractionComponent.h"
```

在 `AbilitySystemComponent` / `InventoryComponent` 等成员附近，public 区加：

```cpp
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	TObjectPtr<UInteractionComponent> InteractionComponent;
```

- [ ] **Step 2: 构造函数创建子对象**

在 `GameplayProjectCharacter.cpp` 构造函数中，紧接现有这行之后：

```cpp
	ConversationComponent = CreateDefaultSubobject<UConversationComponent>(TEXT("Conversation"));
```

新增一行：

```cpp
	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("Interaction"));
```

- [ ] **Step 3: 编译验证**

Run: 通用编译命令
Expected: `Build succeeded`

- [ ] **Step 4: 提交**

```
git -C "D:\SoftWare\Project\GP" add Source/GameplayProject/GameplayProjectCharacter.h Source/GameplayProject/GameplayProjectCharacter.cpp
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): attach InteractionComponent to character"
```

---

## Task 8: 输入资产 IA_Interact（编辑器手动）

**Files:**
- Create: `Content/Input/Actions/IA_Interact`（InputAction 资产）
- Modify: 现有玩家 IMC（Input Mapping Context）
- Modify: 角色 BP（`BP_ALSCharacter` 或工程实际角色 BP）的 EventGraph

- [ ] **Step 1: 创建 InputAction**

编辑器 Content Browser → `Content/Input/Actions/` 右键 → Input → Input Action，命名 `IA_Interact`，`Value Type = Digital (bool)`。

- [ ] **Step 2: 绑按键到 IMC**

打开工程现有 IMC（参考 `Config/DefaultInput.ini` 或现有跳跃/瞄准所在的 IMC），添加 Mapping：`IA_Interact` ← `E` 键。

- [ ] **Step 3: 角色 BP 接线**

打开角色 BP EventGraph：
- 加 `EnhancedInputAction IA_Interact` 节点
- 从其 `Triggered` 引脚 → `Self → InteractionComponent` (Get) → `Try Interact`

- [ ] **Step 4: 编译角色 BP，保存**

编辑器中 Compile + Save。无报错即可。

- [ ] **Step 5: 提交**

```
git -C "D:\SoftWare\Project\GP" add Content/Input Content/<角色BP路径>
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add IA_Interact input wired to TryInteract"
```

---

## Task 9: 提示 UI —— WBP_InteractionPrompt（编辑器手动）

**Files:**
- Create: `Content/Widget/WBP_InteractionPrompt`（Widget Blueprint）
- Modify: 角色 BP（BeginPlay 创建并 AddToViewport）

- [ ] **Step 1: 创建 Widget**

Content/Widget 右键 → User Interface → Widget Blueprint，命名 `WBP_InteractionPrompt`。Widget 树：

```
Canvas Panel
  └─ HorizontalBox  (Anchor: Bottom-Center, Position Y: -150, Alignment 0.5/0.5)
       ├─ Image      (命名 IconImage, 32×32, Visibility=Collapsed)
       └─ TextBlock  (命名 PromptText, 字号 24)
```

- [ ] **Step 2: 加变量**

新增变量 `OwnerInteractionComponent`，类型 `Interaction Component (Object Reference)`，勾选 `Instance Editable` + `Expose on Spawn`。

- [ ] **Step 3: Construct 绑定委托**

`Event Construct`：
- `IsValid(OwnerInteractionComponent)` → True 分支
- `Bind Event to On Target Changed`（红色委托引脚），事件接 `HandlePromptChanged`
- 调一次 `HandlePromptChanged`，传入一个 `Make FInteractionPrompt`（bEnabled=false）以初始化为隐藏

- [ ] **Step 4: HandlePromptChanged 自定义事件**

新建 Custom Event `HandlePromptChanged`，入参 `Prompt (FInteractionPrompt)`：
- `Break FInteractionPrompt`
- `Branch(bEnabled)`：
  - False → `Self SetVisibility(Collapsed)` → return
  - True  → `Self SetVisibility(Visible)`；`PromptText → SetText(Text)`；
    `IsValid(Icon)` ? `IconImage SetBrushFromTexture(Icon)` + `SetVisibility(Visible)` : `IconImage SetVisibility(Collapsed)`

- [ ] **Step 5: Destruct 解绑**

`Event Destruct` → `Unbind Event from On Target Changed`（同一委托）。

- [ ] **Step 6: 角色 BP 生成 Widget**

角色 BP `Event BeginPlay`：
- `IsLocallyControlled` → True
- `Create Widget(Class=WBP_InteractionPrompt, OwningPlayer=自身Controller, OwnerInteractionComponent=Self.InteractionComponent)`
- `Add to Viewport(ZOrder=10)`

- [ ] **Step 7: 编译保存两个 BP**

- [ ] **Step 8: 提交**

```
git -C "D:\SoftWare\Project\GP" add Content/Widget/WBP_InteractionPrompt.uasset Content/<角色BP路径>
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add WBP_InteractionPrompt UI bound to OnTargetChanged"
```

---

## Task 10: 业务派生资产（编辑器手动）

**Files:**
- Create: `Content/Interaction/BP_Pickup_Sample`（继承 APickupActor）
- Modify: 现有 NPC BP（加 Interactable 接口）

依赖已核实的 Conversation API：`bool StartConversation(const FString& DialogueTreeID, const FName& StartNodeID = NAME_None)` / `bool StartDefaultConversation(...)` / `bool IsInConversation() const`。

- [ ] **Step 1: 创建 Pickup 派生 BP**

Content 右键 → Blueprint Class → 搜 `PickupActor` 作父类，命名 `BP_Pickup_Sample`。Detail 面板配：
- `Mesh` 选一个 StaticMesh
- `ItemID` 填一个 Inventory `ItemDataMap` 中存在的 key（参照工程 ItemDefinition 数据资产）
- `Quantity` = 1
- `PromptOverride.Text` = "[E] 拾取苹果"

放一个实例到测试关卡。

- [ ] **Step 2: NPC 加接口**

打开现有 NPC BP → Class Settings → Interfaces → Add `Interactable`：
- Override `GetInteractionPrompt`：`Make FInteractionPrompt`（Text="[E] 交谈"，bEnabled = `NOT IsInConversation()` 的结果，经 ConversationComponent 取），Return
- Override `OnInteract`：`Self → Get Component by Class(ConversationComponent) → StartConversation(DialogueTreeID=<工程对话树ID字符串>)`（或 `StartDefaultConversation`）

- [ ] **Step 3: 编译保存**

- [ ] **Step 4: 提交**

```
git -C "D:\SoftWare\Project\GP" add Content/Interaction Content/<NPC BP路径>
git -C "D:\SoftWare\Project\GP" commit -m "feat(interaction): add sample pickup BP and NPC interactable wiring"
```

---

## Task 11: 运行时验证（PIE）

**Files:** 无（验收）

按 spec §9 清单逐条在 PIE 验证：

- [ ] **1. 走近 Pickup** → 屏幕下方出现 "[E] 拾取苹果"；走开 → 提示消失
- [ ] **2. 按 E** → 物品进库存（库存 UI 数量 +1）→ Pickup Actor 从场景消失
- [ ] **3. 库存满按 E** → Pickup 不消失，Output Log 出现 `LogPickup: ... 库存已满`
- [ ] **4. 走近 NPC** → "[E] 交谈" → 按 E → 对话启动（`IsInConversation()` 变 true）
- [ ] **5. 两个 Pickup 同时在范围** → 提示只显示更近/更正对者；移动 → 切换
- [ ] **6. 拾取后立刻再按 E**（目标已 Destroy）→ 不崩溃，无提示
- [ ] **7. 把某交互物 PromptOverride.bEnabled=false** → 进范围不亮提示

- [ ] **验收门槛**：7 条全过 + Task 3 评分单测通过。全过后在 plan 顶部记录完成日期。

---

## 自检记录（writing-plans self-review）

- **Spec 覆盖**：§3 架构→Task1-7；§4 数据/接口→Task1-2；§5 组件→Task4-5；§6 业务→Task6-7、Task10；§7 UI→Task9；§8 边界（满库存/Destroy/非角色/无组件）→Task5-6 实现含 + Task11 验证；§9 测试→Task3 单测 + Task11 清单。输入接线（§6.3）→Task8。
- **类型一致**：`ScoreCandidate`、`OnTargetChanged`、`TryInteract`、`GetInteractionPrompt`/`OnInteract`、`FInteractionPrompt{Text,Icon,bEnabled}`、`AddItem(返回int32)`、`StartConversation(FString,FName)` 全计划统一。
- **无 placeholder**：每个 C++ 步骤含完整代码；编辑器步骤含具体节点路径。`<角色BP路径>`/`<NPC BP路径>`/`<对话树ID>` 是工程现存资产，实现期由执行者按实际填入（非代码占位）。
