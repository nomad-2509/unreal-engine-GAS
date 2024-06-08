// Fill out your copyright notice in the Description page of Project Settings.


#include "src/base_asset_manager.h"
#include "AbilitySystemGlobals.h"


void Ubase_asset_manager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();

	UE_LOG(LogTemp, Warning, TEXT("----------- Hello world -------------"));
}
