// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VRHELLOWORLD_VRCharacter_generated_h
#error "VRCharacter.generated.h already included, missing '#pragma once' in VRCharacter.h"
#endif
#define VRHELLOWORLD_VRCharacter_generated_h

#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_SPARSE_DATA
#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_RPC_WRAPPERS
#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRCharacter(); \
	friend struct Z_Construct_UClass_AVRCharacter_Statics; \
public: \
	DECLARE_CLASS(AVRCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/vrHelloWorld"), NO_API) \
	DECLARE_SERIALIZER(AVRCharacter)


#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAVRCharacter(); \
	friend struct Z_Construct_UClass_AVRCharacter_Statics; \
public: \
	DECLARE_CLASS(AVRCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/vrHelloWorld"), NO_API) \
	DECLARE_SERIALIZER(AVRCharacter)


#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVRCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRCharacter(AVRCharacter&&); \
	NO_API AVRCharacter(const AVRCharacter&); \
public:


#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRCharacter(AVRCharacter&&); \
	NO_API AVRCharacter(const AVRCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVRCharacter)


#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AVRCharacter, Camera); } \
	FORCEINLINE static uint32 __PPO__VRRoot() { return STRUCT_OFFSET(AVRCharacter, VRRoot); } \
	FORCEINLINE static uint32 __PPO__DestinationMarker() { return STRUCT_OFFSET(AVRCharacter, DestinationMarker); } \
	FORCEINLINE static uint32 __PPO__MaxTeleportDistance() { return STRUCT_OFFSET(AVRCharacter, MaxTeleportDistance); } \
	FORCEINLINE static uint32 __PPO__TeleportFadeTime() { return STRUCT_OFFSET(AVRCharacter, TeleportFadeTime); } \
	FORCEINLINE static uint32 __PPO__TeleportProjectionExtent() { return STRUCT_OFFSET(AVRCharacter, TeleportProjectionExtent); }


#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_12_PROLOG
#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_SPARSE_DATA \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_RPC_WRAPPERS \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_INCLASS \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_SPARSE_DATA \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_INCLASS_NO_PURE_DECLS \
	vrHelloWorld_Source_vrHelloWorld_VRCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VRHELLOWORLD_API UClass* StaticClass<class AVRCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID vrHelloWorld_Source_vrHelloWorld_VRCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
