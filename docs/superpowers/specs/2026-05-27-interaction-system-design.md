# 交互系统（Interaction System）设计

> 起始日期：2026-05-27
> 目标：为 GP 项目（UE 5.6 单人、GAS + ALS）设计一套轻量交互系统，支持「走近自动提示 + 按键确认」两类交互：物品拾取（接现有 Inventory）和 NPC 对话触发（接现有 Conversation）。
> 选型背景：基于 `Interaction` 调研（TBIA 重框架 vs Lyra 轻框架）。GP 当前规模采用 **Lyra「极简接口」哲学**（2 虚函数 + 数据 struct），但不引入 Lyra 的 GAS Tag 触发与 IndicatorSystem 等专有栈。

---

## 1. 需求确认

| 项 | 结论 |
|----|------|
| 交互场景 | Pickup 拾取（物品/弹药/钥匙）+ NPC 对话触发（接现有 Conversation） |
| 触发模型 | 走近自动提示（Sphere Overlap）+ 按键确认 |
| 交互执行 | 接口直调，业务组件自处理（**不**走 GAS Ability） |
| 多选项 | 单选项即可（一个 Target 一个 Interact 动作） |
| 网络 | 单人项目，无多人同步需求 |
| 动画对齐 | 不需要（无 TBIA 多 Mesh Montage / MoveToPosition 需求） |
| 配置者 | 策划在 BP 配数据；框架逻辑在 C++ |

## 2. 选型决策（呼应调研）

- **采纳** Lyra「2 虚函数 + 数据 struct」极简接口哲学
- **不采纳** TBIA 23 虚函数（GP 完全不需要）
- **不采纳** TBIA 多 Mesh Montage / MoveToPosition（无动画对齐场景）
- **不采纳** Lyra GAS Tag 触发链（按需求选直调）
- **不采纳** Lyra Indicator 3D→2D 投影（单人项目，屏幕固定位置提示足够）
- **预留** GAS 升级锚点（`FInteractionPrompt` struct 扩展位）：未来需要「带角色动画的交互」时再加，零当前成本

## 3. 架构总览

```
AGameplayProjectCharacter
  ├─ InventoryComponent    （已有）
  ├─ ConversationComponent （已有）
  └─ InteractionComponent  ★ 新增
        ├─ USphereComponent           半径默认 250cm
        ├─ TArray<TWeakObjectPtr<AActor>> Candidates
        ├─ TWeakObjectPtr<AActor>     CurrentTargetActor
        ├─ Timer(0.1s) → 评分选最佳 → 广播 OnTargetChanged
        └─ TryInteract()             供 Enhanced Input 调用

接口层：IInteractable (C++ UINTERFACE)
  ├─ GetInteractionPrompt() → FInteractionPrompt
  └─ OnInteract(AActor* Instigator)

数据：FInteractionPrompt (USTRUCT, BlueprintType)
  ├─ FText  Text
  ├─ UTexture2D* Icon (可空)
  └─ bool   bEnabled

业务接入（实现 IInteractable）：
  ├─ APickupActor       C++ 基类 + BP 派生配置 ItemDef
  └─ BP_InteractableNPC 纯 BP 实现，OnInteract → ConversationComponent.StartConversation

UI：
  └─ WBP_InteractionPrompt  屏幕中下方，绑 OnTargetChanged
```

**职责边界**：
- `InteractionComponent`：只负责「发现 / 评分 / 路由」，不知道 Inventory / Conversation 存在。
- `IInteractable` 实现者：自己知道「被交互时该做什么」，调对应业务组件。
- `WBP_InteractionPrompt`：纯被动展示，只读组件委托数据。

新增交互类型（开门、Use Switch）= 新增 Actor + 实现 `IInteractable`，框架代码零改动。

## 4. 核心数据结构

### 4.1 FInteractionPrompt

