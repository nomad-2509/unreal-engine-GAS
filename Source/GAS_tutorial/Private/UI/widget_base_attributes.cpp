// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/widget_base_attributes.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "ability_system/attributes/BASE_attribute_set.h"


void Uwidget_base_attributes::initialize_widget(AActor * owner)
{
	owner_actor = owner;
	bind_event_listeners_to_delegates();
}

float Uwidget_base_attributes::set_health_percentage()
{
    return (
        (max_health == 0)
        ? 0
        : (health / max_health)
    );
}

float Uwidget_base_attributes::set_stamina_percentage()
{
    return (
        (max_stamina == 0)
        ? 0
        : (stamina / max_stamina)
    );
}

float Uwidget_base_attributes::set_mana_percentage()
{
    return (
        (max_mana == 0)
        ? 0
        : (mana / max_mana)
    );
}

void Uwidget_base_attributes::bind_event_listeners_to_delegates()
{
	UAbilitySystemComponent * ASC_ =
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(owner_actor);
	
	if (!ASC_) return;

	const UBASE_attribute_set * base_attr_set_ = Cast<UBASE_attribute_set>(
		ASC_->GetAttributeSet(UBASE_attribute_set::StaticClass())
	);

    health = base_attr_set_->Gethealth();
    max_health = base_attr_set_->Getmax_health();

    stamina = base_attr_set_->Getstamina();
    max_stamina = base_attr_set_->Getmax_stamina();

    mana = base_attr_set_->Getmana();
    max_mana = base_attr_set_->Getmax_mana();

    ASC_->GetGameplayAttributeValueChangeDelegate(
			base_attr_set_->GethealthAttribute()
		).
		AddUObject(
			this,
			&Uwidget_base_attributes::health_changed_event_handler
		);

	ASC_->GetGameplayAttributeValueChangeDelegate(
			base_attr_set_->Getmax_healthAttribute()
		).
		AddUObject(
			this,
			&Uwidget_base_attributes::max_health_changed_event_handler
		);

    ASC_->GetGameplayAttributeValueChangeDelegate(
			base_attr_set_->GetstaminaAttribute()
		).
		AddUObject(
			this,
			&Uwidget_base_attributes::stamina_changed_event_handler
		);

	ASC_->GetGameplayAttributeValueChangeDelegate(
			base_attr_set_->Getmax_staminaAttribute()
		).
		AddUObject(
			this,
			&Uwidget_base_attributes::max_stamina_changed_event_handler
		);

    ASC_->GetGameplayAttributeValueChangeDelegate(
			base_attr_set_->GetmanaAttribute()
		).
		AddUObject(
			this,
			&Uwidget_base_attributes::mana_changed_event_handler
		);

	ASC_->GetGameplayAttributeValueChangeDelegate(
			base_attr_set_->Getmax_manaAttribute()
		).
		AddUObject(
			this,
			&Uwidget_base_attributes::max_mana_changed_event_handler
		);

}

void Uwidget_base_attributes::health_changed_event_handler(const FOnAttributeChangeData & Data)
{
	health = Data.NewValue;
	set_health_percentage();
}

void Uwidget_base_attributes::max_health_changed_event_handler(const FOnAttributeChangeData & Data)
{
	max_health = Data.NewValue;
	set_health_percentage();
}

void Uwidget_base_attributes::stamina_changed_event_handler(const FOnAttributeChangeData & Data)
{
	stamina = Data.NewValue;
	set_stamina_percentage();
}

void Uwidget_base_attributes::max_stamina_changed_event_handler(const FOnAttributeChangeData & Data)
{
	max_stamina = Data.NewValue;
	set_stamina_percentage();
}

void Uwidget_base_attributes::mana_changed_event_handler(const FOnAttributeChangeData & Data)
{
	mana = Data.NewValue;
	set_mana_percentage();
}

void Uwidget_base_attributes::max_mana_changed_event_handler(const FOnAttributeChangeData & Data)
{
	max_mana = Data.NewValue;
	set_mana_percentage();
}
