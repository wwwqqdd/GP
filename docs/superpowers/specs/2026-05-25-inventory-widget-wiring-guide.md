# 库存 Widget 事件图接线指南

> 日期：2026-05-25
> 目标：把 `WBP_ItemSlot` 和 `WBP_Inventory` 接到 `UInventoryComponent`，让 UI 显示真实库存数据并随变化刷新。

## 当前已完成（MCP 已写入）

### WBP_ItemSlot
- **变量**：
  - `SlotIndex` (int) — Instance Editable
  - `OwnerInventory` (UInventoryComponent*) — Instance Editable
- **控件树**（你已重新设计）：
  ```
  SizeBox_134 (root)
    Border_142
      ItemButton (Button)
        Overlay_286
          SizeBox_154
            TextBlock_239
          ItemIcon (Image, Fill, Collapsed) ← MCP 新增
          QuantityText (TextBlock, BottomRight, Collapsed) ← MCP 新增
  ```

### WBP_Inventory
- **变量**：
  - `OwnerInventory` (UInventoryComponent*) — Instance Editable, **ExposeOnSpawn**
  - `SlotWidgets` (Array of WBP_ItemSlot)

---

## 第一部分：WBP_ItemSlot 的 Refresh 函数

### 步骤 1 — 创建函数

1. 打开 [WBP_ItemSlot](../../../Content/Widget/WBP_ItemSlot.uasset)
2. 切到 **Graph** 模式（右上角 Designer/Graph 切换）
3. 左侧 **My Blueprint** 面板 → **Functions** → 点 `+` 新建函数 → 命名 `Refresh`
4. 双击 `Refresh` 进入函数图

### 步骤 2 — 拉取槽位数据

在 `Refresh` 函数图里：

```
[Refresh entry] ─exec→ [Branch (IsValid OwnerInventory)]
                              │
                              True
                              ↓
                       [Get Inventory Slot]
                              ↓
                       (返回值 → 拆分结构体)
```

具体操作：
1. 拖出 `Refresh` 节点的 exec 出口
2. 搜 `Is Valid`（蓝色 Pure 节点）→ 入参连 `Get OwnerInventory`
3. `Is Valid` 出口（红色 exec）接 `Branch`
4. `Branch.True` 出口 → 搜 `Get Inventory Slot`（来自 `OwnerInventory`）
   - Target 引脚：拖 `OwnerInventory` 变量连过来
   - Slot Index：拖 `SlotIndex` 变量连过来
5. `Get Inventory Slot` 的 **Return Value (Inventory Slot)** 拖一根线出来，松开后搜 `Break InventorySlot`

### 步骤 3 — 判断槽位是否为空

```
[Break InventorySlot]
  ├ Item (AInventoryItem*) → [IsValid] → Branch
  │                                        ├─True (有 Item)
  │                                        └─False (空槽)
```

1. 从 `Break InventorySlot.Item` 拖出 → 搜 `Is Valid`
2. `Is Valid.exec True` → 接下面的"显示 Item"逻辑
3. `Is Valid.exec False` → 接"隐藏控件"逻辑

### 步骤 4 — 显示 Item（True 分支）

```
─exec→ [Set Brush from Texture] (Target: ItemIcon, Texture: Item.GetIcon())
─exec→ [Set Visibility] (Target: ItemIcon, In Visibility: Visible)
─exec→ [Branch (Item.Quantity > 1)]
         ├─True─→ [Set Text] (QuantityText, "x"+Quantity) → [Set Visibility] (QuantityText, Visible)
         └─False→ [Set Visibility] (QuantityText, Collapsed)
```

具体步骤：

**4a. 设置图标**：
1. 从 Item 引脚拖出 → 搜 `Get Icon` （AInventoryItem 上的方法）
2. 拖出新节点 `Set Brush from Texture`（Image 上的方法，Target 接 `Get ItemIcon`）
   - Texture 引脚 ← `Get Icon` 返回值
3. 连 exec 流：True → Set Brush from Texture

**4b. 显示图标**：
1. 搜 `Set Visibility`（Target: `Get ItemIcon`），In Visibility 选 `Visible`
2. exec 接在 Set Brush 后面

