// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Component/ALSDebugComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeALSDebugComponent() {}

// ********** Begin Cross Module References ********************************************************
ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSBaseCharacter_NoRegister();
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSDebugComponent();
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSDebugComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
UPackage* Z_Construct_UPackage__Script_ALS_System();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UALSDebugComponent Function DrawDebugSpheres *****************************
static FName NAME_UALSDebugComponent_DrawDebugSpheres = FName(TEXT("DrawDebugSpheres"));
void UALSDebugComponent::DrawDebugSpheres()
{
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_DrawDebugSpheres);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "DrawDebugSpheres", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UALSDebugComponent Function DrawDebugSpheres *******************************

// ********** Begin Class UALSDebugComponent Function FocusedDebugCharacterCycle *******************
struct Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics
{
	struct ALSDebugComponent_eventFocusedDebugCharacterCycle_Parms
	{
		bool bValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventFocusedDebugCharacterCycle_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventFocusedDebugCharacterCycle_Parms), &Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "FocusedDebugCharacterCycle", Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::ALSDebugComponent_eventFocusedDebugCharacterCycle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::ALSDebugComponent_eventFocusedDebugCharacterCycle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execFocusedDebugCharacterCycle)
{
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FocusedDebugCharacterCycle(Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function FocusedDebugCharacterCycle *********************

// ********** Begin Class UALSDebugComponent Function GetDebugView *********************************
struct Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics
{
	struct ALSDebugComponent_eventGetDebugView_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventGetDebugView_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventGetDebugView_Parms), &Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "GetDebugView", Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::ALSDebugComponent_eventGetDebugView_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::ALSDebugComponent_eventGetDebugView_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_GetDebugView()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_GetDebugView_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execGetDebugView)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetDebugView();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function GetDebugView ***********************************

// ********** Begin Class UALSDebugComponent Function GetShowDebugShapes ***************************
struct Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics
{
	struct ALSDebugComponent_eventGetShowDebugShapes_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventGetShowDebugShapes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventGetShowDebugShapes_Parms), &Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "GetShowDebugShapes", Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::ALSDebugComponent_eventGetShowDebugShapes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::ALSDebugComponent_eventGetShowDebugShapes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execGetShowDebugShapes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetShowDebugShapes();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function GetShowDebugShapes *****************************

// ********** Begin Class UALSDebugComponent Function GetShowLayerColors ***************************
struct Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics
{
	struct ALSDebugComponent_eventGetShowLayerColors_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventGetShowLayerColors_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventGetShowLayerColors_Parms), &Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "GetShowLayerColors", Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::ALSDebugComponent_eventGetShowLayerColors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::ALSDebugComponent_eventGetShowLayerColors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execGetShowLayerColors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetShowLayerColors();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function GetShowLayerColors *****************************

// ********** Begin Class UALSDebugComponent Function GetShowTraces ********************************
struct Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics
{
	struct ALSDebugComponent_eventGetShowTraces_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventGetShowTraces_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventGetShowTraces_Parms), &Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "GetShowTraces", Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::ALSDebugComponent_eventGetShowTraces_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::ALSDebugComponent_eventGetShowTraces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_GetShowTraces()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_GetShowTraces_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execGetShowTraces)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetShowTraces();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function GetShowTraces **********************************

