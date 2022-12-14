// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystemInterface.h"
#include "Character/LyraPawnComponent.h"
#include "LyraHeroComponent.generated.h"


struct FGameplayTag;
struct FInputActionValue;
/**
 * 
 */
UCLASS(Blueprintable, Meta=(BlueprintSpawnableComponent))
class LARYLEARN_API ULyraHeroComponent : public ULyraPawnComponent
{
	GENERATED_BODY()
public:

	ULyraHeroComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category="Lyra|Hero")
	static ULyraHeroComponent* FindHeroComponent(const AActor* Actor){return  (Actor? Actor->FindComponentByClass<ULyraHeroComponent>() : nullptr);}


	//@TODO CameraMode
	// void SetAbilityCameraMode(TSubclassOf<ULyraCameraMode> CameraMode, const FGameplayAbilitySpecHandle& OwningSpecHandle);
	// void ClearAbilityCameraMode(const FGameplayAbilitySpecHandle& OwningSpecHandle);

	//@TODO InputConfig
	// void AddAdditionalInputConfig(const ULyraInputConfig* InputConfig);
	// void RemoveAdditionalInputConfig(const ULyraInputConfig* InputConfig);

	bool HasPawnInitialized() const;

	bool IsReadyToBindInputs() const;

	static const FName NAME_BindInputsNow;

protected:

	virtual void OnRegister() override;

	virtual bool IsPawnComponentReadyToInitialize() const override;
	void OnPawnReadyToInitialize();
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void InitializePlayerInput(UInputComponent* PlayerInputComponent);

	void Input_AbilityInputTagPressed(FGameplayTag InputTag);
	void Input_AbilityInputTagReleased(FGameplayTag InputTag);
	
	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_LookMouse(const FInputActionValue& InputActionValue);
	void Input_LookStick(const FInputActionValue& InputActionValue);
	void Input_Crouch(const FInputActionValue& InputActionValue);
	void Input_AutoRun(const FInputActionValue& InputActionValue);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HeroComponent|Input")
	TObjectPtr<UInputMappingContext> DefaultInputMappingContext = nullptr;

	
protected:
	// True when the pawn has fully finished initialization
	bool bPawnHasInitialized;

	// True when player input bindings have been applyed, will never be true for non-players
	bool bReadyToBindInputs;
};
