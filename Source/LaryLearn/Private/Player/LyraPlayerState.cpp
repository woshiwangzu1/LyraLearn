// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LyraPlayerState.h"

#include "AbilitySystem/CombatAttributeSet.h"
#include "AbilitySystem/HealthAttributeSet.h"

ALyraPlayerState::ALyraPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<ULyraAbilitySystemComponent>(this,TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	CreateDefaultSubobject<UHealthAttributeSet>(TEXT("HealthSet"));
	CreateDefaultSubobject<UCombatAttributeSet>(TEXT("CombatSet"));
	NetUpdateFrequency = 100.0f;
	
}


UAbilitySystemComponent* ALyraPlayerState::GetAbilitySystemComponent() const
{
	return GetLyraAbilitySystemComponent();
}
