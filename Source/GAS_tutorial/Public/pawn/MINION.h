// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "pawn/BASE_CHAR.h"
#include "MINION.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API AMINION : public ABASE_CHAR
{
	GENERATED_BODY()

public:
	AMINION();

protected:
	virtual void BeginPlay() override;

};
