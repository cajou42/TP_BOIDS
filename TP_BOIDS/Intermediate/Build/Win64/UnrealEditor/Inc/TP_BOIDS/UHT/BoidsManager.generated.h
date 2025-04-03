// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BoidsManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TP_BOIDS_BoidsManager_generated_h
#error "BoidsManager.generated.h already included, missing '#pragma once' in BoidsManager.h"
#endif
#define TP_BOIDS_BoidsManager_generated_h

#define FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoidsManager(); \
	friend struct Z_Construct_UClass_ABoidsManager_Statics; \
public: \
	DECLARE_CLASS(ABoidsManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TP_BOIDS"), NO_API) \
	DECLARE_SERIALIZER(ABoidsManager)


#define FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABoidsManager(ABoidsManager&&); \
	ABoidsManager(const ABoidsManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidsManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidsManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoidsManager) \
	NO_API virtual ~ABoidsManager();


#define FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h_10_PROLOG
#define FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h_13_INCLASS_NO_PURE_DECLS \
	FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TP_BOIDS_API UClass* StaticClass<class ABoidsManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TP_BOIDS_Source_TP_BOIDS_BoidsManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