```cpp
USTRUCT(BlueprintType)
struct FInteractionPrompt
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Text;                              // "[E] 拾取苹果"

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UTexture2D> Icon = nullptr;   // 可空，UI 容错

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnabled = true;                    // false 时被检测到也不显示
};
```

### 4.2 IInteractable

```cpp
UINTERFACE(MinimalAPI, BlueprintType, meta = (CannotImplementInterfaceInBlueprint = "false"))
class UInteractable : public UInterface { GENERATED_BODY() };

class GAMEPLAYPROJECT_API IInteractable
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    FInteractionPrompt GetInteractionPrompt() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnInteract(AActor* Instigator);
};
```

**设计决策**：
- `BlueprintNativeEvent`：C++ 基类可写默认实现，BP 派生可 override——对齐 GP 现有 `APickupActor` 子类模式。
- `CannotImplementInterfaceInBlueprint = false`：允许纯 BP Actor（NPC）实现接口，策划无需 C++。
- `FInteractionPrompt` 作为单一返回值——未来加字段不破签名。
- 不设 `IsAvailable / IsBlocked` 等额外回调（避免 TBIA 23 函数的坑）：`bEnabled = false` 一字段够用。
- 不返回 `TArray`（多选项）——单选明确；未来要多选再加 `GatherOptions` 方法，不影响现有 Actor。

## 5. UInteractionComponent

### 5.1 头文件骨架

```cpp
UCLASS(ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent))
class GAMEPLAYPROJECT_API UInteractionComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UInteractionComponent();

    UPROPERTY(EditAnywhere, Category="Interaction")
    float DetectionRadius = 250.f;          // Sphere 半径，cm

    UPROPERTY(EditAnywhere, Category="Interaction")
    float ScanInterval = 0.1f;              // 节流刷新

    UPROPERTY(EditAnywhere, Category="Interaction")
    float FacingDotThreshold = 0.f;         // 0 = 不过滤朝向

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionTargetChanged, const FInteractionPrompt&, Prompt);
    UPROPERTY(BlueprintAssignable, Category="Interaction")
    FOnInteractionTargetChanged OnTargetChanged;   // Prompt.bEnabled=false 表示无 Target

    UFUNCTION(BlueprintCallable, Category="Interaction")
    bool TryInteract();

    UFUNCTION(BlueprintPure, Category="Interaction")
    AActor* GetCurrentTargetActor() const;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;

private:
    UPROPERTY() TObjectPtr<USphereComponent> DetectionSphere;
    UPROPERTY() TArray<TWeakObjectPtr<AActor>> Candidates;
    UPROPERTY() TWeakObjectPtr<AActor> CurrentTargetActor;
    FTimerHandle ScanTimerHandle;

    UFUNCTION() void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult& Sweep);
    UFUNCTION() void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 BodyIndex);

    void ScanAndUpdateTarget();
    AActor* PickBestCandidate() const;
    void SetCurrentTarget(AActor* NewTarget);
};
```

### 5.2 核心算法

1. **BeginPlay**：动态创建 `USphereComponent` 附到 Owner 根（碰撞预设响应 `WorldDynamic + Pawn` 的 Overlap），半径 = `DetectionRadius`，绑 Begin/End Overlap，启 Timer `SetTimer(ScanTimerHandle, ScanAndUpdateTarget, ScanInterval, true)`。
2. **OnSphereBeginOverlap**：`if Other->Implements<UInteractable>() → Candidates.Add(Other)`。
3. **OnSphereEndOverlap**：`Candidates.RemoveSwap(Other)`；若 `Other == CurrentTargetActor` 立即重选。
4. **ScanAndUpdateTarget**（每 `ScanInterval`）：清理失效 WeakPtr → `PickBestCandidate()` → 与 `CurrentTargetActor` 比较 → 不同则 `SetCurrentTarget(New)`。
5. **PickBestCandidate**：
   - 跳过 `GetInteractionPrompt().bEnabled == false` 的候选。
   - 评分 = 距离权重 70% + 朝向点积权重 30%；`FacingDotThreshold != 0` 时小于阈值的剔除。
   - 评分越高越优；同分取距离更近。
