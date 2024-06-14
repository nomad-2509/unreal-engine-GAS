// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "base_char_movement_component.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API Ubase_char_movement_component : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	virtual void UpdateCharacterStateBeforeMovement(float DeltaSeconds);
	
	virtual float GetMaxSpeed() const override;

};
