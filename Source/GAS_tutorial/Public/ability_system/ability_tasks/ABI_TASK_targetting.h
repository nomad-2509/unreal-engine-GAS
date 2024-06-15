// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "ABI_TASK_targetting.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F_target_data_signature, const FGameplayAbilityTargetDataHandle&, DataHandle);

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UABI_TASK_targetting : public UAbilityTask
{
	GENERATED_BODY()

// Properties
public:
	UPROPERTY(BlueprintAssignable)
	F_target_data_signature target_data;

	// Target Location
	bool location_in_use;
	FVector target_location;
	
	// Target Actor
	bool actor_in_use;
	AActor * target_actor;


// Methods
public:
	/*
		Happens in Locally Controlled Client
		- Locally controlled client sends target data to server
	*/
	void send_target_data();

	/*
		Happens in Server
		- Event Handler for Target Data handle received from remote player
		- Server operates on target data that it receives
	*/
	void on_target_data_replicated(const FGameplayAbilityTargetDataHandle& data_handle, FGameplayTag activation_tag);

public:
	UFUNCTION(
		BlueprintCallable,
		Category="ABILITY_TASKS|Target",
		meta = (
			HidePin = "current_ability_obj",
			DefaultToSelf = "current_ability_obj"
		)
	)
	static UABI_TASK_targetting * create_target_data(
		UGameplayAbility * current_ability_obj,
		FVector location,
		AActor * actor,
		bool use_location = false,
		bool use_actor = false
	);

	// Usually protected
	virtual void Activate() override;

};
