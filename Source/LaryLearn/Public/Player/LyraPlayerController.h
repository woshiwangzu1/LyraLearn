// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonPlayerController.h"
#include "LyraPlayerController.generated.h"

class ULyraSettingsShared;
class ALyraPlayerState;
class ULyraAbilitySystemComponent;
class ALyraHUD;
class APawn;
/**
 * ALyraPlayerController
 *
 *	The base player controller class used by this project.
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base player controller class used by this project."))
class LARYLEARN_API ALyraPlayerController : public ACommonPlayerController
{
	GENERATED_BODY()

public:

	ALyraPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Lyra|PlayerController")
	ALyraPlayerState* GetLyraPlayerState() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|PlayerController")
	ULyraAbilitySystemComponent* GetLyraAbilitySystemComponent() const;

	//~AActor interface
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~End of AActor interface

	//~AController interface
	virtual void OnUnPossess() override;
	//~End of AController interface

	//~APlayerController interface
	virtual void ReceivedPlayer() override;
	virtual void PlayerTick(float DeltaTime) override;
	//~End of APlayerController interface

	//~ACommonPlayerController interface
	virtual void OnPossess(APawn* InPawn) override;
	//~End of ACommonPlayerController interface

private:
	UPROPERTY()
	APlayerState* LastSeenPlayerState;
	
protected:
	// Called when the player state is set or cleared
	virtual void OnPlayerStateChanged();

private:
	void BroadcastOnPlayerStateChanged();

protected:
	//~AController interface
	virtual void InitPlayerState() override;
	virtual void CleanupPlayerState() override;
	virtual void OnRep_PlayerState() override;
	//~End of AController interface

	//~APlayerController interface
	virtual void SetPlayer(UPlayer* InPlayer) override;
	virtual void AddCheats(bool bForce) override;

	virtual void UpdateForceFeedback(IInputInterface* InputInterface, const int32 ControllerId) override;
	virtual void UpdateHiddenComponents(const FVector& ViewLocation, TSet<FPrimitiveComponentId>& OutHiddenComponents) override;

	virtual void PreProcessInput(const float DeltaTime, const bool bGamePaused) override;
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;
	//~End of APlayerController interface

	bool bHideViewTargetPawnNextFrame = false;

	
};

