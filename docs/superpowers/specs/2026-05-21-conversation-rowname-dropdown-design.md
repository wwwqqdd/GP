# Conversation RowName 下拉选择设计

**日期**：2026-05-21
**范围**：为 FConversationNodeData::DefaultNextNodeRowName 和 FConversationBranchOption::TargetNodeRowName 添加 DataTable 行名下拉选择
**目标**：在 DataTable 编辑器中将手动输入的 FName 字段替换为下拉框，数据源为 UConversationSettings 配置的 ConversationDataTable

---

## 1. 问题描述

`DefaultNextNodeRowName` 和 `TargetNodeRowName` 是 FName 类型，编辑时只能手动输入字符串，容易拼写错误且无法发现无效引用。需要在编辑器中提供下拉框列出 DataTable 中所有已有行名。

---

## 2. 方案

使用 UE 的 `IPropertyTypeCustomization` 机制，在 GameplayProjectEditor 模块中为两个结构体注册自定义属性面板。运行时结构体（FName）不变，纯 Editor-side 改动。

---

## 3. 需要修改/创建的文件

| 文件 | 操作 | 说明 |
|------|------|------|
| `Source/GameplayProjectEditor/Private/ConversationNodeDataCustomization.h` | 新建 | FConversationNodeData 属性自定义，替换 DefaultNextNodeRowName 为下拉框 |
| `Source/GameplayProjectEditor/Private/ConversationNodeDataCustomization.cpp` | 新建 | 实现：从 ConversationSettings 读取 DataTable 行名，构建 SSearchableComboBox |
| `Source/GameplayProjectEditor/Private/ConversationBranchOptionCustomization.h` | 新建 | FConversationBranchOption 属性自定义，替换 TargetNodeRowName 为下拉框 |
| `Source/GameplayProjectEditor/Private/ConversationBranchOptionCustomization.cpp` | 新建 | 同上逻辑 |
| `Source/GameplayProjectEditor/Private/GameplayProjectEditor.cpp` | 修改 | StartupModule 注册两个自定义，ShutdownModule 注销 |
| `Source/GameplayProjectEditor/GameplayProjectEditor.Build.cs` | 修改 | 添加 GameplayProject、PropertyEditor、UnrealEd 依赖 |

---

## 4. 实现细节

### 4.1 行名数据源

两个 Customization 类共享同一获取逻辑：

```cpp
TArray<FName> GetConversationRowNames()
{
    const UConversationSettings* Settings = GetDefault<UConversationSettings>();
    UDataTable* DT = Settings ? Settings->GetConversationDataTable() : nullptr;
    if (!DT) return {};
    return DT->GetRowNames();
}
```

### 4.2 Customization 结构

每个 Customization 类只自定义目标 FName 属性，其余属性保持默认渲染（通过 `IDetailChildrenBuilder::GenerateStructValueWidget` 或逐属性添加）。

自定义的 FName 属性渲染为 `SSearchableComboBox`（支持搜索过滤），选中项写回 FName 属性 handle。

### 4.3 模块注册

```cpp
void FGameplayProjectEditorModule::StartupModule()
{
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    PropertyModule.RegisterCustomPropertyTypeLayout(
        "ConversationNodeData",
        FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FConversationNodeDataCustomization::MakeInstance));
    PropertyModule.RegisterCustomPropertyTypeLayout(
        "ConversationBranchOption",
        FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FConversationBranchOptionCustomization::MakeInstance));
}
```
