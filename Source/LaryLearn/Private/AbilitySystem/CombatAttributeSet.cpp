// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CombatAttributeSet.h"

#include "Net/UnrealNetwork.h"

UCombatAttributeSet::UCombatAttributeSet()
	:BaseDamage(0.0f)
	,BaseHeal(0.0f)
{
}

void UCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet,BaseDamage,COND_OwnerOnly,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet,BaseHeal,COND_OwnerOnly,REPNOTIFY_Always);
}



void UCombatAttributeSet::OnRep_BaseDamage(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet,BaseDamage,OldValue);
}

void UCombatAttributeSet::OnRep_BaseHeal(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet,BaseHeal,OldValue);
}
