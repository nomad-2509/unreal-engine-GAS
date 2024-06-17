// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/effect_executions/GEffEx_poison.h"

#include "ability_system/attributes/BASE_attribute_set.h"


UGEffEx_poison::UGEffEx_poison()
{
	poison_damage_health = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::Gethealth_metaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);
	poison_damage_mana = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::Getmana_metaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);
	poison_damage_stamina = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::Getstamina_metaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);

	current_target_health = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::GethealthAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		false		// No need snapshotting, getting running value
	);
	current_target_mana = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::GetmanaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		false		// No need snapshotting, getting running value
	);
	current_target_stamina = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::GetstaminaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		false		// No need snapshotting, getting running value
	);

	current_target_max_health = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::Getmax_healthAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);
	current_target_max_mana = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::Getmax_manaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);
	current_target_max_stamina = FGameplayEffectAttributeCaptureDefinition(
		UBASE_attribute_set::Getmax_staminaAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);

	RelevantAttributesToCapture.Add(poison_damage_health);
	RelevantAttributesToCapture.Add(poison_damage_mana);
	RelevantAttributesToCapture.Add(poison_damage_stamina);

	RelevantAttributesToCapture.Add(current_target_health);
	RelevantAttributesToCapture.Add(current_target_mana);
	RelevantAttributesToCapture.Add(current_target_stamina);

	RelevantAttributesToCapture.Add(current_target_max_health);
	RelevantAttributesToCapture.Add(current_target_max_mana);
	RelevantAttributesToCapture.Add(current_target_max_stamina);
}

void UGEffEx_poison::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters & ExecutionParams,
	FGameplayEffectCustomExecutionOutput & OutExecutionOutput
) const
{
	float poison_damage_value_health_;		// Capturing health meta, which will be outgoing poison damage health
	float poison_damage_value_mana_;		// Capturing mana meta, which will be outgoing poison damage mana
	float poison_damage_value_stamina_;		// Capturing stamina meta, which will be outgoing poison damage stamina

	float captured_value_health_;			// Capturing Current health of the target
	float captured_value_mana_;				// Capturing Current mana of the target
	float captured_value_stamina_;			// Capturing Current stamina of the target

	float captured_value_max_health_;		// Capturing Current max health of the target
	float captured_value_max_mana_;			// Capturing Current max mana of the target
	float captured_value_max_stamina_;		// Capturing Current max stamina of the target

	const FGameplayEffectSpec & spec_ = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters evaluation_parameters_;

	evaluation_parameters_.SourceTags = spec_.CapturedSourceTags.GetAggregatedTags();
	evaluation_parameters_.TargetTags = spec_.CapturedTargetTags.GetAggregatedTags();

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(poison_damage_health, evaluation_parameters_, poison_damage_value_health_);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(poison_damage_mana, evaluation_parameters_, poison_damage_value_mana_);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(poison_damage_stamina, evaluation_parameters_, poison_damage_value_stamina_);

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(current_target_health, evaluation_parameters_, captured_value_health_);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(current_target_mana, evaluation_parameters_, captured_value_mana_);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(current_target_stamina, evaluation_parameters_, captured_value_stamina_);

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(current_target_max_health, evaluation_parameters_, captured_value_max_health_);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(current_target_max_mana, evaluation_parameters_, captured_value_max_mana_);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(current_target_max_stamina, evaluation_parameters_, captured_value_max_stamina_);

	// Perform calculation
		// More damage, if ratio is less than half
	poison_damage_value_health_ += (captured_value_health_ / captured_value_max_health_ > 0.5)
		? -5.f
		: -10.f;
	poison_damage_value_mana_ += (captured_value_mana_ / captured_value_max_mana_ > 0.5)
		? -10.f
		: -15.f;
	poison_damage_value_stamina_ += (captured_value_stamina_ / captured_value_max_stamina_ > 0.5)
		? -20.f
		: -30.f;

	OutExecutionOutput.AddOutputModifier(
		FGameplayModifierEvaluatedData(
			UBASE_attribute_set::Gethealth_metaAttribute(),
			EGameplayModOp::Override,
			poison_damage_value_health_
		)
	);

	OutExecutionOutput.AddOutputModifier(
		FGameplayModifierEvaluatedData(
			UBASE_attribute_set::Getmana_metaAttribute(),
			EGameplayModOp::Override,
			poison_damage_value_mana_
		)
	);

	OutExecutionOutput.AddOutputModifier(
		FGameplayModifierEvaluatedData(
			UBASE_attribute_set::Getstamina_metaAttribute(),
			EGameplayModOp::Override,
			poison_damage_value_stamina_
		)
	);

}
