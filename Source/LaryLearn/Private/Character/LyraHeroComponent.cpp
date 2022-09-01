// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LyraHeroComponent.h"

#include "AbilitySystem/LyraAbilitySystemComponent.h"
#include "Character/LyraPawnExtensionComponent.h"
#include "Misc/UObjectToken.h"
#include "Player/LyraPlayerState.h"

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
			PawnExtComp->OnPawnReadyToInitialize_RegisterAndCall(FSimpleMulticastDelegate::FDelegate::CreateUObject(this, &ThisClass::OnPawnReadyToInitialize));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[ULyraHeroComponent::OnRegister] This component has been added to a blueprint whose base class is not a Pawn. To use this component, it MUST be placed on a Pawn Blueprint."));

#if WITH_EDITOR
		if (GIsEditor)
		{
			static const FText Message = NSLOCTEXT("LyraHeroComponent", "NotOnPawnError", "has been added to a blueprint whose base class is not a Pawn. To use this component, it MUST be placed on a Pawn Blueprint. This will cause a crash if you PIE!");
			static const FName HeroMessageLogName = TEXT("LyraHeroComponent");
			
			FMessageLog(HeroMessageLogName).Error()
				->AddToken(FUObjectToken::Create(this, FText::FromString(GetNameSafe(this))))
				->AddToken(FTextToken::Create(Message));
				
			FMessageLog(HeroMessageLogName).Open();
		}
#endif
	}
}

bool ULyraHeroComponent::IsPawnComponentReadyToInitialize() const
{
	return Super::IsPawnComponentReadyToInitialize();
}

void ULyraHeroComponent::OnPawnReadyToInitialize()
{
	if (!ensure(!bPawnHasInitialized))
	{
		// Don't initialize twice
		return;
	}

	APawn* Pawn = GetPawn<APawn>();
	if (!Pawn)
	{
		return;
	}
	const bool bIsLocallyControlled = Pawn->IsLocallyControlled();

	ALyraPlayerState* LyraPS = GetPlayerState<ALyraPlayerState>();
	check(LyraPS);

	const ULyraPawnData* PawnData = nullptr;

	if (ULyraPawnExtensionComponent* PawnExtComp = ULyraPawnExtensionComponent::FindPawnExtensionComponent(Pawn))
	{
		PawnData = PawnExtComp->GetPawnData<ULyraPawnData>();

		// The player state holds the persistent data for this player (state that persists across deaths and multiple pawns).
		// The ability system component and attribute sets live on the player state.
		PawnExtComp->InitializeAbilitySystem(LyraPS->GetLyraAbilitySystemComponent(), LyraPS);
	}

	//@TODO PCLOGIC
	// if (ALyraPlayerController* LyraPC = GetController<ALyraPlayerController>())
	// {
	// 	if (Pawn->InputComponent != nullptr)
	// 	{
	// 		InitializePlayerInput(Pawn->InputComponent);
	// 	}
	// }

	
	//@TODO CameraLogic
	// if (bIsLocallyControlled && PawnData)
	// {
	// 	if (ULyraCameraComponent* CameraComponent = ULyraCameraComponent::FindCameraComponent(Pawn))
	// 	{
	// 		CameraComponent->DetermineCameraModeDelegate.BindUObject(this, &ThisClass::DetermineCameraMode);
	// 	}
	// }

	bPawnHasInitialized = true;
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