**4c. 数量显示**：
1. 从 Item 拖出 → 搜 `Get` → 找到 `Quantity` 属性（int）
2. 拖出 `> (integer)` 节点 → 左边连 Quantity，右边填 `1`
3. 拖出 `Branch`，Condition ← `>` 结果
4. **True 分支**：
   - 搜 `Format Text` → Format 字段填 `x{0}`，Args[0] 连 Quantity（自动转 Text）
   - 接 `Set Text (Text)` → Target: `Get QuantityText`，In Text: Format Text 输出
   - 接 `Set Visibility` → Target: `Get QuantityText`, In Visibility: `Visible`
5. **False 分支**：
   - `Set Visibility` → Target: `Get QuantityText`, In Visibility: `Collapsed`

### 步骤 5 — 隐藏 Item（False 分支）

```
─exec→ [Set Visibility] (Target: ItemIcon, Visibility: Collapsed)
     → [Set Visibility] (Target: QuantityText, Visibility: Collapsed)
```

简单两个 Set Visibility 节点串起来。

### 步骤 6 — 编译保存

- 顶部点 **Compile** → 应该无错误
- **Save**

---

## 已通过 MCP 完成的内容（截至 2026-05-26 — 方案 A 最终状态）

**注**：用户在 UE 里 Ctrl+Z 撤销了之前的 24-slot 重构。最终采用方案 A — 保留原始 8 个硬编码槽位。

WBP_Inventory 现状：

| 项 | 状态 |
|---|---|
| 原始 `HorizontalBox_111 + 8 WBP_ItemSlot` (包括 Spacers) | ✅ 完整保留 |
| 8 个 WBP_ItemSlot 实例的 `SlotIndex` 默认值（0–7） | ✅ Python 已设 |
| 变量：`OwnerInventory (ExposeOnSpawn)` | ✅ 已添加 |
| `Event Construct → IsValid(OwnerInventory) → InitSlots()` | ✅ 已连 |
| `InitSlots`：链式调用 `WBP_ItemSlot.Refresh()` … `WBP_ItemSlot_7.Refresh()` | ✅ 已连 |
| 每个 Slot 的 `OwnerInventory` 传值（runtime 注入） | ❌ **MCP 做不到，需手动** |
| 绑定 `OnInventoryChanged` 委托 | ❌ **MCP 做不到，需手动** |

## ❌ MCP 局限性说明

经过深度尝试，发现 UE 5.6 的 Python API 对几类 K2Node 不开放：

1. **`K2Node_VariableSet` 的 `VariableReference`** 是 protected 属性，无法从 Python 重定向到外部类的变量。所以无法用 MCP 给 `Slot_i.OwnerInventory` 赋值。
2. **`K2Node_AddDelegate`** 类能加载但 `unreal.new_object` 创建后无法挂到 graph（`UEdGraph::AddNode` 非 UFUNCTION）。
3. **`K2Node_CustomEvent.CreateUserDefinedPin`** 同样未暴露给 Python，无法添加 SlotIndex 参数。
4. **`K2Node_DynamicCast`** 无法构造，Slot 无法 Cast 父级。

这意味着 **OwnerInventory 传值 + 委托绑定** 必须在 UE Designer 里手动接。下面是步骤。

---

## 第二部分：WBP_Inventory 的事件图

### 步骤 1 — 准备：把硬编码的 8 个 ItemSlot 删掉

在 Designer 里：
- 左侧 **Hierarchy** 选中 `HorizontalBox_111` 下所有 `WBP_ItemSlot_*` 和 `Spacer_*`，删除（保留 `HorizontalBox_111`，将作为动态填充的容器）
- 也可以改成 **UniformGridPanel**（容纳更多槽位）：右键 `Border_0` 子项 → Replace With → UniformGridPanel，命名 `SlotGrid`

下面以 `SlotGrid` (UniformGridPanel) 为例。如果你保留 `HorizontalBox_111`，下面节点名替换即可。

### 步骤 2 — Event Construct

```
[Event Construct] ─exec→ [Branch (IsValid OwnerInventory)]
                              │ True
                              ↓
                       [Bind Event to OnInventoryChanged]
                       (Target: OwnerInventory, Event: HandleSlotChanged)
                              ↓
                       [Call InitSlots] (Self)
```

1. 在 EventGraph 右键 → 添加 `Event Construct`（应该已经存在）
2. 拖 `OwnerInventory` 变量 → 拖出 `IsValid` 宏 → Branch
3. True 分支 → 拖 `OwnerInventory` 出来 → 搜 `Bind Event to On Inventory Changed`
   - 红色 Event 引脚 → 右键 → **Create Event** → 命名 `HandleSlotChanged`（自动创建一个 CustomEvent 节点）
