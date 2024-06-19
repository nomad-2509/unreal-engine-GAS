// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/MMC/GMMC_electric_field.h"
#include "ability_system/attributes/BASE_attribute_set.h"
#include "ability_system/attributes/BATTLE_attribute_set.h"


UGMMC_electric_field::UGMMC_electric_field()
{
	health_attr_def.AttributeToCapture = UBASE_attribute_set::GethealthAttribute();
	health_attr_def.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	health_attr_def.bSnapshot = false;

	max_health_attr_def.AttributeToCapture = UBASE_attribute_set::Getmax_healthAttribute();
	max_health_attr_def.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	max_health_attr_def.bSnapshot = true;

	magic_resist_attr_def.AttributeToCapture = UBATTLE_attribute_set::Getmagic_resistAttribute();
	magic_resist_attr_def.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	magic_resist_attr_def.bSnapshot = true;

	// Which attributes to capture?
	RelevantAttributesToCapture.Add(health_attr_def);
	RelevantAttributesToCapture.Add(max_health_attr_def);
	RelevantAttributesToCapture.Add(magic_resist_attr_def);
}

float UGMMC_electric_field::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec & Spec) const
{
	float captured_value_health_;
	float captured_value_max_health_;
	float captured_value_magic_resist_;

	FAggregatorEvaluateParameters evaluation_parameters_;

	evaluation_parameters_.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	evaluation_parameters_.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	GetCapturedAttributeMagnitude(health_attr_def, Spec, evaluation_parameters_, captured_value_health_);
	GetCapturedAttributeMagnitude(max_health_attr_def, Spec, evaluation_parameters_, captured_value_max_health_);
	GetCapturedAttributeMagnitude(magic_resist_attr_def, Spec, evaluation_parameters_, captured_value_magic_resist_);

	float outgoing_health_damage_ = (
		(captured_value_max_health_ - captured_value_health_)	// Missing health
		*
		(100 - captured_value_magic_resist_) / 100				// Missing Magic Resist percentage
	);

	return outgoing_health_damage_;
}
