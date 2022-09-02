// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/LyraAbilitySystemComponent.h"

ULyraAbilitySystemComponent::ULyraAbilitySystemComponent(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	InputPressedSpecHandles.Reset();
	InputReleasedSpecHandles.Reset();
	InputHeldSpecHandles.Reset();

	// FMemory::Memset(ActivationGroupCounts, 0, sizeof(ActivationGroupCounts));
}

void ULyraAbilitySystemComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// if (ULyraGlobalAbilitySystem* GlobalAbilitySystem = UWorld::GetSubsystem<ULyraGlobalAbilitySystem>(GetWorld()))
	// {
	// 	GlobalAbilitySystem->UnregisterASC(this);
	// }
}

void ULyraAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
}

void ULyraAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& AbilitySpec : ActivatableAbilities.Items)
		{
			if (AbilitySpec.Ability && (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)))
			{
				InputPressedSpecHandles.AddUnique(AbilitySpec.Handle);
				InputHeldSpecHandles.AddUnique(AbilitySpec.Handle);
			}
		}
	}
}

void ULyraAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& AbilitySpec : ActivatableAbilities.Items)
		{
			if (AbilitySpec.Ability && (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)))
			{
				InputReleasedSpecHandles.AddUnique(AbilitySpec.Handle);
				InputHeldSpecHandles.Remove(AbilitySpec.Handle);
			}
		}
	}
}
