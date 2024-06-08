// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"

#include "base_player_state.generated.h"


class UBASE_attribute_set;
class UCORE_attribute_set;
class UBATTLE_attribute_set;

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API Abase_player_state : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	Abase_player_state();


// ============
// ABILITY SYSTEM COMPONENT

// Properties
protected:
	UAbilitySystemComponent * ability_system_component;

// Methods
public:
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const
	{ return ability_system_component; };


// ============
// ATTRIBUTE SETS

// Properties
protected:
	UPROPERTY()
	UBASE_attribute_set * BASE_attribute_set;

	UPROPERTY()
	UCORE_attribute_set * CORE_attribute_set;

	UPROPERTY()
	UBATTLE_attribute_set * BATTLE_attribute_set;

// Methods
	UBASE_attribute_set * get_BASE_attribute_set()
	{ return BASE_attribute_set; };

	UCORE_attribute_set * get_CORE_attribute_set()
	{ return CORE_attribute_set; };

	UBATTLE_attribute_set * get_BATTLE_attribute_set()
	{ return BATTLE_attribute_set; };


};
