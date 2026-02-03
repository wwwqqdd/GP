#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Actor.h"
#include "Actor/GameplayDamageTypes.h"
#include "GunProjectile.generated.h"

class UGameplayEffect;
class UNiagaraSystem;
class USphereComponent;
class UProjectileMovementComponent;
class UAudioComponent;

UCLASS()
class GAMEPLAYPROJECT_API AGunProjectile : public AActor
{
    GENERATED_BODY()
    
public:    
    AGunProjectile();
    
    UFUNCTION(BlueprintCallable)
    virtual void OnHit();
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
    
    UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
    FDamageEffectParams DamageEffectParams;
    
    UFUNCTION(BlueprintCallable, Category = "Projectile")
    void SetVelocity(const FVector& NewVelocity);
    
protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Destroyed() override;
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OnHit();
    
private:
    
    UFUNCTION()
    void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    void ApplyDamageToTarget(AActor* TargetActor, const FHitResult& HitResult);
    FGameplayEffectContextHandle ApplyDamageEffect(const FDamageEffectParams& Params);
    
    bool IsValidOverlap(AActor* OtherActor) const;
    bool ShouldIgnoreActor(AActor* OtherActor) const;
    
    void DisableCollision();
    void PlayHitEffects(const FVector& Location, const FVector& Normal);
    FDamageEffectParams CreateDamageParamsForTarget(AActor* TargetActor, const FHitResult& HitResult) const;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    TObjectPtr<USphereComponent> SphereCollision;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    TObjectPtr<UStaticMeshComponent> ProjectileMesh;
    
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TObjectPtr<UNiagaraSystem> ImpactEffect;
    
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TObjectPtr<USoundBase> ImpactSound;
    
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TObjectPtr<USoundBase> LoopingSound;
    
    UPROPERTY()
    TObjectPtr<UAudioComponent> LoopingSoundComponent;
    
    UPROPERTY(EditDefaultsOnly, Category = "Projectile", meta = (ClampMin = "0.1"))
    float LifeSpan = 10.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Projectile")
    bool bDestroyOnImpact = true;
    
    UPROPERTY(EditDefaultsOnly, Category = "Projectile")
    bool bPierceTargets = false;
    
    bool bHasHit = false;
    bool bIsDestroying = false;
    TSet<AActor*> AlreadyHitActors;  // 用于穿透检测，避免重复伤害
    
    // 网络
    UPROPERTY(ReplicatedUsing = OnRep_HitConfirmed)
    bool bHitConfirmed = false;
    
    UFUNCTION()
    void OnRep_HitConfirmed();
};