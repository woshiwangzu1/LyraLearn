// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BaseAttributeSet.h"

UBaseAttributeSet::UBaseAttributeSet()
{
}

UWorld* UBaseAttributeSet::GetWorld() const
{
	const UObject* Outer = GetOuter();
	check(Outer);
	
	return Outer->GetWorld();
}

ULyraAbilitySystemComponent* UBaseAttributeSet::GetLyraAbilitySystemComponent() const
{
	return Cast<ULyraAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}
