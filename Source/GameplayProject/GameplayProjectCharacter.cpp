// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayProjectCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameplayProject.h"
#include "GameplayProjectAttributeSet.h"

AGameplayProjectCharacter::AGameplayProjectCharacter()
{
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	check(AbilitySystemComponent);
	AbilitySystemComponent->SetIsReplicated(true);//允许技能系统组件同步
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);//将网络同步模式设置为混合
 
	AttributeSet = CreateDefaultSubobject<UGameplayProjectAttributeSet>(TEXT("AttributeSet"));
	check(AttributeSet);
	
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), "HandGrip_R");
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	
}

void AGameplayProjectCharacter::BeginPlay()
{
	Super::BeginPlay();
	AddCharacterAbilities();
}

void AGameplayProjectCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AGameplayProjectCharacter::Die(const FVector& DeathImpulse)
{
	UE_LOG(LogGameplayProject, Warning, TEXT("Die"));
}

void AGameplayProjectCharacter::AddCharacterAbilities()
{
	for (TSubclassOf<UGameplayAbility>& Ability : DefaultAbilities)
	{
		if (!Ability)
		{
			continue;
		}
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability,1,1,this));
		
		FString AbilityName = Ability->GetName();
		
	}
}



void AGameplayProjectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGameplayProjectCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AGameplayProjectCharacter::Look);
		
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGameplayProjectCharacter::Look);

		EnhancedInputComponent->BindAction(LeftAttackAction, ETriggerEvent::Started, this, &AGameplayProjectCharacter::LeftAttack);
	}
	else
	{
		return;
	}
}

void AGameplayProjectCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AGameplayProjectCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AGameplayProjectCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AGameplayProjectCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AGameplayProjectCharacter::DoJumpStart()
{
	Jump();
}

void AGameplayProjectCharacter::DoJumpEnd()
{
	StopJumping();
}

void AGameplayProjectCharacter::LeftAttack()
{
	// 根据武器槽位是否有武器，触发不同的输入标签
	const FName InputTagName = bHasWeaponInSlot ? FName("Input.LMB.Aim") : FName("Input.LMB.Melee");

	AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(FGameplayTag::RequestGameplayTag(InputTagName)),/*bAllowRemoteActivation*/ true);
	
}

bool AGameplayProjectCharacter::GetbHasWeaponInSlot()
{
	return bHasWeaponInSlot;
}

void AGameplayProjectCharacter::SetbHasWeaponInSlot(bool NewBool)
{
	bHasWeaponInSlot = NewBool;
}

UAbilitySystemComponent* AGameplayProjectCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
