// Fill out your copyright notice in the Description page of Project Settings.


#include "ability_system/ability_tasks/ABI_TASK_targetting.h"
#include "AbilitySystemComponent.h"


/*
	Happens in Locally Controlled Client
	- Locally controlled client sends target data to server
*/
void UABI_TASK_targetting::send_target_data()
{
	// Begin the Prediction Window
	FScopedPredictionWindow ScopedPrediction(AbilitySystemComponent.Get());

	FHitResult target_hit_result_;
	target_hit_result_.Location = target_location;
	// target_hit_result_.HitActor = target_actor;

	// Declare Target Data Handle and Single Target Data struct
	FGameplayAbilityTargetDataHandle data_handle_;
	FGameplayAbilityTargetData_SingleTargetHit * single_target_data_ = new FGameplayAbilityTargetData_SingleTargetHit();

	// Package the Target Location and/or Actor into Target Data Handle
	single_target_data_->HitResult = target_hit_result_;
	data_handle_.Add(single_target_data_);

	// This is where we send the target data to the server
	AbilitySystemComponent->ServerSetReplicatedTargetData(
		GetAbilitySpecHandle(),
		GetActivationPredictionKey(),
		data_handle_,
		FGameplayTag(),
		AbilitySystemComponent->ScopedPredictionKey
	);

	// Just broadcast the data handle for use - for CLIENT ONLY
	// if (ShouldBroadcastAbilityTaskDelegates())
		target_data.Broadcast(data_handle_);
}

/*
	Happens in Server
	- Event Handler for Target Data handle received from remote player
	- Server operates on target data that it receives
*/
void UABI_TASK_targetting::on_target_data_replicated(const FGameplayAbilityTargetDataHandle & data_handle, FGameplayTag activation_tag)
{
	AbilitySystemComponent->ConsumeClientReplicatedTargetData(GetAbilitySpecHandle(), GetActivationPredictionKey());

	// Just broadcast the data handle for use - for SERVER ONLY
	// if (ShouldBroadcastAbilityTaskDelegates())
		target_data.Broadcast(data_handle);

}

UABI_TASK_targetting * UABI_TASK_targetting::create_target_data(UGameplayAbility * current_ability_obj, FVector location, AActor * actor, bool use_location, bool use_actor)
{
	// This method creates the ability task and
	// assigns values to its properties

	UABI_TASK_targetting * ability_task_object_ = NewAbilityTask<UABI_TASK_targetting>(current_ability_obj);

	ability_task_object_->target_location = location;
	ability_task_object_->target_actor = actor;
	ability_task_object_->location_in_use = use_location;
	ability_task_object_->actor_in_use = use_actor;

	return ability_task_object_;

}

void UABI_TASK_targetting::Activate()
{
	bool locally_controlled = Ability->GetCurrentActorInfo()->IsLocallyControlled();

	if (locally_controlled)
		// Client sends target data
		send_target_data();

	else
	// If I am on the server machine
	{
		// I will operate on the data if sent

		const FGameplayAbilitySpecHandle ability_spec_handle = GetAbilitySpecHandle();
		const FPredictionKey activation_prediction_key = GetActivationPredictionKey();

		AbilitySystemComponent.Get()->
			AbilityTargetDataSetDelegate(ability_spec_handle, activation_prediction_key).		// Get Ability Target Dataset Delegate
				AddUObject(this, &UABI_TASK_targetting::on_target_data_replicated);				// Use event delegate to Bind Callback function to handle event

		bool delegate_is_called = AbilitySystemComponent.Get()->CallReplicatedTargetDataDelegatesIfSet(ability_spec_handle, activation_prediction_key);

		if (!delegate_is_called)
			SetWaitingOnRemotePlayerData();				// Await data from remote player
	}

}
