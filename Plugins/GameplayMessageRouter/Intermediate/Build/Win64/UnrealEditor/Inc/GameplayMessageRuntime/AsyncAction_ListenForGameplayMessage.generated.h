// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAsyncAction_ListenForGameplayMessage;
struct FGameplayTag;
class UObject;
class UScriptStruct;
enum class EGameplayMessageMatch : uint8;
#ifdef GAMEPLAYMESSAGERUNTIME_AsyncAction_ListenForGameplayMessage_generated_h
#error "AsyncAction_ListenForGameplayMessage.generated.h already included, missing '#pragma once' in AsyncAction_ListenForGameplayMessage.h"
#endif
#define GAMEPLAYMESSAGERUNTIME_AsyncAction_ListenForGameplayMessage_generated_h

#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_19_DELEGATE \
struct _Script_GameplayMessageRuntime_eventAsyncGameplayMessageDelegate_Parms \
{ \
	UAsyncAction_ListenForGameplayMessage* ProxyObject; \
	FGameplayTag ActualChannel; \
}; \
static inline void FAsyncGameplayMessageDelegate_DelegateWrapper(const FMulticastScriptDelegate& AsyncGameplayMessageDelegate, UAsyncAction_ListenForGameplayMessage* ProxyObject, FGameplayTag ActualChannel) \
{ \
	_Script_GameplayMessageRuntime_eventAsyncGameplayMessageDelegate_Parms Parms; \
	Parms.ProxyObject=ProxyObject; \
	Parms.ActualChannel=ActualChannel; \
	AsyncGameplayMessageDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_SPARSE_DATA
#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execListenForGameplayMessages);


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execListenForGameplayMessages);


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAsyncAction_ListenForGameplayMessage(); \
	friend struct Z_Construct_UClass_UAsyncAction_ListenForGameplayMessage_Statics; \
public: \
	DECLARE_CLASS(UAsyncAction_ListenForGameplayMessage, UCancellableAsyncAction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMessageRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAsyncAction_ListenForGameplayMessage)


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUAsyncAction_ListenForGameplayMessage(); \
	friend struct Z_Construct_UClass_UAsyncAction_ListenForGameplayMessage_Statics; \
public: \
	DECLARE_CLASS(UAsyncAction_ListenForGameplayMessage, UCancellableAsyncAction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMessageRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAsyncAction_ListenForGameplayMessage)


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAsyncAction_ListenForGameplayMessage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAsyncAction_ListenForGameplayMessage) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAsyncAction_ListenForGameplayMessage); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAsyncAction_ListenForGameplayMessage); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAsyncAction_ListenForGameplayMessage(UAsyncAction_ListenForGameplayMessage&&); \
	NO_API UAsyncAction_ListenForGameplayMessage(const UAsyncAction_ListenForGameplayMessage&); \
public:


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAsyncAction_ListenForGameplayMessage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAsyncAction_ListenForGameplayMessage(UAsyncAction_ListenForGameplayMessage&&); \
	NO_API UAsyncAction_ListenForGameplayMessage(const UAsyncAction_ListenForGameplayMessage&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAsyncAction_ListenForGameplayMessage); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAsyncAction_ListenForGameplayMessage); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAsyncAction_ListenForGameplayMessage)


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_21_PROLOG
#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_SPARSE_DATA \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_RPC_WRAPPERS \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_INCLASS \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_SPARSE_DATA \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_INCLASS_NO_PURE_DECLS \
	FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPLAYMESSAGERUNTIME_API UClass* StaticClass<class UAsyncAction_ListenForGameplayMessage>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LaryLearn_Plugins_GameplayMessageRouter_Source_GameplayMessageRuntime_Public_GameFramework_AsyncAction_ListenForGameplayMessage_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
