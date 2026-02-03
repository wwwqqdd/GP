// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Library/ALSCharacterEnumLibrary.h"

#ifdef ALS_SYSTEM_ALSCharacterEnumLibrary_generated_h
#error "ALSCharacterEnumLibrary.generated.h already included, missing '#pragma once' in ALSCharacterEnumLibrary.h"
#endif
#define ALS_SYSTEM_ALSCharacterEnumLibrary_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterEnumLibrary_h

// ********** Begin Enum EALSGait ******************************************************************
#define FOREACH_ENUM_EALSGAIT(op) \
	op(EALSGait::Walking) \
	op(EALSGait::Running) \
	op(EALSGait::Sprinting) 

enum class EALSGait : uint8;
template<> struct TIsUEnumClass<EALSGait> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSGait>();
// ********** End Enum EALSGait ********************************************************************

// ********** Begin Enum EALSMovementAction ********************************************************
#define FOREACH_ENUM_EALSMOVEMENTACTION(op) \
	op(EALSMovementAction::None) \
	op(EALSMovementAction::LowMantle) \
	op(EALSMovementAction::HighMantle) \
	op(EALSMovementAction::Rolling) \
	op(EALSMovementAction::GettingUp) 

enum class EALSMovementAction : uint8;
template<> struct TIsUEnumClass<EALSMovementAction> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMovementAction>();
// ********** End Enum EALSMovementAction **********************************************************

// ********** Begin Enum EALSMovementState *********************************************************
#define FOREACH_ENUM_EALSMOVEMENTSTATE(op) \
	op(EALSMovementState::None) \
	op(EALSMovementState::Grounded) \
	op(EALSMovementState::InAir) \
	op(EALSMovementState::Mantling) \
	op(EALSMovementState::Ragdoll) 

enum class EALSMovementState : uint8;
template<> struct TIsUEnumClass<EALSMovementState> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMovementState>();
// ********** End Enum EALSMovementState ***********************************************************

// ********** Begin Enum EALSOverlayState **********************************************************
#define FOREACH_ENUM_EALSOVERLAYSTATE(op) \
	op(EALSOverlayState::Default) \
	op(EALSOverlayState::Masculine) \
	op(EALSOverlayState::Feminine) \
	op(EALSOverlayState::Injured) \
	op(EALSOverlayState::HandsTied) \
	op(EALSOverlayState::Rifle) \
	op(EALSOverlayState::PistolOneHanded) \
	op(EALSOverlayState::PistolTwoHanded) \
	op(EALSOverlayState::Bow) \
	op(EALSOverlayState::Torch) \
	op(EALSOverlayState::Binoculars) \
	op(EALSOverlayState::Box) \
	op(EALSOverlayState::Barrel) 

enum class EALSOverlayState : uint8;
template<> struct TIsUEnumClass<EALSOverlayState> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSOverlayState>();
// ********** End Enum EALSOverlayState ************************************************************

// ********** Begin Enum EALSRotationMode **********************************************************
#define FOREACH_ENUM_EALSROTATIONMODE(op) \
	op(EALSRotationMode::VelocityDirection) \
	op(EALSRotationMode::LookingDirection) \
	op(EALSRotationMode::Aiming) 

enum class EALSRotationMode : uint8;
template<> struct TIsUEnumClass<EALSRotationMode> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSRotationMode>();
// ********** End Enum EALSRotationMode ************************************************************

// ********** Begin Enum EALSStance ****************************************************************
#define FOREACH_ENUM_EALSSTANCE(op) \
	op(EALSStance::Standing) \
	op(EALSStance::Crouching) 

enum class EALSStance : uint8;
template<> struct TIsUEnumClass<EALSStance> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSStance>();
// ********** End Enum EALSStance ******************************************************************

// ********** Begin Enum EALSViewMode **************************************************************
#define FOREACH_ENUM_EALSVIEWMODE(op) \
	op(EALSViewMode::ThirdPerson) \
	op(EALSViewMode::FirstPerson) 

