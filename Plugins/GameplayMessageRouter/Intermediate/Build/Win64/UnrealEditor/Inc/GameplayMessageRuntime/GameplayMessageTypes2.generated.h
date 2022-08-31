// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMEPLAYMESSAGERUNTIME_GameplayMessageTypes2_generated_h
#error "GameplayMessageTypes2.generated.h already included, missing '#pragma once' in GameplayMessageTypes2.h"
#endif
#define GAMEPLAYMESSAGERUNTIME_GameplayMessageTypes2_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_GameplayMessageTypes2_h


#define FOREACH_ENUM_EGAMEPLAYMESSAGEMATCH(op) \
	op(EGameplayMessageMatch::ExactMatch) \
	op(EGameplayMessageMatch::PartialMatch) 

enum class EGameplayMessageMatch : uint8;
template<> GAMEPLAYMESSAGERUNTIME_API UEnum* StaticEnum<EGameplayMessageMatch>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
