// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

#include "Net/UnrealNetwork.h"

#include "COMMON_attribute_set.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UCOMMON_attribute_set : public UAttributeSet
{
	GENERATED_BODY()

	/*
		base_damage
		cast_range

		jump_max_number
		jump_count
		jump_height

		dodge_max_number
		dodge_count
		dodge_speed
		dodge_distance

		sprint_speed
	*/

// Properties
public:
	// Combat
	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|combat", ReplicatedUsing = on_rep_base_damage)
		FGameplayAttributeData base_damage;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, base_damage);

	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|combat", ReplicatedUsing = on_rep_cast_range)
		FGameplayAttributeData cast_range;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, cast_range);

	// Jump
	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_jump_max_number)
		FGameplayAttributeData jump_max_number;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, jump_max_number);

	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_jump_count)
		FGameplayAttributeData jump_count;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, jump_count);

	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_jump_height)
		FGameplayAttributeData jump_height;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, jump_height);

	// Dodge
	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_dodge_max_number)
		FGameplayAttributeData dodge_max_number;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, dodge_max_number);

	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_dodge_count)
		FGameplayAttributeData dodge_count;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, dodge_count);

	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_dodge_speed)
		FGameplayAttributeData dodge_speed;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, dodge_speed);

	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_dodge_distance)
		FGameplayAttributeData dodge_distance;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, dodge_distance);

	// Sprint
	UPROPERTY(BlueprintReadOnly, Category = "COMMON_attribute_set|movement", ReplicatedUsing = on_rep_sprint_speed)
		FGameplayAttributeData sprint_speed;
	ATTRIBUTE_ACCESSORS(UCOMMON_attribute_set, sprint_speed);


// Methods
public:
	UCOMMON_attribute_set();

	virtual void PreAttributeChange(const FGameplayAttribute & attribute, float & new_value) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// METHODS FOR REPLICATION
	UFUNCTION()
		virtual void on_rep_base_damage(const FGameplayAttributeData& old_base_damage);

	UFUNCTION()
		virtual void on_rep_cast_range(const FGameplayAttributeData& old_cast_range);

	UFUNCTION()
		virtual void on_rep_jump_max_number(const FGameplayAttributeData& old_jump_max_number);

	UFUNCTION()
		virtual void on_rep_jump_count(const FGameplayAttributeData& old_jump_count);

	UFUNCTION()
		virtual void on_rep_jump_height(const FGameplayAttributeData& old_jump_height);

	UFUNCTION()
		virtual void on_rep_dodge_max_number(const FGameplayAttributeData& old_dodge_max_number);

	UFUNCTION()
		virtual void on_rep_dodge_count(const FGameplayAttributeData& old_dodge_count);

	UFUNCTION()
		virtual void on_rep_dodge_speed(const FGameplayAttributeData& old_dodge_speed);

	UFUNCTION()
		virtual void on_rep_dodge_distance(const FGameplayAttributeData& old_dodge_distance);

	UFUNCTION()
		virtual void on_rep_sprint_speed(const FGameplayAttributeData& old_sprint_speed);

};
