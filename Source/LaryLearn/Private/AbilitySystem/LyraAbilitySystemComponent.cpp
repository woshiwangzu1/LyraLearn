// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/LyraAbilitySystemComponent.h"

ULyraAbilitySystemComponent::ULyraAbilitySystemComponent(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

void ULyraAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
}
