// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

#include "Net/UnrealNetwork.h"

#include "BATTLE_attribute_set.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UBATTLE_attribute_set : public UAttributeSet
{
	GENERATED_BODY()

	/*
		armor - Percentage; min - 0%, max - 100%
		max_armor
		armor_meta					// META
		magic_resist - Percentage; min - 0%, max - 100%
		max_magic_resist
		magic_resist_meta			// META

		movement_speed - In-game character movement speed; min - 0 u/s ; max - 2000 u/s
		max_movement_speed
		movement_speed_meta			// META
		attack_speed - Percentage factor of character animation play rate; min - 0% (immobile), max - 500%
		max_attack_speed
		attack_speed_meta			// META

		cooldown_reduction - Percentage factor of ability cooldowns; min - 20% or 0.2 secs (whichever is lower)
		max_cooldown_reduction
		cooldown_reduction_meta		// META
		spell_amplification - Percentage factor, Enhances ANY magic damage; min - 0%
		max_spell_amplification
		spell_amplification_meta	// META
	*/

// Properties
public:
	// Armor
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|armor", ReplicatedUsing = on_rep_armor)
		FGameplayAttributeData armor;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, armor);

	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|armor", ReplicatedUsing = on_rep_max_armor)
		FGameplayAttributeData max_armor;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, max_armor);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|armor|meta")
		FGameplayAttributeData armor_meta;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, armor_meta);

	// Magic Resistance
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|magic_resist", ReplicatedUsing = on_rep_magic_resist)
		FGameplayAttributeData magic_resist;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, magic_resist);

	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|magic_resist", ReplicatedUsing = on_rep_max_magic_resist)
		FGameplayAttributeData max_magic_resist;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, max_magic_resist);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|magic_resist|meta")
		FGameplayAttributeData magic_resist_meta;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, magic_resist_meta);

	// Movement Speed
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|movement_speed", ReplicatedUsing = on_rep_movement_speed)
		FGameplayAttributeData movement_speed;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, movement_speed);

	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|movement_speed", ReplicatedUsing = on_rep_max_movement_speed)
		FGameplayAttributeData max_movement_speed;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, max_movement_speed);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|movement_speed|meta")
		FGameplayAttributeData movement_speed_meta;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, movement_speed_meta);

	// Attack Speed
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|attack_speed", ReplicatedUsing = on_rep_attack_speed)
		FGameplayAttributeData attack_speed;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, attack_speed);

	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|attack_speed", ReplicatedUsing = on_rep_max_attack_speed)
		FGameplayAttributeData max_attack_speed;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, max_attack_speed);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|attack_speed|meta")
		FGameplayAttributeData attack_speed_meta;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, attack_speed_meta);

	// Cooldown Reduction
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|cooldown_reduction", ReplicatedUsing = on_rep_cooldown_reduction)
		FGameplayAttributeData cooldown_reduction;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, cooldown_reduction);

	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|cooldown_reduction", ReplicatedUsing = on_rep_max_cooldown_reduction)
		FGameplayAttributeData max_cooldown_reduction;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, max_cooldown_reduction);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|cooldown_reduction|meta")
		FGameplayAttributeData cooldown_reduction_meta;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, cooldown_reduction_meta);

	// Spell Amplification
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|spell_amplification", ReplicatedUsing = on_rep_spell_amplification)
		FGameplayAttributeData spell_amplification;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, spell_amplification);

	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|spell_amplification", ReplicatedUsing = on_rep_max_spell_amplification)
		FGameplayAttributeData max_spell_amplification;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, max_spell_amplification);

		// meta
	UPROPERTY(BlueprintReadOnly, Category = "BATTLE_attribute_set|spell_amplification|meta")
		FGameplayAttributeData spell_amplification_meta;
	ATTRIBUTE_ACCESSORS(UBATTLE_attribute_set, spell_amplification_meta);


// Methods
public:
	UBATTLE_attribute_set();

	virtual void PreAttributeChange(const FGameplayAttribute & attribute, float & new_value) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// METHODS FOR REPLICATION
	UFUNCTION()
		virtual void on_rep_armor(const FGameplayAttributeData& old_armor);

	UFUNCTION()
		virtual void on_rep_max_armor(const FGameplayAttributeData& old_max_armor);

	UFUNCTION()
		virtual void on_rep_magic_resist(const FGameplayAttributeData& old_magic_resist);

	UFUNCTION()
		virtual void on_rep_max_magic_resist(const FGameplayAttributeData& old_max_magic_resist);

	UFUNCTION()
		virtual void on_rep_movement_speed(const FGameplayAttributeData& old_movement_speed);

	UFUNCTION()
		virtual void on_rep_max_movement_speed(const FGameplayAttributeData& old_max_movement_speed);

	UFUNCTION()
		virtual void on_rep_attack_speed(const FGameplayAttributeData& old_attack_speed);

	UFUNCTION()
		virtual void on_rep_max_attack_speed(const FGameplayAttributeData& old_max_attack_speed);

	UFUNCTION()
		virtual void on_rep_cooldown_reduction(const FGameplayAttributeData& old_cooldown_reduction);

	UFUNCTION()
		virtual void on_rep_max_cooldown_reduction(const FGameplayAttributeData& old_max_cooldown_reduction);

	UFUNCTION()
		virtual void on_rep_spell_amplification(const FGameplayAttributeData& old_spell_amplification);

	UFUNCTION()
		virtual void on_rep_max_spell_amplification(const FGameplayAttributeData& old_max_spell_amplification);

};
