#include "Actor/GunProjectile.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

AGunProjectile::AGunProjectile()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    AActor::SetReplicateMovement(true);

    // 根组件 - 使用场景组件，避免缩放问题
    USceneComponent* SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
    SetRootComponent(SceneRoot);

    // 碰撞组件
    SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
    SphereCollision->SetupAttachment(RootComponent);
    SphereCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SphereCollision->SetCollisionObjectType(ECC_WorldDynamic);
    SphereCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
    SphereCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
    SphereCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
    SphereCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    SphereCollision->SetGenerateOverlapEvents(true);
    SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AGunProjectile::OnSphereOverlap);

    // 网格组件（可选）
    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
    ProjectileMesh->SetupAttachment(RootComponent);
    ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ProjectileMesh->SetGenerateOverlapEvents(false);

    // 投射物运动组件
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
    ProjectileMovement->SetUpdatedComponent(RootComponent);
    ProjectileMovement->InitialSpeed = 1500.0f;
    ProjectileMovement->MaxSpeed = 1500.0f;
    ProjectileMovement->ProjectileGravityScale = 0.0f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;
}

void AGunProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME_CONDITION(AGunProjectile, bHitConfirmed, COND_None);
}

void AGunProjectile::BeginPlay()
{
    Super::BeginPlay();
    
    SetLifeSpan(LifeSpan);
    
    if (AActor* InstigatorActor = GetInstigator())
    {
        AlreadyHitActors.Add(InstigatorActor);
        
        if (SphereCollision)
        {
            SphereCollision->IgnoreActorWhenMoving(InstigatorActor, true);
        }
    }
    
    if (LoopingSound)
    {
        LoopingSoundComponent = UGameplayStatics::SpawnSoundAttached(LoopingSound,RootComponent,NAME_None,FVector::ZeroVector,EAttachLocation::KeepRelativeOffset,false,1.0f,1.0f,0.0f,nullptr,nullptr,false);
    }
}

void AGunProjectile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (LoopingSoundComponent)
    {
        LoopingSoundComponent->Stop();
        LoopingSoundComponent->DestroyComponent();
        LoopingSoundComponent = nullptr;
    }
    
    Super::EndPlay(EndPlayReason);
}

void AGunProjectile::Destroyed()
{
    // 确保音效停止
    if (LoopingSoundComponent && LoopingSoundComponent->IsPlaying())
    {
        LoopingSoundComponent->Stop();
        LoopingSoundComponent->DestroyComponent();
        LoopingSoundComponent = nullptr;
    }
    
    if (!bHasHit && !HasAuthority() && !bHitConfirmed)
    {
        Multicast_OnHit();
    }
    
    Super::Destroyed();
}

void AGunProjectile::OnHit()
{
    if (bHasHit) return;
    bHasHit = true;
    
    // 服务器：触发多播
    if (HasAuthority())
    {
        Multicast_OnHit();
    }
    else
    {
        // 客户端预测
        PlayHitEffects(GetActorLocation(), -GetActorForwardVector());
    }
}

void AGunProjectile::Multicast_OnHit_Implementation()
{
    if (bHasHit) return;
    bHasHit = true;
    
    PlayHitEffects(GetActorLocation(), -GetActorForwardVector());
}

void AGunProjectile::OnRep_HitConfirmed()
{
    if (bHitConfirmed && !bHasHit)
    {
        OnHit();
    }
}

void AGunProjectile::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
                                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (bIsDestroying || !IsValid(OtherActor)) return;
    
    if (!IsValidOverlap(OtherActor)) return;
    
    if (AlreadyHitActors.Contains(OtherActor)) return;
    AlreadyHitActors.Add(OtherActor);
    
    if (!bHasHit)
    {
        OnHit();
    }
    
    if (HasAuthority())
    {
        ApplyDamageToTarget(OtherActor, SweepResult);
        
        if (!bPierceTargets)
        {
            bIsDestroying = true;
            Destroy();
        }
    }
}

