// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayCueInterface.h"
#include "GameplayTagAssetInterface.h"
#include "LyraHealthComponent.h"
#include "LyraHeroComponent.h"
#include "ModularCharacter.h"
#include "LyraCharacter.generated.h"


class ULyraPawnExtensionComponent;
struct FGameplayTag;
struct FGameplayTagContainer;
class ULyraAbilitySystemComponent;
class ALyraPlayerState;
class ALyraPlayerController;
/**
 * FLyraReplicatedAcceleration: Compressed representation of acceleration
 */
USTRUCT()
struct FLyraReplicatedAcceleration
{
	GENERATED_BODY()

	UPROPERTY()
	uint8 AccelXYRadians = 0; // Direction of XY accel component, quantized to represent [0, 2*pi]

	UPROPERTY()
	uint8 AccelXYMagnitude = 0; //Accel rate of XY component, quantized to represent [0, MaxAcceleration]

	UPROPERTY()
	int8 AccelZ = 0; // Raw Z accel rate component, quantized to represent [-MaxAcceleration, MaxAcceleration]
};

/**
 * ALyraCharacter
 *
 *	The base character pawn class used by this project.
 *	Responsible for sending events to pawn components.
 *	New behavior should be added via pawn components when possible.
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base character pawn class used by this project."))
class LARYLEARN_API ALyraCharacter : public AModularCharacter, public IAbilitySystemInterface, public IGameplayCueInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	ALyraCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
	ALyraPlayerController* GetLyraPlayerController() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
	ALyraPlayerState* GetLyraPlayerState() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
	ULyraAbilitySystemComponent* GetLyraAbilitySystemComponent() const;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//~IGameplayTagAssetInterface
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;
	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	//~End IGameplayTagAssetInterface
	
	//~AActor interface
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Reset() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker) override;
	//~End of AActor interface
	
	//~APawn interface
	virtual void NotifyControllerChanged() override;
	//~End of APawn interface

protected:

	virtual void OnAbilitySystemInitialized();
	virtual void OnAbilitySystemUninitialized();

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	virtual void OnRep_Controller() override;
	virtual void OnRep_PlayerState() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void InitializeGameplayTags();

	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;

	// Begins the death sequence for the character (disables collision, disables movement, etc...)
	UFUNCTION()
	virtual void OnDeathStarted(AActor* OwningActor);

	// Ends the death sequence for the character (detaches controller, destroys pawn, etc...)
	UFUNCTION()
	virtual void OnDeathFinished(AActor* OwningActor);

	void DisableMovementAndCollision();
	void DestroyDueToDeath();
	void UninitAndDestroy();

	// Called when the death sequence for the character has completed
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnDeathFinished"))
	void K2_OnDeathFinished();

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override;
	void SetMovementModeTag(EMovementMode MovementMode, uint8 CustomMovementMode, bool bTagEnabled);

	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;
	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

	virtual bool CanJumpInternal_Implementation() const;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
	ULyraPawnExtensionComponent* PawnExtComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
	ULyraHealthComponent* HealthComponent;
	

	
	//
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
	// ULyraCameraComponent* CameraComponent;

	UPROPERTY(Transient, ReplicatedUsing = OnRep_ReplicatedAcceleration)
	FLyraReplicatedAcceleration ReplicatedAcceleration;

private:
	UFUNCTION()
	void OnRep_ReplicatedAcceleration();
};
