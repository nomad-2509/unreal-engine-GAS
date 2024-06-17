// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEffEx_poison.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UGEffEx_poison : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

// Properties
public:
	FGameplayEffectAttributeCaptureDefinition poison_damage_health;
	FGameplayEffectAttributeCaptureDefinition poison_damage_mana;
	FGameplayEffectAttributeCaptureDefinition poison_damage_stamina;

	FGameplayEffectAttributeCaptureDefinition current_target_health;
	FGameplayEffectAttributeCaptureDefinition current_target_mana;
	FGameplayEffectAttributeCaptureDefinition current_target_stamina;

	FGameplayEffectAttributeCaptureDefinition current_target_max_health;
	FGameplayEffectAttributeCaptureDefinition current_target_max_mana;
	FGameplayEffectAttributeCaptureDefinition current_target_max_stamina;

// Methods
public:
	UGEffEx_poison();

	virtual void Execute_Implementation(
		const FGameplayEffectCustomExecutionParameters & ExecutionParams,
		FGameplayEffectCustomExecutionOutput & OutExecutionOutput
	) const override;

};
