// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "GameFramework/Character.h"

#include "base_player_controller.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API Abase_player_controller : public APlayerController
{
	GENERATED_BODY()

// Properties
protected:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* default_mapping_context;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* input_action_jump;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* input_action_move;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* input_action_look;

	float movement_x;
	float movement_y;

// Methods
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	// virtual void AcknowledgePossession(APawn * P) override;

	// Server only
	virtual void OnPossess(APawn* InPawn) override;

	/** Called for movement input */
	void move(const FInputActionValue& Value);

	/** Called for looking input */
	void look(const FInputActionValue& Value);

	// Temporary methods
	// Will create a Jump ability
	// void __jump()
	// { if (Cast<ACharacter>(GetPawn()))
	// 	Cast<ACharacter>(GetPawn())->Jump(); };

	// void __stop_jump()
	// { if (Cast<ACharacter>(GetPawn()))
	// 	Cast<ACharacter>(GetPawn())->StopJumping(); };

	UFUNCTION(BlueprintPure, Category="PLAYER_CONTROLLER|Movement")
	float get_movement_x() { return movement_x; }

	UFUNCTION(BlueprintPure, Category="PLAYER_CONTROLLER|Movement")
	float get_movement_y() { return movement_y; }

};
