// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ALSBaseCharacter.h"

#ifdef ALS_SYSTEM_ALSBaseCharacter_generated_h
#error "ALSBaseCharacter.generated.h already included, missing '#pragma once' in ALSBaseCharacter.h"
#endif
#define ALS_SYSTEM_ALSBaseCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UALSCharacterMovementComponent;
class UALSPlayerCameraBehavior;
class UAnimMontage;
class USkeletalMesh;
enum class EALSGait : uint8;
enum class EALSGroundedEntryState : uint8;
enum class EALSMovementAction : uint8;
enum class EALSMovementState : uint8;
enum class EALSOverlayState : uint8;
enum class EALSRotationMode : uint8;
enum class EALSStance : uint8;
enum class EALSViewMode : uint8;
struct FALSMovementSettings;

// ********** Begin Delegate FJumpPressedSignature *************************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_13_DELEGATE \
ALS_SYSTEM_API void FJumpPressedSignature_DelegateWrapper(const FMulticastScriptDelegate& JumpPressedSignature);


// ********** End Delegate FJumpPressedSignature ***************************************************

// ********** Begin Delegate FOnJumpedSignature ****************************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_14_DELEGATE \
ALS_SYSTEM_API void FOnJumpedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnJumpedSignature);


// ********** End Delegate FOnJumpedSignature ******************************************************

// ********** Begin Delegate FRagdollStateChangedSignature *****************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_15_DELEGATE \
ALS_SYSTEM_API void FRagdollStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& RagdollStateChangedSignature, bool bRagdollState);


// ********** End Delegate FRagdollStateChangedSignature *******************************************

