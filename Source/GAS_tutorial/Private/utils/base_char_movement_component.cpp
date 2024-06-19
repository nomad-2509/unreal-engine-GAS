// Fill out your copyright notice in the Description page of Project Settings.


#include "utils/base_char_movement_component.h"

#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ability_system/attributes/BATTLE_attribute_set.h"


void Ubase_char_movement_component::UpdateCharacterStateBeforeMovement(float DeltaSeconds)
{
	Super::UpdateCharacterStateBeforeMovement(DeltaSeconds);

	if (
		UAbilitySystemComponent * ASC_ = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())
	)
		// if NOT (stunned OR rooted), rotate by controller
		bUseControllerDesiredRotation = !(
			ASC_->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("state.pawn.root")) || 
			ASC_->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("state.pawn.stun")) 
		);

}

float Ubase_char_movement_component::GetMaxSpeed() const
{
	UAbilitySystemComponent * ASC_ = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner());

	if (!ASC_) return Super::GetMaxSpeed();

	const UBATTLE_attribute_set * BATTLE_attr_set_ = Cast<UBATTLE_attribute_set>(
		ASC_->GetAttributeSet(UBATTLE_attribute_set::StaticClass())
	);

	if (!BATTLE_attr_set_) return Super::GetMaxSpeed();

	// Validate for stun or root state
	return (
		ASC_->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("state.pawn.root")) || 
		ASC_->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("state.pawn.stun")) 
	)
		? 0.0f		// If true, return movement speed as zero
		: BATTLE_attr_set_->Getmovement_speed();

}
