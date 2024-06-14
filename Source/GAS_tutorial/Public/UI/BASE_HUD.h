// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Blueprint/UserWidget.h"

#include "BASE_HUD.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API ABASE_HUD : public AHUD
{
	GENERATED_BODY()

// Properties
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player_HUD|Widget_Overlay")
	TSubclassOf<UUserWidget> widget_overlay_class;

	UUserWidget * widget_overlay_obj;

// Methods
protected:
	virtual void BeginPlay() override;

	virtual void initialize_HUD();

public:
	UFUNCTION(BlueprintPure, Category = "Player_HUD|Widget_Overlay")
	UUserWidget * get_overlay_widget()
	{ return (widget_overlay_obj); };

	UUserWidget * get_widget_obj_base_attributes();

	UUserWidget * set_widget_obj_base_attributes(UUserWidget * widget_base_attr);

};
