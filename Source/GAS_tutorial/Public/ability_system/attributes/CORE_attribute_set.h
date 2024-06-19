// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

#include "Net/UnrealNetwork.h"

#include "CORE_attribute_set.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UCORE_attribute_set : public UAttributeSet
{
	GENERATED_BODY()

	/*
		strength
		max_strength
		strength_meta		// META

		agility
		max_agility
		agility_meta		// META

		intelligence
		max_intelligence
		intelligence_meta		// META

	*/

// Properties
public:
	// Strength
	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|strength", ReplicatedUsing = on_rep_strength)
		FGameplayAttributeData strength;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, strength);

	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|strength", ReplicatedUsing = on_rep_max_strength)
		FGameplayAttributeData max_strength;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, max_strength);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|strength|meta")
		FGameplayAttributeData strength_meta;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, strength_meta);

	// Agility
	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|agility", ReplicatedUsing = on_rep_agility)
		FGameplayAttributeData agility;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, agility);

	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|agility", ReplicatedUsing = on_rep_max_agility)
		FGameplayAttributeData max_agility;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, max_agility);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|agility|meta")
		FGameplayAttributeData agility_meta;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, agility_meta);

	// Intelligence
	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|intelligence", ReplicatedUsing = on_rep_intelligence)
		FGameplayAttributeData intelligence;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, intelligence);

	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|intelligence", ReplicatedUsing = on_rep_max_intelligence)
		FGameplayAttributeData max_intelligence;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, max_intelligence);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "CORE_attribute_set|intelligence|meta")
		FGameplayAttributeData intelligence_meta;
	ATTRIBUTE_ACCESSORS(UCORE_attribute_set, intelligence_meta);

// Methods
public:
	UCORE_attribute_set();

	virtual void PreAttributeChange(const FGameplayAttribute & attribute, float & new_value) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// METHODS FOR REPLICATION
	UFUNCTION()
		virtual void on_rep_strength(const FGameplayAttributeData& old_strength);

	UFUNCTION()
		virtual void on_rep_max_strength(const FGameplayAttributeData& old_max_strength);

	UFUNCTION()
		virtual void on_rep_agility(const FGameplayAttributeData& old_agility);

	UFUNCTION()
		virtual void on_rep_max_agility(const FGameplayAttributeData& old_max_agility);

	UFUNCTION()
		virtual void on_rep_intelligence(const FGameplayAttributeData& old_intelligence);

	UFUNCTION()
		virtual void on_rep_max_intelligence(const FGameplayAttributeData& old_max_intelligence);

};
