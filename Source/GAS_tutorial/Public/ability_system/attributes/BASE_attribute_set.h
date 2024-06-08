// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

#include "Net/UnrealNetwork.h"

#include "BASE_attribute_set.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UBASE_attribute_set : public UAttributeSet
{
	GENERATED_BODY()

	/*
		health
		max_health
		health_regen
		health_meta		// META

		mana
		max_mana
		mana_regen
		mana_meta		// META

		stamina
		max_stamina
		stamina_regen
		stamina_meta	// META
	*/

// Properties
public:
	// Health
	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|health", ReplicatedUsing = on_rep_health)
		FGameplayAttributeData health;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, health);

	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|health", ReplicatedUsing = on_rep_max_health)
		FGameplayAttributeData max_health;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, max_health);

	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|health", ReplicatedUsing = on_rep_health_regen)
		FGameplayAttributeData health_regen;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, health_regen);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|health|meta")
		FGameplayAttributeData health_meta;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, health_meta);

	// Mana
	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|mana", ReplicatedUsing = on_rep_mana)
		FGameplayAttributeData mana;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, mana);

	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|mana", ReplicatedUsing = on_rep_max_mana)
		FGameplayAttributeData max_mana;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, max_mana);

	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|mana", ReplicatedUsing = on_rep_mana_regen)
		FGameplayAttributeData mana_regen;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, mana_regen);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|mana|meta")
		FGameplayAttributeData mana_meta;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, mana_meta);

	// Stamina
	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|stamina", ReplicatedUsing = on_rep_stamina)
		FGameplayAttributeData stamina;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, stamina);

	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|stamina", ReplicatedUsing = on_rep_max_stamina)
		FGameplayAttributeData max_stamina;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, max_stamina);

	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|stamina", ReplicatedUsing = on_rep_stamina_regen)
		FGameplayAttributeData stamina_regen;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, stamina_regen);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BASE_attribute_set|stamina|meta")
		FGameplayAttributeData stamina_meta;
	ATTRIBUTE_ACCESSORS(UBASE_attribute_set, stamina_meta);


// Methods
public:
	UBASE_attribute_set();

	virtual void PreAttributeChange(const FGameplayAttribute & attribute, float & new_value) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// METHODS FOR REPLICATION
	UFUNCTION()
		virtual void on_rep_health(const FGameplayAttributeData& old_health);

	UFUNCTION()
		virtual void on_rep_max_health(const FGameplayAttributeData& old_max_health);

	UFUNCTION()
		virtual void on_rep_health_regen(const FGameplayAttributeData& old_health_regen);

	UFUNCTION()
		virtual void on_rep_mana(const FGameplayAttributeData& old_mana);

	UFUNCTION()
		virtual void on_rep_max_mana(const FGameplayAttributeData& old_max_mana);

	UFUNCTION()
		virtual void on_rep_mana_regen(const FGameplayAttributeData& old_mana_regen);

	UFUNCTION()
		virtual void on_rep_stamina(const FGameplayAttributeData& old_stamina);

	UFUNCTION()
		virtual void on_rep_max_stamina(const FGameplayAttributeData& old_max_stamina);

	UFUNCTION()
		virtual void on_rep_stamina_regen(const FGameplayAttributeData& old_stamina_regen);

};