6. **SetCurrentTarget**：更新 `CurrentTargetActor`，广播 `OnTargetChanged(NewPrompt)`；无 Target 时广播 `bEnabled=false` 的空 Prompt。
7. **TryInteract**：`CurrentTarget` 有效 + `Prompt.bEnabled == true` → 调 `IInteractable::Execute_OnInteract(TargetActor, GetOwner())` → 返回 `true`；否则 `false`。
8. **EndPlay**：清 Timer，解绑 Overlap。

### 5.3 性能与边界

- Timer 而非 `TickComponent`——0.1s 评分够灵敏，避免每帧浪费。
- `TWeakObjectPtr` 容忍 Actor 被销毁不崩溃（Pickup 拾走后 Destroy）。
- Overlap 半径 250cm + 一般场景密度 < 10 个候选，无性能压力，不设硬上限。
- 用 `Implements<UInteractable>()` 检测，对 C++ / BP 实现都兼容。

## 6. 业务接入

### 6.1 Pickup —— APickupActor（C++ 基类）

> **已核实的现有 Inventory API（`InventoryComponent.h` / `ItemDefinition.h`）**：
> - `UItemDefinition` 是数据容器：`TMap<FName, FItemData> ItemDataMap`，**不是单个物品**。物品由 `FName ItemID` 标识。
> - `int32 AddItem(FName ItemID, int32 Quantity, bool bForceToSpecificSlot=false, int32 TargetSlotIndex=-1)`——**返回实际入库数量**（非 bool）。
> - `bool HasEnoughSpace(FName ItemID, int32 Quantity) const`、`bool GetItemData(FName ItemID, FItemData& Out) const`（`FItemData` 含 `DisplayName`、`WorldMesh` 等）。
>
> 因此 Pickup 持有的是 `FName ItemID`，而不是把 `UItemDefinition*` 当单物品用。

```cpp
UCLASS(Blueprintable)
class GAMEPLAYPROJECT_API APickupActor : public AActor, public IInteractable
{
    GENERATED_BODY()
public:
    APickupActor();

    UPROPERTY(EditAnywhere, Category="Pickup")
    FName ItemID;                               // Inventory 数据键（对应 ItemDataMap 的 key）

    UPROPERTY(EditAnywhere, Category="Pickup")
    int32 Quantity = 1;

    UPROPERTY(EditAnywhere, Category="Pickup")
    FInteractionPrompt PromptOverride;          // 策划直接填 "[E] 拾取苹果"

    virtual FInteractionPrompt GetInteractionPrompt_Implementation() const override;
    virtual void OnInteract_Implementation(AActor* Instigator) override;

protected:
    UPROPERTY(VisibleAnywhere) TObjectPtr<UStaticMeshComponent> Mesh;
};
```

- **OnInteract_Implementation**（对齐 `AddItem` 返回 int32 的实际语义）：
  ```cpp
  auto* Char = Cast<AGameplayProjectCharacter>(Instigator);
  if (!Char) return;
  auto* Inv = Char->FindComponentByClass<UInventoryComponent>();
  if (!Inv) return;
  const int32 Added = Inv->AddItem(ItemID, Quantity);   // 返回实际入库数
  if (Added >= Quantity)      { Destroy(); }            // 全部入库 → 销毁
  else if (Added > 0)         { Quantity -= Added; }    // 部分入库 → 剩余留场上
  // Added == 0（库存满）→ 不动，打日志
  ```
- **GetInteractionPrompt_Implementation**：默认返回 `PromptOverride`；若 `Text.IsEmpty()` 回退通用 "[E] 拾取"。（可选 polish：经 `Inv->GetItemData(ItemID)` 取 `DisplayName` 拼出物品名——需 Instigator 的 Inventory，本期不强制。）
- **BP 派生**：`BP_Pickup_Apple` → 改 Mesh + ItemID + Prompt 文本，零图节点。对齐 Inventory 模块「C++ 提供能力，BP 配数据」风格。ItemID 的选择体验可参照已有 `2026-05-21-conversation-rowname-dropdown-design.md` 的下拉思路（本期可先用裸 `FName`）。