// ********** Begin Class AALSBaseCharacter ********************************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void LookingDirectionAction_Implementation(); \
	virtual void VelocityDirectionAction_Implementation(); \
	virtual void RagdollAction_Implementation(); \
	virtual void WalkAction_Implementation(); \
	virtual void StanceAction_Implementation(); \
	virtual void CameraHeldAction_Implementation(); \
	virtual void CameraTapAction_Implementation(); \
	virtual void AimAction_Implementation(bool bValue); \
	virtual void SprintAction_Implementation(bool bValue); \
	virtual void JumpAction_Implementation(bool bValue); \
	virtual void CameraRightAction_Implementation(float Value); \
	virtual void CameraUpAction_Implementation(float Value); \
	virtual void RightMovementAction_Implementation(float Value); \
	virtual void ForwardMovementAction_Implementation(float Value); \
	virtual void Server_SetVisibleMesh_Implementation(USkeletalMesh* NewSkeletalMesh); \
	virtual void Server_SetDesiredRotationMode_Implementation(EALSRotationMode NewRotMode); \
	virtual void Server_SetDesiredGait_Implementation(EALSGait NewGait); \
	virtual void Server_SetDesiredStance_Implementation(EALSStance NewStance); \
	virtual void Multicast_RagdollEnd_Implementation(FVector CharacterLocation); \
	virtual void Server_RagdollEnd_Implementation(FVector CharacterLocation); \
	virtual void Multicast_RagdollStart_Implementation(); \
	virtual void Server_RagdollStart_Implementation(); \
	virtual void Multicast_PlayMontage_Implementation(UAnimMontage* Montage, float PlayRate); \
	virtual void Server_PlayMontage_Implementation(UAnimMontage* Montage, float PlayRate); \
	virtual void Multicast_OnJumped_Implementation(); \
	virtual void Multicast_OnLanded_Implementation(); \
	virtual void Server_SetOverlayState_Implementation(EALSOverlayState NewState, bool bForce); \
	virtual void Server_SetViewMode_Implementation(EALSViewMode NewViewMode, bool bForce); \
	virtual void Server_SetRotationMode_Implementation(EALSRotationMode NewRotationMode, bool bForce); \
	virtual void Server_SetMeshLocationDuringRagdoll_Implementation(FVector MeshLocation); \
	DECLARE_FUNCTION(execOnRep_VisibleMesh); \
	DECLARE_FUNCTION(execOnRep_OverlayState); \
	DECLARE_FUNCTION(execOnRep_ViewMode); \
	DECLARE_FUNCTION(execOnRep_RotationMode); \
	DECLARE_FUNCTION(execLookingDirectionAction); \
	DECLARE_FUNCTION(execVelocityDirectionAction); \
	DECLARE_FUNCTION(execRagdollAction); \
	DECLARE_FUNCTION(execWalkAction); \
	DECLARE_FUNCTION(execStanceAction); \
	DECLARE_FUNCTION(execCameraHeldAction); \
	DECLARE_FUNCTION(execCameraTapAction); \
	DECLARE_FUNCTION(execAimAction); \
	DECLARE_FUNCTION(execSprintAction); \
	DECLARE_FUNCTION(execJumpAction); \
	DECLARE_FUNCTION(execCameraRightAction); \
	DECLARE_FUNCTION(execCameraUpAction); \
	DECLARE_FUNCTION(execRightMovementAction); \
	DECLARE_FUNCTION(execForwardMovementAction); \
	DECLARE_FUNCTION(execGetAimYawRate); \
	DECLARE_FUNCTION(execGetAimingRotation); \
	DECLARE_FUNCTION(execGetSpeed); \
	DECLARE_FUNCTION(execGetMovementInputAmount); \
	DECLARE_FUNCTION(execGetMovementInput); \
	DECLARE_FUNCTION(execIsMoving); \
	DECLARE_FUNCTION(execGetAcceleration); \
	DECLARE_FUNCTION(execSetCameraBehavior); \
	DECLARE_FUNCTION(execGetCameraParameters); \
	DECLARE_FUNCTION(execGetFirstPersonCameraTarget); \
	DECLARE_FUNCTION(execGetThirdPersonPivotTarget); \
	DECLARE_FUNCTION(execGetThirdPersonTraceParams); \
	DECLARE_FUNCTION(execSetRightShoulder); \
	DECLARE_FUNCTION(execIsRightShoulder); \
	DECLARE_FUNCTION(execServer_SetVisibleMesh); \
	DECLARE_FUNCTION(execSetVisibleMesh); \
	DECLARE_FUNCTION(execGetAnimCurveValue); \
	DECLARE_FUNCTION(execSetActorLocationAndTargetRotation); \
	DECLARE_FUNCTION(execServer_SetDesiredRotationMode); \
	DECLARE_FUNCTION(execSetDesiredRotationMode); \
	DECLARE_FUNCTION(execGetDesiredRotationMode); \
	DECLARE_FUNCTION(execServer_SetDesiredGait); \
	DECLARE_FUNCTION(execSetDesiredGait); \
	DECLARE_FUNCTION(execServer_SetDesiredStance); \
	DECLARE_FUNCTION(execSetDesiredStance); \
	DECLARE_FUNCTION(execGetDesiredStance); \
	DECLARE_FUNCTION(execReplicated_PlayMontage); \
	DECLARE_FUNCTION(execOnBreakfall); \
	DECLARE_FUNCTION(execCanSprint); \
	DECLARE_FUNCTION(execGetActualGait); \
	DECLARE_FUNCTION(execGetAllowedGait); \
	DECLARE_FUNCTION(execGetTargetMovementSettings); \
	DECLARE_FUNCTION(execHasMovementInput); \
	DECLARE_FUNCTION(execMulticast_RagdollEnd); \
	DECLARE_FUNCTION(execServer_RagdollEnd); \
	DECLARE_FUNCTION(execReplicatedRagdollEnd); \
	DECLARE_FUNCTION(execMulticast_RagdollStart); \
	DECLARE_FUNCTION(execServer_RagdollStart); \
	DECLARE_FUNCTION(execReplicatedRagdollStart); \
	DECLARE_FUNCTION(execMulticast_PlayMontage); \
	DECLARE_FUNCTION(execServer_PlayMontage); \
	DECLARE_FUNCTION(execMulticast_OnJumped); \
	DECLARE_FUNCTION(execEventOnJumped); \
	DECLARE_FUNCTION(execMulticast_OnLanded); \
	DECLARE_FUNCTION(execEventOnLanded); \
	DECLARE_FUNCTION(execGetGroundedEntryState); \
	DECLARE_FUNCTION(execSetGroundedEntryState); \
	DECLARE_FUNCTION(execServer_SetOverlayState); \
	DECLARE_FUNCTION(execSetOverlayState); \
	DECLARE_FUNCTION(execGetViewMode); \
	DECLARE_FUNCTION(execServer_SetViewMode); \
	DECLARE_FUNCTION(execSetViewMode); \
	DECLARE_FUNCTION(execGetRotationMode); \
	DECLARE_FUNCTION(execServer_SetRotationMode); \
	DECLARE_FUNCTION(execSetRotationMode); \
	DECLARE_FUNCTION(execGetDesiredGait); \
	DECLARE_FUNCTION(execGetGait); \
	DECLARE_FUNCTION(execSetGait); \
	DECLARE_FUNCTION(execGetOverlayOverrideState); \
	DECLARE_FUNCTION(execSetOverlayOverrideState); \
	DECLARE_FUNCTION(execGetStance); \
	DECLARE_FUNCTION(execSetStance); \
	DECLARE_FUNCTION(execGetMovementAction); \
	DECLARE_FUNCTION(execSetMovementAction); \
	DECLARE_FUNCTION(execGetPrevMovementState); \
	DECLARE_FUNCTION(execGetMovementState); \
	DECLARE_FUNCTION(execSetMovementState); \
	DECLARE_FUNCTION(execServer_SetMeshLocationDuringRagdoll); \
	DECLARE_FUNCTION(execRagdollEnd); \
	DECLARE_FUNCTION(execRagdollStart); \
	DECLARE_FUNCTION(execGetMyMovementComponent);


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_CALLBACK_WRAPPERS
ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSBaseCharacter_NoRegister();

#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAALSBaseCharacter(); \
	friend struct Z_Construct_UClass_AALSBaseCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSBaseCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AALSBaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ALS_System"), Z_Construct_UClass_AALSBaseCharacter_NoRegister) \
	DECLARE_SERIALIZER(AALSBaseCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		DesiredRotationMode=NETFIELD_REP_START, \
		DesiredStance, \
		DesiredGait, \
		ReplicatedControlRotation, \
		VisibleMesh, \
		OverlayState, \
		RotationMode, \
		ViewMode, \
		ReplicatedCurrentAcceleration, \
		TargetRagdollLocation, \
		NETFIELD_REP_END=TargetRagdollLocation	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AALSBaseCharacter(AALSBaseCharacter&&) = delete; \
	AALSBaseCharacter(const AALSBaseCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AALSBaseCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AALSBaseCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AALSBaseCharacter) \
	NO_API virtual ~AALSBaseCharacter();


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_17_PROLOG
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_CALLBACK_WRAPPERS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_INCLASS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AALSBaseCharacter;

// ********** End Class AALSBaseCharacter **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSBaseCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
