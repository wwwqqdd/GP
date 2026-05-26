# 库存 Widget 接线实施记录

> 起始日期：2026-05-25
> 完成日期：2026-05-26
> 目标：把 `WBP_ItemSlot` 和 `WBP_Inventory` 接到 `UInventoryComponent`，让 UI 显示真实库存并随变化刷新。
> 最终方案：**方案 A — 保留 8 个硬编码槽位**（曾尝试方案 B 动态 24 槽，因 MCP 局限性回退）

---

## 最终架构

```
AGameplayProjectCharacter (BP_ALSCharacter)
  └─ Event BeginPlay
       ├─ InventoryComponent.AddItem(ItemID, N)         先填充数据
       ├─ CreateWidget(WBP_Inventory, OwnerInventory=Self.InventoryComponent)
       └─ AddToViewport

WBP_Inventory
  ├─ Variables: OwnerInventory (UInventoryComponent*, ExposeOnSpawn)
  ├─ Event Construct
  │   ├─ IsValid(OwnerInventory) → True
  │   ├─ InitSlots()                                   初始化 8 个槽位
  │   └─ Bind Event to OnInventoryChanged → HandleSlotChanged   委托绑定（用户手动接）
  ├─ InitSlots (Function)
  │   └─ 8 条链：Get WBP_ItemSlot_N → Init(OwnerInventory, SlotIndex)
  └─ HandleSlotChanged (CustomEvent, int SlotIndex)
      └─ Select 0..7 → 对应 WBP_ItemSlot_N → Refresh()

WBP_ItemSlot
  ├─ Variables: SlotIndex (int, default 0~7), OwnerInventory (UInventoryComponent*)
  ├─ Widget Tree:
  │     SizeBox_134
  │       └─ Border_142
  │           └─ ItemButton
  │               └─ Overlay_286
  │                   ├─ SizeBox_154 → TextBlock_239
  │                   ├─ ItemIcon (Image, Fill, Collapsed by default)
  │                   └─ QuantityText (TextBlock, BottomRight, Collapsed)
  ├─ Init (Macro)        用户自建：SET OwnerInventory + Refresh
  └─ Refresh (Function)
      ├─ IsValid(OwnerInventory) → Branch
      ├─ GetInventorySlot(SlotIndex) → Break InventorySlot
      ├─ IsValid(Item) → Branch
      │   ├─ True：Set Brush from Texture(ItemIcon, Item.GetIcon())
      │   │         + Set Visibility(ItemIcon, Visible)
      │   │         + Quantity>1 ? Set Text(x{Quantity})+Visible : Collapsed
      │   └─ False：Set Visibility(ItemIcon, Collapsed) + (QuantityText, Collapsed)
```

---

## C++ 侧修复（实施过程中发现的 4 个 Bug）