### 6.2 NPC —— BP_InteractableNPC（纯 BP）

> **已核实的现有 Conversation API（`ConversationComponent.h`）**：
> - `bool StartConversation(const FString& DialogueTreeID, const FName& StartNodeID = NAME_None)`
> - `bool StartDefaultConversation(const FName& StartNodeID = NAME_None)`
> - `bool IsInConversation() const`（可用于 `bEnabled` 判断，对话中不再提示）

策划在已有 NPC BP 上：
1. Class Settings → Interfaces → Add `Interactable`。
2. Override `GetInteractionPrompt` → Make `FInteractionPrompt`，Text="[E] 交谈"；可选用 `IsInConversation()==true` 时令 `bEnabled=false`。
3. Override `OnInteract`：`Self → Get Component by Class (ConversationComponent) → StartConversation(DialogueTreeID)`（或 `StartDefaultConversation()`）。`DialogueTreeID` 是 `FString`，策划在 NPC BP 上配。

不写 C++ NPC 基类——NPC 行为多样（巡逻、AI），强加基类容易绑死；接口实现走 BP 更灵活。

### 6.3 角色侧接线 —— AGameplayProjectCharacter

- **唯一 C++ 改动**：构造函数加 `CreateDefaultSubobject<UInteractionComponent>(TEXT("InteractionComponent"))`，暴露 `BlueprintReadOnly`。
- **输入**（沿用项目 Enhanced Input）：新增 `IA_Interact`，角色 BP 监听 `IA_Interact (Triggered)` → 调 `InteractionComponent.TryInteract`。不走 GAS Ability。

## 7. UI —— WBP_InteractionPrompt

**结构**：
```
WBP_InteractionPrompt (UserWidget)
  └─ Canvas Panel
       └─ HorizontalBox  Anchor: Bottom-Center, Y Offset: -150
            ├─ Image       (IconImage,  32×32, Collapsed by default)
            └─ TextBlock   (PromptText, 字号 24, 描边)

Variables:
  └─ OwnerInteractionComponent : UInteractionComponent*  (ExposeOnSpawn)
```

**事件接线**：

| 事件 | 行为 |
|------|------|
| `Event Construct` | `IsValid(OwnerInteractionComponent)` → Bind `OnTargetChanged` → `HandlePromptChanged`；并手动调一次空 Prompt 保证初始隐藏 |
| `HandlePromptChanged(Prompt)` | `if !Prompt.bEnabled → Collapsed; return`；否则 `Visible` + `PromptText.SetText`；`Icon` 有则 `SetBrushFromTexture + Visible`，否则 Collapsed |
| `Event Destruct` | Unbind 委托 |

**生成方式（角色 BP）**：
```
Event BeginPlay
  ├─ IsLocallyControlled → True
  └─ CreateWidget(WBP_InteractionPrompt, OwnerInteractionComponent=Self.InteractionComponent)
       └─ AddToViewport(ZOrder=10)
```

和库存 widget 同形（参见 `2026-05-25-inventory-widget-wiring-guide.md`），策划已熟悉。

**设计点**：
- 屏幕中下方固定位置而非 3D 跟随：单玩家、单选项场景下比 Lyra `SActorCanvas` 投影更简洁；未来要跟随再加 3D widget。
- `bEnabled=false` 一统隐藏路径：无 Target / 暂不可用 都走该字段，UI 不分支。
- `ExposeOnSpawn`：组件指针走 `CreateWidget` 入参传入，避免 UI 反查角色。

## 8. 错误处理 / 边界条件

