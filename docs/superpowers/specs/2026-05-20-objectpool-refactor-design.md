# ObjectPool 统一重构设计

**日期**：2026-05-20
**范围**：全面重构 ObjectPoolManager、PoolableInterface 以及 InventoryComponent 的对象池集成
**目标**：统一双池架构，增加线程安全、INI 配置和扩展生命周期回调

---

## 1. 问题描述

当前实现采用双池架构：
- **全局 `UObjectPoolManager`**（单例）— 泛型模板实现，但实际上没有任何调用者使用
- **`UInventoryComponent` 本地池** — 类型专用，独立于全局管理器运行

这导致了：重复池化浪费内存、配置不一致（全局最大值=20，本地最大值=10）、生命周期回调顺序不一致、参数硬编码、无线程安全、无法扩展新对象类型。

其他问题：
- `SplitItem()` 完全绕过对象池（直接调用 `SpawnActor`）
- `PreallocateObjects()` 存在但从未被调用
- `PendingDestroyItems` 队列从未被填充
- 单例跨关卡持久化导致过期引用
- 归还时 `OnPooled` 在 `Reset` 之前调用，但获取时 `Reset` 在 `OnUnpooled` 之前调用（不对称）

---

## 2. 核心数据结构

### 2.1 FPoolTypeConfig

每类型配置，从 INI 加载并支持运行时覆盖。

```cpp
USTRUCT()
struct FPoolTypeConfig
{
    GENERATED_BODY()

    UPROPERTY(Config)
    int32 MaxPoolSize = 20;

    UPROPERTY(Config)
    float CleanupInterval = 30.0f;
};
```

### 2.2 FObjectPoolBucket

每类型存储单元。每个 Bucket 拥有自己的数据、锁和配置。

```cpp
struct FObjectPoolBucket
{
    TArray<UObject*> PooledObjects;     // 空闲对象，可供复用
    TSet<UObject*> ActiveObjects;       // 当前使用中的对象
    FCriticalSection Lock;              // 每 Bucket 独立锁，保证线程安全
    FPoolTypeConfig Config;             // 该类型的配置
    double LastCleanupTime = 0.0;       // 上次清理的时间戳

    // 轻量级统计
    int32 TotalAllocations = 0;         // Acquire 调用总次数
    int32 TotalReuses = 0;             // 从池中复用对象的次数
};

// GetPoolStatistics 返回的统计快照
USTRUCT(BlueprintType)
struct FPoolStatistics
{
    GENERATED_BODY()

    int32 PooledCount = 0;         // 当前池中空闲对象数
    int32 ActiveCount = 0;         // 当前使用中的对象数
    int32 TotalAllocations = 0;    // 生命周期内 Acquire 调用总次数
    int32 TotalReuses = 0;         // 生命周期内从池复用的总次数
};
```

**设计决策**：
- 锁粒度为每 Bucket：不同类型之间零竞争
- ActiveObjects 拆分到每个 Bucket 中（移除全局 TSet），消除全局热点
- 每类型独立配置，允许不同类型拥有不同的池大小和清理间隔

---

## 3. 扩展 IPoolableInterface 生命周期

### 3.1 回调定义（共 6 个）

| 回调 | 触发时机 | 用途 |
|------|---------|------|
| `OnCreated()` | 首次 Spawn 之后 | 一次性初始化（绑定组件引用等） |
| `Reset()` | 获取和归还时都调用 | 重置运行时状态到初始值 |
| `OnUnpooled()` | 从池中取出后 | 激活逻辑（启用碰撞、Tick、显示等） |
| `OnPrePooled()` | **新增** - 归还到池之前 | 清理外部引用（从场景树解除绑定、停止音效等） |
| `OnPooled()` | 归还到池之后 | 钝化逻辑（禁用碰撞、Tick、隐藏等） |
| `OnDestroyed()` | **新增** - 池销毁对象之前 | 释放一次性资源（与 OnCreated 对称） |

### 3.2 确定性调用序列

```
首次创建：     SpawnActor -> OnCreated -> Reset -> OnUnpooled -> [使用中]
从池中获取：   从 Bucket Pop -> Reset -> OnUnpooled -> [使用中]
归还到池：     [使用中] -> OnPrePooled -> Reset -> OnPooled -> 添加到 Bucket
池销毁对象：   OnDestroyed -> Destroy / ConditionalBeginDestroy
```

### 3.3 接口声明

```cpp
UINTERFACE(MinimalAPI)
class UPoolableInterface : public UInterface
{
    GENERATED_BODY()
};

class GAMEPLAYPROJECT_API IPoolableInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void Reset();

    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnCreated();

    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnPooled();

    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnUnpooled();

    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnPrePooled();

    UFUNCTION(BlueprintNativeEvent, Category = "Pooling")
    void OnDestroyed();
};
```

---

