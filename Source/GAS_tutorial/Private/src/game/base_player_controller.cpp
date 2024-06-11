// Fill out your copyright notice in the Description page of Project Settings.


#include "src/game/base_player_controller.h"
#include "src/game/base_player_state.h"


void Abase_player_controller::BeginPlay()
{
	Super::BeginPlay();

	if (
		UEnhancedInputLocalPlayerSubsystem * Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
				GetLocalPlayer()
			)
	)
		Subsystem->AddMappingContext(default_mapping_context, 0);

}

void Abase_player_controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent * EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		// EnhancedInputComponent->BindAction(input_action_jump, ETriggerEvent::Triggered, this, &Abase_player_controller::__jump);
		// EnhancedInputComponent->BindAction(input_action_jump, ETriggerEvent::Completed, this, &Abase_player_controller::__stop_jump);

		// Moving
		EnhancedInputComponent->BindAction(input_action_move, ETriggerEvent::Triggered, this, &Abase_player_controller::move);

		// Looking
		EnhancedInputComponent->BindAction(input_action_look, ETriggerEvent::Triggered, this, &Abase_player_controller::look);
	}
}

void Abase_player_controller::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Abase_player_state * player_state_ = GetPlayerState<Abase_player_state>();
	if (player_state_)
		player_state_->GetAbilitySystemComponent()->InitAbilityActorInfo(player_state_, InPawn);
}

void Abase_player_controller::move(const FInputActionValue & Value)
{
	// input is a Vector2D
    FVector2D MovementVector = Value.Get<FVector2D>();

	if (!(
		GetPawn() && 
		GetPawn()->GetController()
	)) return;

    // Use controller rotation
    const FRotator Rotation = GetPawn()->GetController()->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, MovementVector.X);

	movement_x = MovementVector.Y;
	movement_y = MovementVector.X;

}

void Abase_player_controller::look(const FInputActionValue & Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (!GetPawn()) return;

	// add yaw and pitch input to controller
	GetPawn()->AddControllerYawInput(LookAxisVector.X);
	GetPawn()->AddControllerPitchInput(LookAxisVector.Y);

}