4. 接 `Init Slots`（下一步要创建的函数）

### 步骤 3 — 创建 InitSlots 函数

新建函数 `InitSlots`：

```
[InitSlots] ─exec→ [ForLoop (0 to OwnerInventory.InventorySize-1)]
                          │ LoopBody
                          ↓
                   [Create Widget] (Class: WBP_ItemSlot, Owning Player: GetOwningPlayer)
                          ↓ Return Value (slot)
                   [Set SlotIndex] (slot, Index)
                          ↓
                   [Set OwnerInventory] (slot, Self.OwnerInventory)
                          ↓
                   [Add Child] (Target: SlotGrid, Content: slot) ← 注意 UniformGridPanel 需要设置 Slot 的行列
                          ↓
                   [Array Add] (SlotWidgets, slot)
                          ↓
                   [Call Refresh] (slot)
```

详细：

1. 拖 `For Loop`：
   - First Index: `0`
   - Last Index: 从 `Get OwnerInventory` → `Get Inventory Size` → 减 `1`
2. **Loop Body** 出口：
   - `Create Widget`（Class 选 `WBP_ItemSlot`）
     - Owning Player: 拖 `Get Owning Player` 节点（这里要的是 PlayerController）
   - Return Value 拖出 → `Set SlotIndex`，Value 用 ForLoop 的 `Index`
   - 再连 `Set OwnerInventory`，Value 用 Self 的 `OwnerInventory`
   - 拖 `SlotGrid` (or `HorizontalBox_111`) → `Add Child`，Content 连 widget
   - 拖 `SlotWidgets` → `Add` 节点，把 widget 加进数组
   - 最后 `Call Refresh`（在 widget 上调用）

3. **如果用 UniformGridPanel**：
   - Add Child 返回 `UniformGridSlot`，可以从这里 `Set Row` / `Set Column`
   - 简单方案：每行 8 列：`Column = Index % 8`，`Row = Index / 8`
   - 拖 UniformGridSlot → `Set Column` (Index % 8)、`Set Row` (Index / 8)

### 步骤 4 — HandleSlotChanged 事件

`HandleSlotChanged` 是 step 2 自动创建的 CustomEvent，它有 1 个 int 入参（SlotIndex）。

```
[HandleSlotChanged (SlotIndex)] ─exec→ [Branch (SlotWidgets.IsValidIndex(SlotIndex))]
                                              │ True
                                              ↓
                                       [Get SlotWidgets[SlotIndex]]
                                              ↓
                                       [Call Refresh]
```

1. 拖 `SlotWidgets` → `Is Valid Index`（数组方法），Index 连 SlotIndex
2. 拖 `Branch`，Condition 接 IsValidIndex
3. True 出口 → `Get` 数组项（Index = SlotIndex）→ 拖出 `Refresh`（前面在 WBP_ItemSlot 里创建的函数）

### 步骤 5 — Event Destruct (清理)

可选但推荐：避免重复绑定。

```
[Event Destruct] ─exec→ [Unbind Event from OnInventoryChanged]
                       (Target: OwnerInventory, Event: HandleSlotChanged)
```

### 步骤 6 — 编译保存

- Compile，无错误后 Save

---

## 第二部分增补：你需要在 UE 里手动接的 2 件事

MCP 已经把 `Event Construct → IsValid → InitSlots()` 和 `InitSlots` 内的 24 个 `Slot_i.Refresh()` 链都接好了。但缺这两块：

### 2A. 给每个 Slot 注入 OwnerInventory（必做）

不接这一步，Slots 会因为 `OwnerInventory == null` 全部静默退出，UI 不显示任何物品。

**操作步骤** — 在 `InitSlots` 函数图里，每条 `Refresh` 链旁加一个 `Set OwnerInventory`：

1. 打开 [WBP_Inventory](../../../Content/Widget/WBP_Inventory.uasset) → **Functions** → 双击 `InitSlots`
2. 你会看到 8 条 Refresh 链，每条形如：`Get WBP_ItemSlot_N → Refresh`
3. **对每条链（8 次）**：
   - 选中链上的 `Get WBP_ItemSlot_N` 节点，**Alt+拖动**复制一份（或在空白处再拖一个出来）
   - 从这个 Get 节点的输出引脚 **拖一根线** → 在弹出菜单里搜 `Set Owner Inventory` → 选 **"SET Owner Inventory (Target is WBP Item Slot)"**（注意要选有 "Target is WBP Item Slot" 字样的那个）
   - 从蓝图左侧 **Variables → OwnerInventory** 拖一个 Get 出来 → 连到这个 Set 节点的 `Owner Inventory` 输入
   - 把新的 Set 节点串到 exec 链里：原本是 `prev.then → Refresh.execute`，改成 `prev.then → Set.execute`、`Set.then → Refresh.execute`

