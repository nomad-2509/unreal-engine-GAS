// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/attributes/BATTLE_attribute_set.h"


UBATTLE_attribute_set::UBATTLE_attribute_set()
{
	Initmax_armor(100.f);
	Initmax_magic_resist(100.f);

	// Initmax_movement_speed(100.f);
	Initmax_attack_speed(500.f);

	// Setting the default values
	Initmovement_speed(100.f);
	Initattack_speed(100.f);

	Initcooldown_reduction(100.f);
	Initspell_amplification(100.f);

}

void UBATTLE_attribute_set::PreAttributeChange(const FGameplayAttribute & attribute, float & new_value)
{
    Super::PreAttributeChange(attribute, new_value);

	if (attribute == GetarmorAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_armor());

	else if (attribute == Getmagic_resistAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_magic_resist());

	/*
		To clamp movement speed, we must fetch the Character Movement Component
		And compare with its movement speed.
	*/
	else if (attribute == Getmovement_speedAttribute())
	{
		float char_movt_speed_ = 500.f;		// get character movement speed from character movement component

		new_value = (char_movt_speed_ >= 3000.f)
			? Getmovement_speed()
			: new_value;
	}

	else if (attribute == Getattack_speedAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_attack_speed());

	else if (
		attribute == Getcooldown_reductionAttribute() && 
		new_value <= 20.f
	)
		new_value = Getcooldown_reduction();
	// but 0.2 second must be validated for at the time of committing costs

	else	// Spell Amplification
		if (new_value <= 0.f)
			new_value = Getspell_amplification();

}

void UBATTLE_attribute_set::PostGameplayEffectExecute(const FGameplayEffectModCallbackData & Data)
{
    Super::PostGameplayEffectExecute(Data);

	// Change character's movement speed 

}

void UBATTLE_attribute_set::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, max_armor, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, magic_resist, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, max_magic_resist, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, movement_speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, max_movement_speed, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, attack_speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, max_attack_speed, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, cooldown_reduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, max_cooldown_reduction, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, spell_amplification, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBATTLE_attribute_set, max_spell_amplification, COND_None, REPNOTIFY_Always);

}

void UBATTLE_attribute_set::on_rep_armor(const FGameplayAttributeData& old_armor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, armor, old_armor);
}

void UBATTLE_attribute_set::on_rep_max_armor(const FGameplayAttributeData& old_max_armor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, max_armor, old_max_armor);
}

void UBATTLE_attribute_set::on_rep_magic_resist(const FGameplayAttributeData& old_magic_resist)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, magic_resist, old_magic_resist);
}

void UBATTLE_attribute_set::on_rep_max_magic_resist(const FGameplayAttributeData& old_max_magic_resist)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, max_magic_resist, old_max_magic_resist);
}

void UBATTLE_attribute_set::on_rep_movement_speed(const FGameplayAttributeData& old_movement_speed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, movement_speed, old_movement_speed);
}

void UBATTLE_attribute_set::on_rep_max_movement_speed(const FGameplayAttributeData& old_max_movement_speed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, max_movement_speed, old_max_movement_speed);
}

void UBATTLE_attribute_set::on_rep_attack_speed(const FGameplayAttributeData& old_attack_speed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, attack_speed, old_attack_speed);
}

void UBATTLE_attribute_set::on_rep_max_attack_speed(const FGameplayAttributeData& old_max_attack_speed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, max_attack_speed, old_max_attack_speed);
}

void UBATTLE_attribute_set::on_rep_cooldown_reduction(const FGameplayAttributeData& old_cooldown_reduction)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, cooldown_reduction, old_cooldown_reduction);
}

void UBATTLE_attribute_set::on_rep_max_cooldown_reduction(const FGameplayAttributeData& old_max_cooldown_reduction)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, max_cooldown_reduction, old_max_cooldown_reduction);
}

void UBATTLE_attribute_set::on_rep_spell_amplification(const FGameplayAttributeData& old_spell_amplification)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, spell_amplification, old_spell_amplification);
}

void UBATTLE_attribute_set::on_rep_max_spell_amplification(const FGameplayAttributeData& old_max_spell_amplification)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBATTLE_attribute_set, max_spell_amplification, old_max_spell_amplification);
}