void AGunProjectile::ApplyDamageToTarget(AActor* TargetActor, const FHitResult& HitResult)
{
    if (!IsValid(TargetActor)) return;
    
    UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
    if (!TargetASC) return;
    
    // 创建伤害参数
    FDamageEffectParams DamageParams = CreateDamageParamsForTarget(TargetActor, HitResult);
    
    // 确保有源ASC
    if (!DamageParams.SourceAbilitySystemComponent && GetInstigator())
    {
        if (UAbilitySystemComponent* InstigatorASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetInstigator()))
        {
            DamageParams.SourceAbilitySystemComponent = InstigatorASC;
        }
    }
    
    // 应用伤害
    ApplyDamageEffect(DamageParams);
}

FDamageEffectParams AGunProjectile::CreateDamageParamsForTarget(AActor* TargetActor, const FHitResult& HitResult) const
{
    FDamageEffectParams Params = DamageEffectParams;
    
    // 设置目标
    if (UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor))
    {
        Params.TargetAbilitySystemComponent = TargetASC;
    }
    
    // 计算方向
    FVector HitDirection = GetVelocity().GetSafeNormal();
    if (HitDirection.IsNearlyZero())
    {
        HitDirection = GetActorForwardVector();
    }
    
    Params.HitDirection = HitDirection;
    
    // 死亡冲击力
    Params.DeathImpulse = HitDirection * Params.DeathImpulseMagnitude;
    
    // 随机击退
    if (Params.KnockbackChance > 0 && FMath::RandRange(1, 100) < Params.KnockbackChance)
    {
        FRotator KnockbackRotation = HitDirection.Rotation();
        KnockbackRotation.Pitch = 45.0f;  // 向上45度
        
        Params.KnockbackForce = KnockbackRotation.Vector() * Params.KnockbackMagnitude;
    }
    else
    {
        Params.KnockbackForce = FVector::ZeroVector;
    }
    
    // 设置命中信息
    Params.HitLocation = HitResult.Location;
    Params.HitNormal = HitResult.Normal;
    Params.HitActor = TargetActor;
    
    return Params;
}

FGameplayEffectContextHandle AGunProjectile::ApplyDamageEffect(const FDamageEffectParams& Params)
{
    if (!Params.SourceAbilitySystemComponent || !Params.TargetAbilitySystemComponent)
    {
        return FGameplayEffectContextHandle();
    }
    
    UAbilitySystemComponent* SourceASC = Params.SourceAbilitySystemComponent;
    UAbilitySystemComponent* TargetASC = Params.TargetAbilitySystemComponent;
    
    FGameplayEffectContextHandle ContextHandle = SourceASC->MakeEffectContext();
    ContextHandle.AddHitResult(FHitResult(Params.HitActor.Get(), nullptr, Params.HitLocation, Params.HitNormal));
    
    if (Params.DeathImpulse != FVector::ZeroVector)
    {
        ContextHandle.AddOrigin(Params.DeathImpulse);  
    }
    
  
    FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(
        Params.DamageGameplayEffectClass,
        Params.AbilityLevel,
        ContextHandle
    );
    
    if (SpecHandle.IsValid())
    {
        if (Params.BaseDamage > 0.0f)
        {
            SpecHandle.Data->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag("Data.Damage"), Params.BaseDamage);
        }
        
        SourceASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data, TargetASC);
    }
    
    return ContextHandle;
}

bool AGunProjectile::IsValidOverlap(AActor* OtherActor) const
{
    if (!IsValid(OtherActor)) return false;
    
    if (OtherActor == this) return false;
    
    
    if (OtherActor == GetInstigator()) return false;
    
    
    return true;
}

bool AGunProjectile::ShouldIgnoreActor(AActor* OtherActor) const
{
    
    return false;
}

void AGunProjectile::PlayHitEffects(const FVector& Location, const FVector& Normal)
{
    
}

void AGunProjectile::SetVelocity(const FVector& NewVelocity)
{
    if (ProjectileMovement)
    {
        ProjectileMovement->Velocity = NewVelocity;
        ProjectileMovement->UpdateComponentVelocity();
    }
}

void AGunProjectile::DisableCollision()
{
    if (SphereCollision)
    {
        SphereCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        SphereCollision->SetGenerateOverlapEvents(false);
    }
    
    // 隐藏网格
    if (ProjectileMesh)
    {
        ProjectileMesh->SetVisibility(false);
    }
    
    // 停止运动
    if (ProjectileMovement)
    {
        ProjectileMovement->StopMovementImmediately();
        ProjectileMovement->SetActive(false);
    }
}