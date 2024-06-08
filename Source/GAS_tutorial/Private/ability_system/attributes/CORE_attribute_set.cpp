// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/attributes/CORE_attribute_set.h"


UCORE_attribute_set::UCORE_attribute_set()
{
	Initmax_strength(300.f);
	Initmax_agility(300.f);
	Initmax_intelligence(300.f);
}

void UCORE_attribute_set::PreAttributeChange(const FGameplayAttribute & attribute, float & new_value)
{
    Super::PreAttributeChange(attribute, new_value);

	if (attribute == GetstrengthAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_strength());

	if (attribute == GetagilityAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_agility());

	if (attribute == GetintelligenceAttribute())
		new_value = FMath::Clamp(new_value, 0.f, Getmax_intelligence());

}

void UCORE_attribute_set::PostGameplayEffectExecute(const FGameplayEffectModCallbackData & Data)
{
    Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetstrengthAttribute())
		Setstrength(FMath::Clamp(Getstrength(), 0.f, Getmax_strength()));

	if (Data.EvaluatedData.Attribute == GetagilityAttribute())
		Setagility(FMath::Clamp(Getagility(), 0.f, Getmax_agility()));

	if (Data.EvaluatedData.Attribute == GetintelligenceAttribute())
		Setintelligence(FMath::Clamp(Getintelligence(), 0.f, Getmax_intelligence()));

}

void UCORE_attribute_set::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCORE_attribute_set, strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCORE_attribute_set, max_strength, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UCORE_attribute_set, agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCORE_attribute_set, max_agility, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UCORE_attribute_set, intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCORE_attribute_set, max_intelligence, COND_None, REPNOTIFY_Always);

}

void UCORE_attribute_set::on_rep_strength(const FGameplayAttributeData& old_strength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCORE_attribute_set, strength, old_strength);
}

void UCORE_attribute_set::on_rep_max_strength(const FGameplayAttributeData& old_max_strength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCORE_attribute_set, max_strength, old_max_strength);
}

void UCORE_attribute_set::on_rep_agility(const FGameplayAttributeData& old_agility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCORE_attribute_set, agility, old_agility);
}

void UCORE_attribute_set::on_rep_max_agility(const FGameplayAttributeData& old_max_agility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCORE_attribute_set, max_agility, old_max_agility);
}

void UCORE_attribute_set::on_rep_intelligence(const FGameplayAttributeData& old_intelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCORE_attribute_set, intelligence, old_intelligence);
}

void UCORE_attribute_set::on_rep_max_intelligence(const FGameplayAttributeData& old_max_intelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCORE_attribute_set, max_intelligence, old_max_intelligence);
}
