// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GMMC_electric_field.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UGMMC_electric_field : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

// Properties
protected:
	FGameplayEffectAttributeCaptureDefinition health_attr_def;
	FGameplayEffectAttributeCaptureDefinition max_health_attr_def;
	FGameplayEffectAttributeCaptureDefinition magic_resist_attr_def;

public:
	UGMMC_electric_field();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

};
