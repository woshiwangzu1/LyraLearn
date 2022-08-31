// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/LyraPawnComponent.h"
#include "LyraPawnExtensionComponent.generated.h"

/**
 * 
 */
UCLASS()
class LARYLEARN_API ULyraPawnExtensionComponent : public ULyraPawnComponent
{
	GENERATED_BODY()
public:
	ULyraPawnExtensionComponent(const FObjectInitializer& ObjectInitializer);

	static ULyraPawnExtensionComponent* FindPawnExtensionComponent(const AActor* Actor)
	{
		return (Actor ? Actor->FindComponentByClass<ULyraPawnExtensionComponent>() : nullptr);
	}

protected:

	
};