enum class EALSViewMode : uint8;
template<> struct TIsUEnumClass<EALSViewMode> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSViewMode>();
// ********** End Enum EALSViewMode ****************************************************************

// ********** Begin Enum EALSAnimFeatureExample ****************************************************
#define FOREACH_ENUM_EALSANIMFEATUREEXAMPLE(op) \
	op(EALSAnimFeatureExample::StrideBlending) \
	op(EALSAnimFeatureExample::AdditiveBlending) \
	op(EALSAnimFeatureExample::SprintImpulse) 

enum class EALSAnimFeatureExample : uint8;
template<> struct TIsUEnumClass<EALSAnimFeatureExample> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSAnimFeatureExample>();
// ********** End Enum EALSAnimFeatureExample ******************************************************

// ********** Begin Enum EALSFootstepType **********************************************************
#define FOREACH_ENUM_EALSFOOTSTEPTYPE(op) \
	op(EALSFootstepType::Step) \
	op(EALSFootstepType::WalkRun) \
	op(EALSFootstepType::Jump) \
	op(EALSFootstepType::Land) 

enum class EALSFootstepType : uint8;
template<> struct TIsUEnumClass<EALSFootstepType> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSFootstepType>();
// ********** End Enum EALSFootstepType ************************************************************

// ********** Begin Enum EALSGroundedEntryState ****************************************************
#define FOREACH_ENUM_EALSGROUNDEDENTRYSTATE(op) \
	op(EALSGroundedEntryState::None) \
	op(EALSGroundedEntryState::Roll) 

enum class EALSGroundedEntryState : uint8;
template<> struct TIsUEnumClass<EALSGroundedEntryState> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSGroundedEntryState>();
// ********** End Enum EALSGroundedEntryState ******************************************************

// ********** Begin Enum EALSHipsDirection *********************************************************
#define FOREACH_ENUM_EALSHIPSDIRECTION(op) \
	op(EALSHipsDirection::F) \
	op(EALSHipsDirection::B) \
	op(EALSHipsDirection::RF) \
	op(EALSHipsDirection::RB) \
	op(EALSHipsDirection::LF) \
	op(EALSHipsDirection::LB) 

enum class EALSHipsDirection : uint8;
template<> struct TIsUEnumClass<EALSHipsDirection> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSHipsDirection>();
// ********** End Enum EALSHipsDirection ***********************************************************

// ********** Begin Enum EALSMantleType ************************************************************
#define FOREACH_ENUM_EALSMANTLETYPE(op) \
	op(EALSMantleType::HighMantle) \
	op(EALSMantleType::LowMantle) \
	op(EALSMantleType::FallingCatch) 

enum class EALSMantleType : uint8;
template<> struct TIsUEnumClass<EALSMantleType> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMantleType>();
// ********** End Enum EALSMantleType **************************************************************

// ********** Begin Enum EALSMovementDirection *****************************************************
#define FOREACH_ENUM_EALSMOVEMENTDIRECTION(op) \
	op(EALSMovementDirection::Forward) \
	op(EALSMovementDirection::Right) \
	op(EALSMovementDirection::Left) \
	op(EALSMovementDirection::Backward) 

enum class EALSMovementDirection : uint8;
template<> struct TIsUEnumClass<EALSMovementDirection> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMovementDirection>();
// ********** End Enum EALSMovementDirection *******************************************************

// ********** Begin Enum EALSSpawnType *************************************************************
#define FOREACH_ENUM_EALSSPAWNTYPE(op) \
	op(EALSSpawnType::Location) \
	op(EALSSpawnType::Attached) 

enum class EALSSpawnType : uint8;
template<> struct TIsUEnumClass<EALSSpawnType> { enum { Value = true }; };
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSSpawnType>();
// ********** End Enum EALSSpawnType ***************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