8 个槽位重复 8 次，约 5 分钟。

### 2B. 绑定 OnInventoryChanged 委托（推荐，让 UI 自动刷新）

不接这一步，玩家拾取/丢弃物品后 UI 不会自动更新，需要手动调 Refresh。

1. 切到 `EventGraph`
2. 在 `Call Init Slots` 节点之后：从 **Get OwnerInventory** 拖一根线 → 搜 `Bind Event to On Inventory Changed`
3. 右键 Bind 节点的红色 `Event` 输入引脚 → **Create Event** → 命名 `HandleSlotChanged` → 它会自动创建一个带 `SlotIndex (int)` 参数的 CustomEvent
4. 把 `Init Slots.then` 连到 Bind Event.execute
5. 切到自动创建的 `HandleSlotChanged` CustomEvent：
   - 从 `SlotIndex` 引脚拖出 → 搜 `Select` → 设置 `Option 0..7` 分别返回 `WBP_ItemSlot..WBP_ItemSlot_7` 引用（每个 case 连一个 Get 节点）→ Select 的 Return Value 连到 `Refresh` 调用
   - **或更简单粗暴**：直接调 `InitSlots()` 全量刷新 8 槽（虽然不精准但只 8 个，性能完全可接受）

实测建议：先不绑定委托，让 UI 通过 `InitSlots` 函数手动触发（在玩家拾取物品后调用 `WBP_Inventory.InitSlots()` 即可全量刷新）。这样 MVP 立即可跑。

---

## 第三部分：把 Inventory UI 显示到屏幕上

### 在角色蓝图或 PlayerController 里

通常做法（在 `BP_ALSCharacter` 或 `GameplayProjectCharacter` 子蓝图里）：

```
[Event BeginPlay] ─exec→ [Branch (IsLocallyControlled)]
                              │ True
                              ↓
                       [Create Widget] (Class: WBP_Main 或 WBP_Inventory)
                              ↓
                       [Set OwnerInventory] (Self.InventoryComponent)
                              ↓
                       [Add to Viewport]
```

如果用 `WBP_Inventory` 直接显示：
1. Create Widget → Class: `WBP_Inventory`
   - 因为我们把 `OwnerInventory` 设为 `ExposeOnSpawn`，Create Widget 节点会直接显示一个 `Owner Inventory` 输入引脚
2. 连 `Self.InventoryComponent` 到那个引脚
3. Return Value → `Add to Viewport`

---

## 验证清单

- [ ] WBP_ItemSlot 编译无错误
- [ ] WBP_Inventory 编译无错误
- [ ] Play in Editor，角色蓝图能创建 Widget 并加到屏幕
- [ ] 控制台调 `InventoryComponent.AddItem(ItemID, 1)` → UI 应自动刷新对应槽位
- [ ] `RemoveItem` → 槽位变空
- [ ] 堆叠物品 `AddItem(X, 5)` → 显示 `x5`

---

## 常见坑

1. **`Create Event` 找不到 OnInventoryChanged**：确保用的是 `Bind Event to OnInventoryChanged` 节点（蓝色，从 InventoryComponent 引脚拖），不是 `Add Custom Event`。
2. **`Quantity` 是 int 但 Format Text 期望 Text**：UE 蓝图会自动插一个 `Conv_IntToText`，不用手动加。
3. **Add Child 到 UniformGridPanel 后行列未设置**：默认全堆在 (0,0)。一定要 `Set Row` + `Set Column`。
4. **EventConstruct 里 OwnerInventory 还没赋值**：因为我们用了 `ExposeOnSpawn`，Create Widget 时就传入了，所以 Construct 时已有值。但如果别处用了无参 Create Widget，记得手动 `Set OwnerInventory` 再 Add to Viewport，或者把初始化逻辑放到 `BindToInventory` 函数里手动调用。
5. **OnInventoryChanged 签名不匹配**：从 [InventoryComponent.h](../../../Source/GameplayProject/Public/Inventory/InventoryComponent.h) 看 `FOnInventoryChanged` 的实际 delegate 签名（int32 SlotIndex），HandleSlotChanged 的入参类型要对得上。
