// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"

#include "BASE_CHAR.generated.h"

class Ubase_player_state;


UCLASS()
class GAS_TUTORIAL_API ABASE_CHAR : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABASE_CHAR();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Client only
	virtual void OnRep_PlayerState() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Only called on the Server. Calls before Server's AcknowledgePossession.
	virtual void PossessedBy(AController* NewController) override;

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