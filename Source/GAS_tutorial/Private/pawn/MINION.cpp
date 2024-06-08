// Fill out your copyright notice in the Description page of Project Settings.


#include "pawn/MINION.h"


AMINION::AMINION()
{
	ability_system_component = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ability_system_component->SetIsReplicated(true);
	ability_system_component->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

}

void AMINION::BeginPlay()
{
	Super::BeginPlay();

	if (ability_system_component) ability_system_component->InitAbilityActorInfo(this, this);

}
