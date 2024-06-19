// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BASE_WIDGET.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API UBASE_WIDGET : public UUserWidget
{
	GENERATED_BODY()

// Properties
protected:
	UPROPERTY(BlueprintReadWrite, Category = "WIDGET|Owner")
	AActor * owner_actor;


// Methods
public:
	UFUNCTION(BlueprintCallable, Category = "WIDGET|Owner")
	void set_owner_actor(AActor * actor)
	{ owner_actor = actor; };

	UFUNCTION(BlueprintPure, Category = "WIDGET|Owner")
	AActor * get_owner_actor()
	{ return owner_actor; };

	virtual UUserWidget * get_widget_obj_base_attributes()
	{ return nullptr; }

	virtual UUserWidget * set_widget_obj_base_attributes(UUserWidget * widget_base_attr)
	{ return nullptr; }


};
