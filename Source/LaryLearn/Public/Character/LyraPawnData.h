// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LyraPawnData.generated.h"

class ULyraInputConfig;
class ULyraAbilitySet;
/**
 * 
 */
UCLASS()
class LARYLEARN_API ULyraPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	ULyraPawnData(const FObjectInitializer& ObjectInitializer);
	
public:
	// Class to instantiate for this pawn (should usually derive from ALyraPawn or ALyraCharacter).
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Pawn")
	TSubclassOf<APawn> PawnClass;

	// Ability sets to grant to this pawn's ability system.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Abilities")
	TArray<ULyraAbilitySet*> AbilitySets;
	
	// Input configuration used by player controlled pawns to create input mappings and bind input actions.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Input")
	ULyraInputConfig* InputConfig;
	
};
