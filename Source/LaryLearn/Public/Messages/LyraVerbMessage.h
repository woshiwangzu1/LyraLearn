#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "../../../../Intermediate/Build/Win64/UnrealEditor/Development/LaryLearn/Definitions.LaryLearn.h"

#include "LyraVerbMessage.generated.h"

USTRUCT(BlueprintType)
struct FLyraVerbMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	FGameplayTag Verb;

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	UObject* Instigator = nullptr;

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	UObject* Target = nullptr;

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	FGameplayTagContainer InstigatorTags;
	
	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	FGameplayTagContainer TargetTags;

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	FGameplayTagContainer ContextTags;

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	double Magnitude = 1.0;

	LARYLEARN_API FString ToString() const;
};
