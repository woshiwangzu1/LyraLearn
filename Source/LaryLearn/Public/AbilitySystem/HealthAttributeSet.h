// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "HealthAttributeSet.generated.h"
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Damage);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_DamageImmunity);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_DamageSelfDestruct);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_FellOutOfWorld);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Lyra_Damage_Message);

struct FGameplayAttributeData;

/**
 * 
 */
UCLASS(BlueprintType)
class LARYLEARN_API UHealthAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
public:
	UHealthAttributeSet();

	ATTRIBUTE_ACCESSORS(UHealthAttributeSet,Health);
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet,MaxHealth);
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet,Healing);
	// Delegate to broadcast when the health attribute reaches zero.
	mutable FLyraAttributeEvent OnOutOfHealth;

protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	
	/*PostGameplayEffectExecute仅在即刻(Instant)GameplayEffect对Attribute的BaseValue修改之后触发,
	 *当GameplayEffect对其修改时,这就是一个处理更多Attribute操作的有效位置.*/
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	/*PreAttributeChange是AttributeSet中的主要函数之一,
	 *其在修改发生前响应Attribute的CurrentValue变化, 其是通过引用参数NewValue限制(Clamp)CurrentValue即将进行的修改的理想位置.*/
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;
	
private:
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing= OnRep_Health, Category="Lyra|Health",meta=(HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing= OnRep_Health, Category="Lyra|Health",meta=(AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;

	// Used to track when the health reaches 0.
	bool bOutOfHealth;

private:
	// Incoming healing. This is mapped directly to +Health
	UPROPERTY(BlueprintReadOnly, Category="Lyra|Health", Meta=(AllowPrivateAccess=true))
	FGameplayAttributeData Healing;

	// Incoming damage. This is mapped directly to -Health
	UPROPERTY(BlueprintReadOnly, Category="Lyra|Health", Meta=(HideFromModifiers, AllowPrivateAccess=true))
	FGameplayAttributeData Damage;
	
};
