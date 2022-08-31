// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LyraHeroComponent.h"

#include "Character/LyraPawnExtensionComponent.h"

namespace LyraHero
{
	static const float LookYawRate = 300.0f;
	static const float LookPitchRate = 165.0f;
}

const FName ULyraHeroComponent::NAME_BindInputsNow("BindInputsNow");


ULyraHeroComponent::ULyraHeroComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	bPawnHasInitialized = false;
	bReadyToBindInputs = false;
}

bool ULyraHeroComponent::HasPawnInitialized() const
{
	return bPawnHasInitialized;
}

bool ULyraHeroComponent::IsReadyToBindInputs() const
{
	return bReadyToBindInputs;
}

void ULyraHeroComponent::OnRegister()
{
	Super::OnRegister();

	if (const APawn* Pawn = GetPawn<APawn>())
	{
		if (ULyraPawnExtensionComponent* PawnExtComp = ULyraPawnExtensionComponent::FindPawnExtensionComponent(Pawn))
		{
			
		}
	}
}

bool ULyraHeroComponent::IsPawnComponentReadyToInitialize() const
{
	return Super::IsPawnComponentReadyToInitialize();
}

void ULyraHeroComponent::BeginPlay()
{
	Super::BeginPlay();
}

void ULyraHeroComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ULyraHeroComponent::InitializePlayerInput(UInputComponent* PlayerInputComponent)
{
}

void ULyraHeroComponent::Input_Move(const FInputActionValue& InputActionValue)
{
}

void ULyraHeroComponent::Input_LookMouse(const FInputActionValue& InputActionValue)
{
}

void ULyraHeroComponent::Input_LookStick(const FInputActionValue& InputActionValue)
{
}

void ULyraHeroComponent::Input_Crouch(const FInputActionValue& InputActionValue)
{
}

void ULyraHeroComponent::Input_AutoRun(const FInputActionValue& InputActionValue)
{
}

