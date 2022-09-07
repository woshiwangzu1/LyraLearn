// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/LyraGameplayAbility.h"

ULyraGameplayAbility::ULyraGameplayAbility(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	
}

ULyraAbilitySystemComponent* ULyraGameplayAbility::GetLyraAbilitySystemComponentFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<ULyraAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get()): nullptr);
}

ALyraCharacter* ULyraGameplayAbility::GetLyraCharacterFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<ALyraCharacter>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}
