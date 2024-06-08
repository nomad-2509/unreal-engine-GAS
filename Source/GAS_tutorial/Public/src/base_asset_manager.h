// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "base_asset_manager.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API Ubase_asset_manager : public UAssetManager
{
	GENERATED_BODY()

protected:
	virtual void StartInitialLoading() override;

};
