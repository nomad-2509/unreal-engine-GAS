// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/BASE_WIDGET.h"
#include "widget_base_attributes.generated.h"


struct FOnAttributeChangeData;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	F_on_health_changed_signature,
		float, new_health
	);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	F_on_max_health_changed_signature,
		float, new_max_health
	);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	F_on_stamina_changed_signature,
		float, new_stamina
	);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	F_on_max_stamina_changed_signature,
		float, new_max_stamina
	);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	F_on_mana_changed_signature,
		float, new_mana
	);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	F_on_max_mana_changed_signature,
		float, new_max_mana
	);


UCLASS()
class GAS_TUTORIAL_API Uwidget_base_attributes : public UBASE_WIDGET
{
	GENERATED_BODY()

// Properites
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float health;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float max_health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float stamina;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float max_stamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float mana;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float max_mana;


	UPROPERTY(
		BlueprintAssignable,
		Category = "old_widget_base_attributes|Attribute_change_delegates"
	)
		F_on_health_changed_signature event_delegate_on_health_changed;

	UPROPERTY(
		BlueprintAssignable,
		Category = "old_widget_base_attributes|Attribute_change_delegates"
	)
		F_on_max_health_changed_signature event_delegate_on_max_health_changed;

	UPROPERTY(
		BlueprintAssignable,
		Category = "old_widget_base_attributes|Attribute_change_delegates"
	)
		F_on_stamina_changed_signature event_delegate_on_stamina_changed;

	UPROPERTY(
		BlueprintAssignable,
		Category = "old_widget_base_attributes|Attribute_change_delegates"
	)
		F_on_max_stamina_changed_signature event_delegate_on_max_stamina_changed;

	UPROPERTY(
		BlueprintAssignable,
		Category = "old_widget_base_attributes|Attribute_change_delegates"
	)
		F_on_mana_changed_signature event_delegate_on_mana_changed;

	UPROPERTY(
		BlueprintAssignable,
		Category = "old_widget_base_attributes|Attribute_change_delegates"
	)
		F_on_max_mana_changed_signature event_delegate_on_max_mana_changed;


// Methods
public:
	UFUNCTION(BlueprintCallable, Category = "WIDGET")
	void initialize_widget(AActor * owner);

protected:
	UFUNCTION(BlueprintPure)
	float set_health_percentage();

	UFUNCTION(BlueprintPure)
	float set_stamina_percentage();

	UFUNCTION(BlueprintPure)
	float set_mana_percentage();

	virtual void bind_event_listeners_to_delegates();

	void health_changed_event_handler(const FOnAttributeChangeData & Data);

	void max_health_changed_event_handler(const FOnAttributeChangeData & Data);

	void stamina_changed_event_handler(const FOnAttributeChangeData & Data);

	void max_stamina_changed_event_handler(const FOnAttributeChangeData & Data);

	void mana_changed_event_handler(const FOnAttributeChangeData & Data);

	void max_mana_changed_event_handler(const FOnAttributeChangeData & Data);

};