// ********** Begin Class UALSDebugComponent Function OnPlayerControllerInitialized ****************
struct ALSDebugComponent_eventOnPlayerControllerInitialized_Parms
{
	APlayerController* Controller;
};
static FName NAME_UALSDebugComponent_OnPlayerControllerInitialized = FName(TEXT("OnPlayerControllerInitialized"));
void UALSDebugComponent::OnPlayerControllerInitialized(APlayerController* Controller)
{
	ALSDebugComponent_eventOnPlayerControllerInitialized_Parms Parms;
	Parms.Controller=Controller;
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_OnPlayerControllerInitialized);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Controller;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSDebugComponent_eventOnPlayerControllerInitialized_Parms, Controller), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::NewProp_Controller,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "OnPlayerControllerInitialized", Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::PropPointers), sizeof(ALSDebugComponent_eventOnPlayerControllerInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ALSDebugComponent_eventOnPlayerControllerInitialized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UALSDebugComponent Function OnPlayerControllerInitialized ******************

// ********** Begin Class UALSDebugComponent Function OpenOverlayMenu ******************************
struct ALSDebugComponent_eventOpenOverlayMenu_Parms
{
	bool bValue;
};
static FName NAME_UALSDebugComponent_OpenOverlayMenu = FName(TEXT("OpenOverlayMenu"));
void UALSDebugComponent::OpenOverlayMenu(bool bValue)
{
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_OpenOverlayMenu);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ALSDebugComponent_eventOpenOverlayMenu_Parms Parms;
		Parms.bValue=bValue ? true : false;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OpenOverlayMenu_Implementation(bValue);
	}
}
struct Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventOpenOverlayMenu_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventOpenOverlayMenu_Parms), &Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "OpenOverlayMenu", Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::PropPointers), sizeof(ALSDebugComponent_eventOpenOverlayMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ALSDebugComponent_eventOpenOverlayMenu_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execOpenOverlayMenu)
{
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenOverlayMenu_Implementation(Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function OpenOverlayMenu ********************************

// ********** Begin Class UALSDebugComponent Function OverlayMenuCycle *****************************
struct ALSDebugComponent_eventOverlayMenuCycle_Parms
{
	bool bValue;
};
static FName NAME_UALSDebugComponent_OverlayMenuCycle = FName(TEXT("OverlayMenuCycle"));
void UALSDebugComponent::OverlayMenuCycle(bool bValue)
{
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_OverlayMenuCycle);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ALSDebugComponent_eventOverlayMenuCycle_Parms Parms;
		Parms.bValue=bValue ? true : false;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OverlayMenuCycle_Implementation(bValue);
	}
}
struct Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((ALSDebugComponent_eventOverlayMenuCycle_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSDebugComponent_eventOverlayMenuCycle_Parms), &Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "OverlayMenuCycle", Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::PropPointers), sizeof(ALSDebugComponent_eventOverlayMenuCycle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ALSDebugComponent_eventOverlayMenuCycle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execOverlayMenuCycle)
{
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OverlayMenuCycle_Implementation(Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function OverlayMenuCycle *******************************

// ********** Begin Class UALSDebugComponent Function SetDynamicMaterials **************************
static FName NAME_UALSDebugComponent_SetDynamicMaterials = FName(TEXT("SetDynamicMaterials"));
void UALSDebugComponent::SetDynamicMaterials()
{
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_SetDynamicMaterials);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "SetDynamicMaterials", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UALSDebugComponent Function SetDynamicMaterials ****************************

// ********** Begin Class UALSDebugComponent Function SetResetColors *******************************
static FName NAME_UALSDebugComponent_SetResetColors = FName(TEXT("SetResetColors"));
void UALSDebugComponent::SetResetColors()
{
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_SetResetColors);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UALSDebugComponent_SetResetColors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_SetResetColors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "SetResetColors", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_SetResetColors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_SetResetColors_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_SetResetColors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_SetResetColors_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UALSDebugComponent Function SetResetColors *********************************

// ********** Begin Class UALSDebugComponent Function ToggleCharacterInfo **************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleCharacterInfo", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleCharacterInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleCharacterInfo();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleCharacterInfo ****************************

// ********** Begin Class UALSDebugComponent Function ToggleDebugMesh ******************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleDebugMesh", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleDebugMesh)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDebugMesh();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleDebugMesh ********************************

// ********** Begin Class UALSDebugComponent Function ToggleDebugShapes ****************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleDebugShapes", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleDebugShapes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDebugShapes();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleDebugShapes ******************************

// ********** Begin Class UALSDebugComponent Function ToggleDebugView ******************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleDebugView", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleDebugView)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDebugView();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleDebugView ********************************

// ********** Begin Class UALSDebugComponent Function ToggleGlobalTimeDilationLocal ****************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics
{
	struct ALSDebugComponent_eventToggleGlobalTimeDilationLocal_Parms
	{
		float TimeDilation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeDilation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::NewProp_TimeDilation = { "TimeDilation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSDebugComponent_eventToggleGlobalTimeDilationLocal_Parms, TimeDilation), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::NewProp_TimeDilation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleGlobalTimeDilationLocal", Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::ALSDebugComponent_eventToggleGlobalTimeDilationLocal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::ALSDebugComponent_eventToggleGlobalTimeDilationLocal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleGlobalTimeDilationLocal)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_TimeDilation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleGlobalTimeDilationLocal(Z_Param_TimeDilation);
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleGlobalTimeDilationLocal ******************

// ********** Begin Class UALSDebugComponent Function ToggleHud ************************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleHud_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleHud_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleHud", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleHud_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleHud_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleHud()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleHud_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleHud)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleHud();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleHud **************************************

// ********** Begin Class UALSDebugComponent Function ToggleLayerColors ****************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleLayerColors", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleLayerColors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleLayerColors();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleLayerColors ******************************

// ********** Begin Class UALSDebugComponent Function ToggleSlomo **********************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleSlomo", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleSlomo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleSlomo();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleSlomo ************************************

// ********** Begin Class UALSDebugComponent Function ToggleTraces *********************************
struct Z_Construct_UFunction_UALSDebugComponent_ToggleTraces_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_ToggleTraces_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "ToggleTraces", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_ToggleTraces_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_ToggleTraces_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_ToggleTraces()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_ToggleTraces_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSDebugComponent::execToggleTraces)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleTraces();
	P_NATIVE_END;
}
// ********** End Class UALSDebugComponent Function ToggleTraces ***********************************

// ********** Begin Class UALSDebugComponent Function UpdateColoringSystem *************************
static FName NAME_UALSDebugComponent_UpdateColoringSystem = FName(TEXT("UpdateColoringSystem"));
void UALSDebugComponent::UpdateColoringSystem()
{
	UFunction* Func = FindFunctionChecked(NAME_UALSDebugComponent_UpdateColoringSystem);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSDebugComponent, nullptr, "UpdateColoringSystem", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UALSDebugComponent Function UpdateColoringSystem ***************************

// ********** Begin Class UALSDebugComponent *******************************************************
void UALSDebugComponent::StaticRegisterNativesUALSDebugComponent()
{
	UClass* Class = UALSDebugComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FocusedDebugCharacterCycle", &UALSDebugComponent::execFocusedDebugCharacterCycle },
		{ "GetDebugView", &UALSDebugComponent::execGetDebugView },
		{ "GetShowDebugShapes", &UALSDebugComponent::execGetShowDebugShapes },
		{ "GetShowLayerColors", &UALSDebugComponent::execGetShowLayerColors },
		{ "GetShowTraces", &UALSDebugComponent::execGetShowTraces },
		{ "OpenOverlayMenu", &UALSDebugComponent::execOpenOverlayMenu },
		{ "OverlayMenuCycle", &UALSDebugComponent::execOverlayMenuCycle },
		{ "ToggleCharacterInfo", &UALSDebugComponent::execToggleCharacterInfo },
		{ "ToggleDebugMesh", &UALSDebugComponent::execToggleDebugMesh },
		{ "ToggleDebugShapes", &UALSDebugComponent::execToggleDebugShapes },
		{ "ToggleDebugView", &UALSDebugComponent::execToggleDebugView },
		{ "ToggleGlobalTimeDilationLocal", &UALSDebugComponent::execToggleGlobalTimeDilationLocal },
		{ "ToggleHud", &UALSDebugComponent::execToggleHud },
		{ "ToggleLayerColors", &UALSDebugComponent::execToggleLayerColors },
		{ "ToggleSlomo", &UALSDebugComponent::execToggleSlomo },
		{ "ToggleTraces", &UALSDebugComponent::execToggleTraces },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UALSDebugComponent;
UClass* UALSDebugComponent::GetPrivateStaticClass()
{
	using TClass = UALSDebugComponent;
	if (!Z_Registration_Info_UClass_UALSDebugComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ALSDebugComponent"),
			Z_Registration_Info_UClass_UALSDebugComponent.InnerSingleton,
			StaticRegisterNativesUALSDebugComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UALSDebugComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UALSDebugComponent_NoRegister()
{
	return UALSDebugComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UALSDebugComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Component/ALSDebugComponent.h" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerCharacter_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSlomo_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowHud_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowCharacterInfo_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugSkeletalMesh_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableDebugCharacters_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugFocusCharacter_MetaData[] = {
		{ "Category", "ALS|Debug" },
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultSkeletalMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/Component/ALSDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerCharacter;
	static void NewProp_bSlomo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSlomo;
	static void NewProp_bShowHud_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowHud;
	static void NewProp_bShowCharacterInfo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowCharacterInfo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugSkeletalMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AvailableDebugCharacters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AvailableDebugCharacters;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugFocusCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultSkeletalMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UALSDebugComponent_DrawDebugSpheres, "DrawDebugSpheres" }, // 264319989
		{ &Z_Construct_UFunction_UALSDebugComponent_FocusedDebugCharacterCycle, "FocusedDebugCharacterCycle" }, // 3717859584
		{ &Z_Construct_UFunction_UALSDebugComponent_GetDebugView, "GetDebugView" }, // 2525496189
		{ &Z_Construct_UFunction_UALSDebugComponent_GetShowDebugShapes, "GetShowDebugShapes" }, // 1533568186
		{ &Z_Construct_UFunction_UALSDebugComponent_GetShowLayerColors, "GetShowLayerColors" }, // 2249191757
		{ &Z_Construct_UFunction_UALSDebugComponent_GetShowTraces, "GetShowTraces" }, // 1578000930
		{ &Z_Construct_UFunction_UALSDebugComponent_OnPlayerControllerInitialized, "OnPlayerControllerInitialized" }, // 2468862576
		{ &Z_Construct_UFunction_UALSDebugComponent_OpenOverlayMenu, "OpenOverlayMenu" }, // 3288437169
		{ &Z_Construct_UFunction_UALSDebugComponent_OverlayMenuCycle, "OverlayMenuCycle" }, // 3115263936
		{ &Z_Construct_UFunction_UALSDebugComponent_SetDynamicMaterials, "SetDynamicMaterials" }, // 554587686
		{ &Z_Construct_UFunction_UALSDebugComponent_SetResetColors, "SetResetColors" }, // 1643129681
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleCharacterInfo, "ToggleCharacterInfo" }, // 244626307
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleDebugMesh, "ToggleDebugMesh" }, // 2470168098
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleDebugShapes, "ToggleDebugShapes" }, // 3669540698
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleDebugView, "ToggleDebugView" }, // 1263876295
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleGlobalTimeDilationLocal, "ToggleGlobalTimeDilationLocal" }, // 1141709926
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleHud, "ToggleHud" }, // 2846276562
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleLayerColors, "ToggleLayerColors" }, // 3468550862
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleSlomo, "ToggleSlomo" }, // 705141778
		{ &Z_Construct_UFunction_UALSDebugComponent_ToggleTraces, "ToggleTraces" }, // 3619907075
		{ &Z_Construct_UFunction_UALSDebugComponent_UpdateColoringSystem, "UpdateColoringSystem" }, // 1104846711
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UALSDebugComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_OwnerCharacter = { "OwnerCharacter", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSDebugComponent, OwnerCharacter), Z_Construct_UClass_AALSBaseCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerCharacter_MetaData), NewProp_OwnerCharacter_MetaData) };
void Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bSlomo_SetBit(void* Obj)
{
	((UALSDebugComponent*)Obj)->bSlomo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bSlomo = { "bSlomo", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSDebugComponent), &Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bSlomo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSlomo_MetaData), NewProp_bSlomo_MetaData) };
void Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowHud_SetBit(void* Obj)
{
	((UALSDebugComponent*)Obj)->bShowHud = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowHud = { "bShowHud", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSDebugComponent), &Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowHud_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowHud_MetaData), NewProp_bShowHud_MetaData) };
void Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowCharacterInfo_SetBit(void* Obj)
{
	((UALSDebugComponent*)Obj)->bShowCharacterInfo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowCharacterInfo = { "bShowCharacterInfo", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSDebugComponent), &Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowCharacterInfo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowCharacterInfo_MetaData), NewProp_bShowCharacterInfo_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_DebugSkeletalMesh = { "DebugSkeletalMesh", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSDebugComponent, DebugSkeletalMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugSkeletalMesh_MetaData), NewProp_DebugSkeletalMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_AvailableDebugCharacters_Inner = { "AvailableDebugCharacters", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AALSBaseCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_AvailableDebugCharacters = { "AvailableDebugCharacters", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSDebugComponent, AvailableDebugCharacters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableDebugCharacters_MetaData), NewProp_AvailableDebugCharacters_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_DebugFocusCharacter = { "DebugFocusCharacter", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSDebugComponent, DebugFocusCharacter), Z_Construct_UClass_AALSBaseCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugFocusCharacter_MetaData), NewProp_DebugFocusCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_DefaultSkeletalMesh = { "DefaultSkeletalMesh", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSDebugComponent, DefaultSkeletalMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultSkeletalMesh_MetaData), NewProp_DefaultSkeletalMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UALSDebugComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_OwnerCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bSlomo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowHud,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_bShowCharacterInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_DebugSkeletalMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_AvailableDebugCharacters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_AvailableDebugCharacters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_DebugFocusCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSDebugComponent_Statics::NewProp_DefaultSkeletalMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UALSDebugComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UALSDebugComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UALSDebugComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UALSDebugComponent_Statics::ClassParams = {
	&UALSDebugComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UALSDebugComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UALSDebugComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UALSDebugComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UALSDebugComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UALSDebugComponent()
{
	if (!Z_Registration_Info_UClass_UALSDebugComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UALSDebugComponent.OuterSingleton, Z_Construct_UClass_UALSDebugComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UALSDebugComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UALSDebugComponent);
UALSDebugComponent::~UALSDebugComponent() {}
// ********** End Class UALSDebugComponent *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h__Script_ALS_System_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UALSDebugComponent, UALSDebugComponent::StaticClass, TEXT("UALSDebugComponent"), &Z_Registration_Info_UClass_UALSDebugComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UALSDebugComponent), 1080768406U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h__Script_ALS_System_2689800780(TEXT("/Script/ALS_System"),
	Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h__Script_ALS_System_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h__Script_ALS_System_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