| 场景 | 处理 |
|------|------|
| Target 在范围内被销毁（拾走） | WeakPtr 失效，扫描清理 + 重选 + 广播新/空 Prompt |
| Instigator 不是 Character | Cast 失败 → return，不崩 |
| Inventory 满（AddItem 返回 false） | Pickup **不** Destroy，物品留场上；打日志（本期不做失败 UI） |
| NPC 缺 ConversationComponent | BP `IsValid` 分支保护，空转 |
| 多个候选 | 评分唯一选最佳；同分取最近；都不行则无 Target |
| ItemDef 未配 | Prompt 回退默认文字；OnInteract 检 null 后 return |
| 快速进出范围 | Begin/End Overlap + 0.1s 节流，无闪烁 |
| 交互中目标移出范围 | 本期交互瞬时（直调），无「进行中」状态，无需打断 |

**日志**：新增 `LogInteraction` 类目，在 `SetCurrentTarget` / `TryInteract` 失败路径打 `Verbose`，便于策划自查「为什么没提示」。

## 9. 测试策略

GP 无自动化测试框架，以运行时验证为主 + 少量 C++ 单元可测点。

**C++ 单元可测点**：
- `PickBestCandidate` 评分函数：模拟候选数组（距离 + 朝向），断言选出预期最佳。
- `FInteractionPrompt` 默认值：`bEnabled=true`、`Icon=null`。

**运行时验证清单（PIE 手动 / MCP）**：
1. 走近 Pickup → 屏幕下方出现 "[E] 拾取苹果" → 走开 → 消失。
2. 按 E → 进库存（库存 UI +1）→ Pickup 消失。
3. 库存满按 E → Pickup 不消失，日志输出 AddItem 失败。
4. 走近 NPC → "[E] 交谈" → 按 E → ConversationComponent 启动对话。
5. 两 Pickup 在范围 → 只显示更近/更正对者 → 移动切换。
6. 拾取后立即按 E（目标已 Destroy）→ 不崩，无提示。
7. `bEnabled=false` 的交互物 → 进范围不亮提示。

**验收门槛**：7 条全过 + `PickBestCandidate` 单测通过。

## 10. 文件清单（实现阶段产出）

| 文件 | 类型 | 说明 |
|------|------|------|
| `Source/GameplayProject/Public/Interaction/Interactable.h` | C++ | `IInteractable` 接口 + `FInteractionPrompt` |
| `Source/GameplayProject/Public/Interaction/InteractionComponent.h` | C++ | 组件头 |
| `Source/GameplayProject/Private/Interaction/InteractionComponent.cpp` | C++ | 组件实现 |
| `Source/GameplayProject/Public/Interaction/PickupActor.h` | C++ | Pickup 基类头 |
| `Source/GameplayProject/Private/Interaction/PickupActor.cpp` | C++ | Pickup 实现 |
| `GameplayProjectCharacter.h/.cpp` | C++ 改动 | 加 InteractionComponent 子对象 |
| `WBP_InteractionPrompt` | BP 资产 | 提示 UI |
| `BP_Pickup_*` | BP 资产 | Pickup 派生（配 ItemID + Mesh + Prompt） |
| `BP_InteractableNPC`（在现有 NPC 上加接口） | BP 改动 | NPC 对话触发 |
| `IA_Interact` + IMC 绑定 | 输入资产 | 交互按键 |

## 11. 未来扩展锚点（YAGNI，当前不做）

- **多选项**：加 `GatherOptions() → TArray<FInteractionPrompt>` + 轮盘 UI。
- **GAS 驱动**：`TryInteract` 先查 `Target->GetInteractionAbility()`，有则 `TryActivateAbilityByClass`。
- **长按交互**：`FInteractionPrompt` 加 `HoldDuration`，组件加进度条逻辑。
- **3D 跟随指示器**：替换屏幕固定 UI 为 Actor 上方 widget。
- **多人同步**：`OnInteract` 改服务器 RPC + GAS NetExecutionPolicy。
