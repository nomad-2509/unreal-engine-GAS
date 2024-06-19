// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/attributes/BASE_attribute_set.h"

#include "ability_system/attributes/BATTLE_attribute_set.h"


UBASE_attribute_set::UBASE_attribute_set()
{
	Initmax_health(300.f);
	Initmax_mana(300.f);
	Initmax_stamina(300.f);
}

void UBASE_attribute_set::PreAttributeChange(const FGameplayAttribute & attribute, float & new_value)
{
    Super::PreAttributeChange(attribute, new_value);

	if (attribute == GethealthAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_health());

	if (attribute == GetmanaAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_mana());

	if (attribute == GetstaminaAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_stamina());

}

bool UBASE_attribute_set::PreGameplayEffectExecute(FGameplayEffectModCallbackData & Data)
{
	Super::PreGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == Gethealth_metaAttribute())
	{
		const UBATTLE_attribute_set * battle_attr_set_ = Cast<UBATTLE_attribute_set>(
			GetOwningAbilitySystemComponent()
				->GetAttributeSet(UBATTLE_attribute_set::StaticClass())
		);

		if (!battle_attr_set_) return false;

		FGameplayTagContainer asset_tags_;

		Data.EffectSpec.GetAllAssetTags(asset_tags_);

		// Refine the physical damage damage to be received
		if (
			asset_tags_
				.HasTagExact(
					FGameplayTag::RequestGameplayTag("damage.type.physical")
				)
		)
			Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude * (100 - battle_attr_set_->Getarmor()) / 100;

		// Refine the magical damage damage to be received
		else if (
			asset_tags_
				.HasTagExact(
					FGameplayTag::RequestGameplayTag("damage.type.magical")
				)
		)
			Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude * (100 - battle_attr_set_->Getmagic_resist()) / 100;

		// else, do nothing, since pure damage is not blocked by magic_resist or armor

		// else
			// Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude;

	}

	if (Data.EvaluatedData.Attribute == Getmana_metaAttribute())
	{
		const UBATTLE_attribute_set * battle_attr_set_ = Cast<UBATTLE_attribute_set>(
			GetOwningAbilitySystemComponent()
				->GetAttributeSet(UBATTLE_attribute_set::StaticClass())
		);

		if (!battle_attr_set_) return false;

		FGameplayTagContainer asset_tags_;

		Data.EffectSpec.GetAllAssetTags(asset_tags_);

		// Refine the physical damage damage to be received
		if (
			asset_tags_
				.HasTagExact(
					FGameplayTag::RequestGameplayTag("damage.type.physical")
				)
		)
			Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude * (100 - battle_attr_set_->Getarmor()) / 100;

		// Refine the magical damage damage to be received
		else if (
			asset_tags_
				.HasTagExact(
					FGameplayTag::RequestGameplayTag("damage.type.magical")
				)
		)
			Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude * (100 - battle_attr_set_->Getmagic_resist()) / 100;

		// else, do nothing, since pure damage is not blocked by magic_resist or armor

		// else
			// Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude;

	}

	if (Data.EvaluatedData.Attribute == Getstamina_metaAttribute())
	{
		const UBATTLE_attribute_set * battle_attr_set_ = Cast<UBATTLE_attribute_set>(
			GetOwningAbilitySystemComponent()
				->GetAttributeSet(UBATTLE_attribute_set::StaticClass())
		);

		if (!battle_attr_set_) return false;

		FGameplayTagContainer asset_tags_;

		Data.EffectSpec.GetAllAssetTags(asset_tags_);

		// Refine the physical damage damage to be received
		if (
			asset_tags_
				.HasTagExact(
					FGameplayTag::RequestGameplayTag("damage.type.physical")
				)
		)
			Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude * (100 - battle_attr_set_->Getarmor()) / 100;

		// Refine the magical damage damage to be received
		else if (
			asset_tags_
				.HasTagExact(
					FGameplayTag::RequestGameplayTag("damage.type.magical")
				)
		)
			Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude * (100 - battle_attr_set_->Getmagic_resist()) / 100;

		// else, do nothing, since pure damage is not blocked by magic_resist or armor

		// else
			// Data.EvaluatedData.Magnitude = Data.EvaluatedData.Magnitude;

	}

	return true;

}

void UBASE_attribute_set::PostGameplayEffectExecute(const FGameplayEffectModCallbackData & Data)
{
    Super::PostGameplayEffectExecute(Data);

	// Do the damage/heal using the meta attribute set
	if (Data.EvaluatedData.Attribute == Gethealth_metaAttribute())
	{
		Sethealth(FMath::Clamp(
			Gethealth() + Gethealth_meta(),
			0.f,
			Getmax_health()
		));

		Sethealth_meta(0.f);
	}

	if (Data.EvaluatedData.Attribute == Getmana_metaAttribute())
	{
		Setmana(FMath::Clamp(
			Getmana() + Getmana_meta(),
			0.f,
			Getmax_mana()
		));

		Setmana_meta(0.f);
	}

	if (Data.EvaluatedData.Attribute == Getstamina_metaAttribute())
	{
		Setstamina(FMath::Clamp(
			Getstamina() + Getstamina_meta(),
			0.f,
			Getmax_stamina()
		));

		Setstamina_meta(0.f);
	}

	if (Data.EvaluatedData.Attribute == GethealthAttribute())
		Sethealth(FMath::Clamp(Gethealth(), 0.f, Getmax_health()));

	if (Data.EvaluatedData.Attribute == GetmanaAttribute())
		Setmana(FMath::Clamp(Getmana(), 0.f, Getmax_mana()));

	if (Data.EvaluatedData.Attribute == GetstaminaAttribute())
		Setstamina(FMath::Clamp(Getstamina(), 0.f, Getmax_stamina()));

}

void UBASE_attribute_set::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, max_health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, health_regen, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, max_mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, mana_regen, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, max_stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBASE_attribute_set, stamina_regen, COND_None, REPNOTIFY_Always);

}

void UBASE_attribute_set::on_rep_health(const FGameplayAttributeData& old_health)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, health, old_health);
}

void UBASE_attribute_set::on_rep_max_health(const FGameplayAttributeData& old_max_health)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, max_health, old_max_health);
}

void UBASE_attribute_set::on_rep_health_regen(const FGameplayAttributeData& old_health_regen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, health_regen, old_health_regen);
}

void UBASE_attribute_set::on_rep_mana(const FGameplayAttributeData& old_mana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, mana, old_mana);
}

void UBASE_attribute_set::on_rep_max_mana(const FGameplayAttributeData& old_max_mana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, max_mana, old_max_mana);
}

void UBASE_attribute_set::on_rep_mana_regen(const FGameplayAttributeData& old_mana_regen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, mana_regen, old_mana_regen);
}

void UBASE_attribute_set::on_rep_stamina(const FGameplayAttributeData& old_stamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, stamina, old_stamina);
}

void UBASE_attribute_set::on_rep_max_stamina(const FGameplayAttributeData& old_max_stamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, max_stamina, old_max_stamina);
}

void UBASE_attribute_set::on_rep_stamina_regen(const FGameplayAttributeData& old_stamina_regen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBASE_attribute_set, stamina_regen, old_stamina_regen);
}
