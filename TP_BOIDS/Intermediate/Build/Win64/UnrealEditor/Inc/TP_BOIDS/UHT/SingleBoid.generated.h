// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SingleBoid.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TP_BOIDS_SingleBoid_generated_h
#error "SingleBoid.generated.h already included, missing '#pragma once' in SingleBoid.h"
#endif
#define TP_BOIDS_SingleBoid_generated_h

#define FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASingleBoid(); \
	friend struct Z_Construct_UClass_ASingleBoid_Statics; \
public: \
	DECLARE_CLASS(ASingleBoid, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TP_BOIDS"), NO_API) \
	DECLARE_SERIALIZER(ASingleBoid)


#define FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASingleBoid(ASingleBoid&&); \
	ASingleBoid(const ASingleBoid&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASingleBoid); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASingleBoid); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASingleBoid) \
	NO_API virtual ~ASingleBoid();


#define FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h_9_PROLOG
#define FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h_12_INCLASS_NO_PURE_DECLS \
	FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TP_BOIDS_API UClass* StaticClass<class ASingleBoid>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TP_BOIDS_Source_TP_BOIDS_SingleBoid_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
