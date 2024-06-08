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
	}

}
