// Fill out your copyright notice in the Description page of Project Settings.


#include "src/game/base_player_state.h"

#include "ability_system/attributes/BASE_attribute_set.h"
#include "ability_system/attributes/CORE_attribute_set.h"
#include "ability_system/attributes/BATTLE_attribute_set.h"
#include "ability_system/attributes/COMMON_attribute_set.h"


Abase_player_state::Abase_player_state()
{
	// Ability System Component
	ability_system_component = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ability_system_component->SetIsReplicated(true);
	ability_system_component->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	NetUpdateFrequency = 30.f;

	// Attribute Sets
	// Initializing all 3 attribute sets
	BASE_attribute_set = CreateDefaultSubobject<UBASE_attribute_set>(TEXT("BASE_attribute_set"));
	CORE_attribute_set = CreateDefaultSubobject<UCORE_attribute_set>(TEXT("CORE_attribute_set"));
	BATTLE_attribute_set = CreateDefaultSubobject<UBATTLE_attribute_set>(TEXT("BATTLE_attribute_set"));
	COMMON_attribute_set = CreateDefaultSubobject<UCOMMON_attribute_set>(TEXT("COMMON_attribute_set"));

}
