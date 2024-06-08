// Fill out your copyright notice in the Description page of Project Settings.


#include "src/game/base_player_state.h"

Abase_player_state::Abase_player_state()
{
	ability_system_component = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ability_system_component->SetIsReplicated(true);
	ability_system_component->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	NetUpdateFrequency = 30.f;

}
