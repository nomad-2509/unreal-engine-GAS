// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"

#include "BASE_CHAR.generated.h"

class Ubase_player_state;

class UBASE_attribute_set;
class UCORE_attribute_set;
class UBATTLE_attribute_set;
class UCOMMON_attribute_set;


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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAMEPLAY_ABILITY_SYSTEM")
	UAbilitySystemComponent * ability_system_component;

// Methods
public:
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const
	{ return ability_system_component; };

	virtual void initialize_ability_system();

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

	UPROPERTY()
	UCOMMON_attribute_set * COMMON_attribute_set;


// Methods
	UBASE_attribute_set * get_BASE_attribute_set()
	{ return BASE_attribute_set; };

	UCORE_attribute_set * get_CORE_attribute_set()
	{ return CORE_attribute_set; };

	UBATTLE_attribute_set * get_BATTLE_attribute_set()
	{ return BATTLE_attribute_set; };

	UCOMMON_attribute_set * get_COMMON_attribute_set()
	{ return COMMON_attribute_set; };


// ============
// EFFECTS

// Properties
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ABILITY_SYSTEM|EFFECTS")
	TArray< TSubclassOf<UGameplayEffect> > initial_effect_container;

	bool applied_initial_effects = false;

// Methods
protected:
	virtual void apply_initial_effects();


// ============
// ABILITIES

// Properties
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ABILITY_SYSTEM|ABILITIES")
	TMap<
		FGameplayTag,
		TSubclassOf<UGameplayAbility>
	> initial_ability_container;

	bool given_initial_abilities = false;

// Methods
protected:
	virtual void give_initial_abilities();


};
