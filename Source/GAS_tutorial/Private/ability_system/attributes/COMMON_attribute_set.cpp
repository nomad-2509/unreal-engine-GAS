// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/attributes/COMMON_attribute_set.h"


UCOMMON_attribute_set::UCOMMON_attribute_set()
{
	Initjump_max_number(3.0f);
	Initjump_count(3.0f);
	
	Initdodge_max_number(3.0f);
	Initdodge_count(3.0f);
}

void UCOMMON_attribute_set::PreAttributeChange(const FGameplayAttribute & attribute, float & new_value)
{
	Super::PreAttributeChange(attribute, new_value);

	if (attribute == Getjump_countAttribute())
		new_value = FMath::Clamp(
			FMath::FloorToFloat(new_value),		// Must use the floor value
			0.f,
			Getjump_max_number()
		);
	
	if (attribute == Getdodge_countAttribute())
		new_value = FMath::Clamp(
			FMath::FloorToFloat(new_value),		// Must use the floor value
			0.f,
			Getdodge_max_number()
		);
}

void UCOMMON_attribute_set::PostGameplayEffectExecute(const FGameplayEffectModCallbackData & Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == Getjump_countAttribute())
	{
		Setjump_count(
			FMath::Clamp(
				FMath::FloorToFloat(Getjump_count()),	// Must use the floor value
				0.f,
				Getjump_max_number()
			)
		);

		// Remove the jump increment effect if 
		// jump count is equal to or greater than max jump numer
		if (
			Getjump_count() >= Getjump_max_number() && 
			Data.EffectSpec.Def
		)
			GetOwningAbilitySystemComponent()->
				RemoveActiveGameplayEffectBySourceEffect(
					Data.EffectSpec.Def.GetClass(),
					GetOwningAbilitySystemComponent()
				);
	}
	
	if (Data.EvaluatedData.Attribute == Getdodge_countAttribute())
	{
		Setdodge_count(
			FMath::Clamp(
				FMath::FloorToFloat(Getdodge_count()),	// Must use the floor value
				0.f,
				Getdodge_max_number()
			)
		);

		// Remove the dodge increment effect if 
		// dodge count is equal to or greater than max dodge numer
		if (
			Getdodge_count() >= Getdodge_max_number() && 
			Data.EffectSpec.Def
		)
			GetOwningAbilitySystemComponent()->
				RemoveActiveGameplayEffectBySourceEffect(
					Data.EffectSpec.Def.GetClass(),
					GetOwningAbilitySystemComponent()
				);
	}
}

void UCOMMON_attribute_set::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, base_damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, cast_range, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, jump_max_number, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, jump_count, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, jump_height, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, dodge_max_number, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, dodge_count, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, dodge_speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, dodge_distance, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UCOMMON_attribute_set, sprint_speed, COND_None, REPNOTIFY_Always);
}

void UCOMMON_attribute_set::on_rep_base_damage(const FGameplayAttributeData & old_base_damage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, base_damage, old_base_damage);
}

void UCOMMON_attribute_set::on_rep_cast_range(const FGameplayAttributeData & old_cast_range)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, cast_range, old_cast_range);
}

void UCOMMON_attribute_set::on_rep_jump_max_number(const FGameplayAttributeData& old_jump_max_number)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, jump_max_number, old_jump_max_number);
}

void UCOMMON_attribute_set::on_rep_jump_count(const FGameplayAttributeData& old_jump_count)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, jump_count, old_jump_count);
}

void UCOMMON_attribute_set::on_rep_jump_height(const FGameplayAttributeData& old_jump_height)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, jump_height, old_jump_height);
}

void UCOMMON_attribute_set::on_rep_dodge_max_number(const FGameplayAttributeData& old_dodge_max_number)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, dodge_max_number, old_dodge_max_number);
}

void UCOMMON_attribute_set::on_rep_dodge_count(const FGameplayAttributeData& old_dodge_count)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, dodge_count, old_dodge_count);
}

void UCOMMON_attribute_set::on_rep_dodge_speed(const FGameplayAttributeData& old_dodge_speed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, dodge_speed, old_dodge_speed);
}

void UCOMMON_attribute_set::on_rep_dodge_distance(const FGameplayAttributeData& old_dodge_distance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, dodge_distance, old_dodge_distance);
}

void UCOMMON_attribute_set::on_rep_sprint_speed(const FGameplayAttributeData& old_sprint_speed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCOMMON_attribute_set, sprint_speed, old_sprint_speed);
}
