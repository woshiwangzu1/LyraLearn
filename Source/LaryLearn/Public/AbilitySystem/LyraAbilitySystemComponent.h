// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LyraAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class LARYLEARN_API ULyraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	ULyraAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;
};
