// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "CombatAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LARYLEARN_API UCombatAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
public:

	UCombatAttributeSet();

	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, BaseDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, BaseHeal);

protected:
	UFUNCTION()
	void OnRep_BaseDamage(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BaseHeal(const FGameplayAttributeData& OldValue);
private:
	// The base amount of damage to apply in the damage execution.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseDamage, Category = "Lyra|Combat", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData BaseDamage;
	// The base amount of damage to apply in the damage execution.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseHeal, Category = "Lyra|Combat", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData BaseHeal;
};
