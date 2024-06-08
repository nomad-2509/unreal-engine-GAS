// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"

#include "base_player_state.generated.h"

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

};