## 4. ObjectPoolManager 公开 API

### 4.1 类声明

```cpp
UCLASS()
class GAMEPLAYPROJECT_API UObjectPoolManager : public UObject
{
    GENERATED_BODY()

public:
    static UObjectPoolManager* Get(UWorld* World);

    // 核心操作
    template<typename T>
    T* Acquire(TSubclassOf<T> ObjectClass);

    template<typename T>
    void Release(T* Object);

    template<typename T>
    void Preallocate(TSubclassOf<T> ObjectClass, int32 Count);

    // 池管理
    void CleanupAll();
    void CleanupForClass(TSubclassOf<UObject> ObjectClass);
    void DrainAll();

    // 配置
    void SetPoolConfig(TSubclassOf<UObject> ObjectClass, const FPoolTypeConfig& Config);
    FPoolTypeConfig GetPoolConfig(TSubclassOf<UObject> ObjectClass) const;

    // 统计
    void GetPoolStatistics(TMap<FString, FPoolStatistics>& OutStats) const;

private:
    FObjectPoolBucket& FindOrCreateBucket(TSubclassOf<UObject> ObjectClass);

    TMap<TSubclassOf<UObject>, FObjectPoolBucket> Buckets;
    FCriticalSection BucketsMapLock;    // 仅保护 Buckets map 的增删
    FPoolTypeConfig DefaultConfig;      // 未配置类型的默认值
    TMap<FString, FPoolTypeConfig> PerClassConfigs; // INI 覆盖配置

    FTimerHandle CleanupTimerHandle;
    static UObjectPoolManager* Instance;
};
```

### 4.2 线程安全策略 — 两级锁

| 操作 | 锁 | 说明 |
|------|---|------|
| 首次注册新类型（Bucket 不存在） | `BucketsMapLock` | 仅在 TMap 插入时持有 |
| Acquire / Release / 按类型 Cleanup | `Bucket.Lock` | 每类型粒度，不同类型零竞争 |
| GetPoolStatistics | 短暂获取各 `Bucket.Lock` | 只读快照，不阻塞业务操作 |

### 4.3 Acquire 流程

```
1. FindOrCreateBucket(ObjectClass)
     - 检查 Buckets map（读取，已存在的条目无需加锁）
     - 如果不存在：加 BucketsMapLock，二次检查，创建 Bucket，应用 PerClassConfigs，解锁
2. 加 Bucket.Lock
3. 如果 PooledObjects 非空：
     - Pop 对象
     - 移入 ActiveObjects
     - 递增 TotalReuses
     - 解锁 Bucket.Lock
     - 调用：Reset -> OnUnpooled
4. 否则：
     - 递增 TotalAllocations
     - 解锁 Bucket.Lock
     - SpawnActor（必须在游戏线程）
     - 加 Bucket.Lock，添加到 ActiveObjects，解锁
     - 调用：OnCreated -> Reset -> OnUnpooled
5. 返回对象
```

### 4.4 Release 流程

```
1. FindOrCreateBucket(Object->GetClass())
2. 调用：OnPrePooled -> Reset -> OnPooled（锁外 — 回调可能执行重量级操作）
3. 加 Bucket.Lock
4. 从 ActiveObjects 移除
5. 如果 PooledObjects.Num() < Config.MaxPoolSize：
     - 添加到 PooledObjects
     - 解锁 Bucket.Lock
6. 否则：
     - 解锁 Bucket.Lock
     - 调用 OnDestroyed -> Destroy/ConditionalBeginDestroy（锁外 — Destroy 可能触发 GC）
```

### 4.5 DrainAll 流程（关卡切换时）

```
1. 加 BucketsMapLock
2. 遍历每个 Bucket：
     - 加 Bucket.Lock
     - 池化对象：OnDestroyed -> Destroy
     - 活跃对象：仅移除追踪（由拥有者负责其生命周期）
     - 清空 PooledObjects 和 ActiveObjects
     - 解锁 Bucket.Lock
3. 清空 Buckets map
4. 解锁 BucketsMapLock
```

---

## 5. INI 配置

### 5.1 DefaultGame.ini 结构

```ini
[/Script/GameplayProject.ObjectPoolManager]
; 全局默认值
DefaultMaxPoolSize=20
DefaultCleanupInterval=30.0

; 按类型覆盖
+PerClassConfigs=(ClassName="/Script/GameplayProject.InventoryItem", MaxPoolSize=15, CleanupInterval=30.0)
```

### 5.2 加载方式

- `DefaultConfig` 通过构造函数中的 `UPROPERTY(Config)` 从 INI 自动加载
- `PerClassConfigs` 是带 `UPROPERTY(Config)` 的 `TMap<FString, FPoolTypeConfig>`
- 在 `Get()` 初始化时，遍历 PerClassConfigs 并注入到对应 Bucket 的 Config 中
- 运行时通过 `SetPoolConfig()` 覆盖，优先级高于 INI