### Bug 1：`UseItem` 短路逻辑错误（NPE 风险）
**文件**：[InventoryComponent.cpp:461](../../../Source/GameplayProject/Private/Inventory/InventoryComponent.cpp#L461)
**原代码**：`if (!IsValid(Item) && !Item->CanUse())` —— `&&` 短路在 Item 为 null 时仍调用 `CanUse()`，崩溃。
**修复**：拆成两个独立分支，先 `IsValid(Item)` 再 `CanUse()`，每个分支单独打 log。

### Bug 2：`CanUse` 冷却误判（永远返回 false）
**文件**：[InventoryItem.cpp:139-149](../../../Source/GameplayProject/Private/Inventory/InventoryItem.cpp#L139-L149)
**原因**：`LastUsedTime` 初始为 0，第一次使用时 `CurrentTime - 0 < UseCooldown` 必为 true，UseItem 永远失败。
**修复**：
```cpp
if (GetWorld() && LastUsedTime > 0.0f)   // 只在用过至少一次后才检查
{
    float CurrentTime = GetWorld()->GetTimeSeconds();
    if (CurrentTime - LastUsedTime < ItemData.UseCooldown) return false;
}
```

### Bug 3：`ApplyConsumableEffect` Instant GE 句柄判断
**文件**：[InventoryComponent.cpp:735-737](../../../Source/GameplayProject/Private/Inventory/InventoryComponent.cpp#L735-L737)
**原因**：`Instant` 类型 GameplayEffect 应用后返回 invalid handle（设计如此，不持久化），原代码用 `EffectHandle.IsValid()` 判断成功，对 Instant GE 永远失败。
**修复**：
```cpp
const bool bIsInstant = DefaultGameplayEffect->DurationPolicy == EGameplayEffectDurationType::Instant;
if (bIsInstant || EffectHandle.IsValid()) { ... return true; }
```

### Bug 4：`RemoveItemFromSlot` 部分扣除时不广播
**文件**：[InventoryComponent.cpp:240-261](../../../Source/GameplayProject/Private/Inventory/InventoryComponent.cpp#L240-L261)
**原因**：原代码只在 `Item->Quantity <= 0` 时通过 `ClearSlot` 广播；当数量减少但 > 0（典型使用场景），不广播 `OnInventoryChanged`，UI 不刷新。
**修复**：
```cpp
if (Item->Quantity <= 0) {
    ClearSlot(SlotIndex);
}
else if (ActualRemoved > 0) {
    OnItemRemoved.Broadcast(RemovedItemID, ActualRemoved);
    NotifyInventoryChanged(SlotIndex);
}
```

---

## 蓝图侧改动（最终落地的接法）

### WBP_ItemSlot

| 项 | 落地状态 | 备注 |
|---|---|---|
| `SlotIndex` (int, Instance Editable) | ✅ | 8 个实例的默认值 0~7 由 Python 设置 |
| `OwnerInventory` (UInventoryComponent*, Instance Editable) | ✅ | runtime 注入，不能在 default 里赋 |
| `ItemIcon` (Image) | ✅ | Fill alignment, 初始 Collapsed |
| `QuantityText` (TextBlock) | ✅ | BottomRight, 初始 Collapsed |
| `Init` Macro（用户自建） | ✅ | 用户在 UE 里手建：入参 `OwnerInventory` → SET self.OwnerInventory → Refresh |
| `Refresh` Function（27 节点） | ✅ | MCP 搭建，包含 `Set Brush from Texture` (bMatchSize=true)、`Conv_IntToText + SetText` |

### WBP_Inventory

| 项 | 落地状态 | 备注 |
|---|---|---|
| `OwnerInventory` (UInventoryComponent*, ExposeOnSpawn) | ✅ | 父端 `Create Widget` 节点会显示参数引脚 |
| 原始 `HorizontalBox_111 + 8 WBP_ItemSlot + Spacers` | ✅ | 保留不动 |
| `Event Construct → IsValid(OwnerInventory) → InitSlots()` | ✅ | MCP 已连 |
| `Bind Event to OnInventoryChanged → Create Event(HandleSlotChanged)` | ✅ | **用户手动接**（MCP 不支持 `K2Node_AddDelegate`） |
| `InitSlots` Function（8 条 `Get Slot_N → Init` 链） | ✅ | 用户改用自建 `Init` macro 一并完成 OwnerInventory 注入 + Refresh |
| `HandleSlotChanged(int SlotIndex)` CustomEvent + Select → Refresh | ✅ | 用户手动接 |

### 玩家角色

在 `BP_ALSCharacter` 的 `Event BeginPlay` 里：
```
BeginPlay
  → InventoryComponent.AddItem(HealthPotion, 5)    先加物品，否则 InitSlots 时槽位还是空
  → CreateWidget(WBP_Inventory, OwnerInventory=Self.InventoryComponent)
  → AddToViewport
```
**关键顺序**：AddItem 必须在 CreateWidget 之前，否则 InitSlots 跑完后槽位仍为空，Icon 不显示。

---

## MCP 局限性总结（UE 5.6 Python API）

经过深度尝试，记录这些通过 `blueprint_add_blueprint_node` 无法完成的操作，供后续参考：

1. **`K2Node_VariableSet.VariableReference`** 是 protected 属性，无法从 Python 重定向到外部类（如 WBP_ItemSlot）的变量。所以无法用 MCP 给 `Slot_i.OwnerInventory` 赋值 —— 需要用户在 UE 里手动接 Set。
2. **`K2Node_AddDelegate`** 类能加载但 `unreal.new_object` 创建后无法挂到 graph（`UEdGraph::AddNode` 非 UFUNCTION）。
3. **`K2Node_CustomEvent.CreateUserDefinedPin`** 未暴露给 Python，无法添加自定义参数（如 SlotIndex）。
4. **`K2Node_DynamicCast`** 无法构造，所以 Slot 不能 Cast 父级（WBP_Inventory）拿 OwnerInventory。
5. **`K2Node_CreateWidget`** 也无法用 MCP 添加。
6. **`K2Node_GetArrayItem`** 同样不支持。

**MCP 支持的节点类型**：CallFunction、Event、CustomEvent（无自定义参数）、CastTo（限定父类的常规继承）、Branch、Sequence、VariableGet、VariableSet（限本类变量）、MacroInstance。

---

## 验证结果

- [x] WBP_ItemSlot 编译无错误
- [x] WBP_Inventory 编译无错误
- [x] Play in Editor，角色 BeginPlay 创建 Widget 并加到屏幕
- [x] `AddItem(HealthPotion, 5)` → InitSlots 后 ItemIcon 立即显示，QuantityText 显示 `x5`
- [x] `UseItem(SlotIndex)` → ApplyConsumableEffect 成功（HP 回复）
- [x] `RemoveItemFromSlot` 部分扣除（5→4）→ 广播 `OnInventoryChanged` → UI 实时刷新 `x5` → `x4`
- [x] 数量减到 0 → ClearSlot → ItemIcon/QuantityText 隐藏

---

## 踩坑记录

1. **WBP_ItemSlot 单根容器**：MCP 无法在 Button 这种单子容器里塞同级 sibling，需用户手动改成 Overlay。
2. **`K2Node_VariableSet` 的 "Set Text" Text 引脚为空** ：Python 创建的 `Set Text` 节点 Text 输入无连接，需替换成 `SetText(FText)` CallFunction + `Conv_IntToText`。
3. **Icon 时序问题**：曾把 AddItem 放在 CreateWidget 之后 → InitSlots 跑时槽位空 → 修正顺序后立刻看到 Icon。
4. **MCP 工具 `blueprint_add_blueprint_node` 的支持矩阵**：见上节 MCP 局限性。
5. **`UseItem` 永远 false**：堆叠 3 个 Bug（CanUse 冷却误判、Instant GE 句柄判断、UseItem 短路逻辑），逐个排查 log → 修复。
6. **UI 数量不更新**：以为是委托绑定问题，实际是 C++ 部分扣除时没广播 —— 用户手动接的委托是对的。
