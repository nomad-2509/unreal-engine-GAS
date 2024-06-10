// Fill out your copyright notice in the Description page of Project Settings.


#include "pawn/BASE_CHAR.h"

#include "src/game/base_player_state.h"


// Sets default values
ABASE_CHAR::ABASE_CHAR()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABASE_CHAR::BeginPlay()
{
	Super::BeginPlay();

}

void ABASE_CHAR::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	Abase_player_state * player_state_ = GetPlayerState<Abase_player_state>();

	if (player_state_)
	{
		// Refer player state's ability_system_component with our ASC variable
		ability_system_component = player_state_->GetAbilitySystemComponent();

		// Intended to initialize for AI characters. Re-initializing does not cause problems.
		player_state_->GetAbilitySystemComponent()->InitAbilityActorInfo(player_state_, this);

		initialize_ability_system();
	}

}

// Called every frame
void ABASE_CHAR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABASE_CHAR::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABASE_CHAR::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);

	Abase_player_state * player_state_ = GetPlayerState<Abase_player_state>();

	if (player_state_)
	{
		// Refer player state's ability_system_component with our ASC variable
		ability_system_component = player_state_->GetAbilitySystemComponent();

		player_state_->GetAbilitySystemComponent()->InitAbilityActorInfo(player_state_, this);

		initialize_ability_system();
	}

}

void ABASE_CHAR::initialize_ability_system()
{
	apply_initial_effects();
	give_initial_abilities();
}

void ABASE_CHAR::apply_initial_effects()
{
	FPredictionKey pred_key_;

	if (applied_initial_effects) return;	// Initial effects were already applied

	if (GetLocalRole() != ROLE_Authority) return;		// Can be applied only on Server

	for (auto & effect_class_ : initial_effect_container)
	{
		if (!(effect_class_ && effect_class_.Get()))	// Return if not valid GE class, hence, not initialized
			return;

		FGameplayEffectSpecHandle effect_spec_handle_ = ability_system_component->MakeOutgoingSpec(
			effect_class_,
			1.0f,
			ability_system_component->MakeEffectContext()
		);

		ability_system_component->ApplyGameplayEffectSpecToSelf(
			*effect_spec_handle_.Data.Get(),
			pred_key_
		);
	}

	applied_initial_effects = true;

}

void ABASE_CHAR::give_initial_abilities()
{
	if (given_initial_abilities) return;	// Initial abilities were already given

	if (GetLocalRole() != ROLE_Authority) return;		// Giving abilities only on server

	for (auto & ability_pair_ : initial_ability_container)
	{
		if (!(ability_pair_.Value && ability_pair_.Value.Get())) return;	// Return if invalid ability class, hence, not initialized

		FGameplayAbilitySpec ability_spec_ = FGameplayAbilitySpec(ability_pair_.Value, 1.f);

		ability_system_component->GiveAbility(
			ability_spec_
		);
	}

	given_initial_abilities = true;

}