---

## 6. 清理机制

### 6.1 定时器清理

单个全局定时器以所有 Bucket 中最小的 CleanupInterval 运行。每次触发时：

```
遍历每个 Bucket：
  1. 检查 (当前时间 - Bucket.LastCleanupTime) >= Bucket.Config.CleanupInterval
     - 如果未到间隔，跳过该 Bucket
  2. 加 Bucket.Lock
  3. 移除无效对象（!IsValid 检查）从 PooledObjects
  4. 当 PooledObjects.Num() > Config.MaxPoolSize 时：
     - 从尾部 Pop
     - 调用 OnDestroyed -> Destroy/ConditionalBeginDestroy
  5. 移除 ActiveObjects 中的无效引用
  6. 更新 Bucket.LastCleanupTime
  7. 解锁 Bucket.Lock
```

---

## 7. InventoryComponent 重构

### 7.1 删除的成员

```cpp
// 删除以下所有内容：
TMap<TSubclassOf<AInventoryItem>, TArray<AInventoryItem*>> ItemsPoolByClass;
TArray<AInventoryItem*> PendingDestroyItems;
FTimerHandle CleanupTimerHandle;  // 仅删除池相关的定时器
void CleanupItemPool();
```

### 7.2 重构的方法

`CreateItemFromPool` 变为薄封装：

```cpp
AInventoryItem* UInventoryComponent::CreateItemFromPool(TSubclassOf<AInventoryItem> ItemClass)
{
    UObjectPoolManager* PoolMgr = UObjectPoolManager::Get(GetWorld());
    if (!PoolMgr) return nullptr;

    AInventoryItem* NewItem = PoolMgr->Acquire<AInventoryItem>(ItemClass);
    if (NewItem)
    {
        ItemPool.Add(NewItem);
    }
    return NewItem;
}
```

`ReturnItemToPool` 变为薄封装：

```cpp
void UInventoryComponent::ReturnItemToPool(AInventoryItem* Item)
{
    if (!Item) return;

    ItemPool.Remove(Item);

    UObjectPoolManager* PoolMgr = UObjectPoolManager::Get(GetWorld());
    if (PoolMgr)
    {
        PoolMgr->Release(Item);
    }
}
```

### 7.3 SplitItem 修复

在 `AInventoryItem::SplitItem()` 中，将直接的 `SpawnActor` 替换为池获取：

```cpp
// 旧：
AInventoryItem* NewItem = World->SpawnActor<AInventoryItem>(GetClass());

// 新：
UObjectPoolManager* PoolMgr = UObjectPoolManager::Get(GetWorld());
AInventoryItem* NewItem = PoolMgr->Acquire<AInventoryItem>(GetClass());
```

### 7.4 EndPlay 清理

`UInventoryComponent::EndPlay` 时，活跃物品通过 `Release()` 归还到全局池，而不是直接销毁。全局池的生命周期由关卡切换时的 `DrainAll()` 统一处理。

---

## 8. 需要修改的文件

| 文件 | 操作 | 范围 |
|------|------|------|
| `Public/ObjectPool/PoolableInterface.h` | 修改 | 添加 OnPrePooled、OnDestroyed 声明 |
| `Public/ObjectPool/ObjectPoolManager.h` | 重写 | 新 API、FObjectPoolBucket、FPoolTypeConfig、线程安全成员 |
| `Private/ObjectPool/ObjectPoolManager.cpp` | 重写 | Acquire/Release/Cleanup/Drain 实现、INI 加载、定时器逻辑 |
| `Public/Inventory/InventoryComponent.h` | 修改 | 删除池相关成员（约 5 行） |
| `Private/Inventory/InventoryComponent.cpp` | 修改 | 重构 CreateItemFromPool、ReturnItemToPool、CleanupItemPool（约 60 行） |
| `Private/Inventory/InventoryItem.cpp` | 修改 | SplitItem 池修复、实现 OnPrePooled/OnDestroyed 回调（约 10 行） |
| `Config/DefaultGame.ini` | 修改 | 添加 ObjectPoolManager 配置段 |

---

## 9. 迁移检查清单

1. 在 `IPoolableInterface` 中添加 `OnPrePooled` 和 `OnDestroyed`
2. 实现 `FPoolTypeConfig` 和 `FObjectPoolBucket`
3. 重写 `UObjectPoolManager`，包含新 API、线程安全、INI 配置
4. 实现 `AInventoryItem::OnPrePooled_Implementation` 和 `OnDestroyed_Implementation`
5. 重构 `UInventoryComponent`，删除本地池并委托给全局管理器
6. 修复 `AInventoryItem::SplitItem` 使用对象池
7. 更新 `EndPlay` 清理逻辑
8. 在 `DefaultGame.ini` 中添加 INI 配置
9. 编译和测试
