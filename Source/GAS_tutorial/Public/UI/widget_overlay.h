// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/BASE_WIDGET.h"

#include "Components/WrapBox.h"

#include "widget_overlay.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TUTORIAL_API Uwidget_overlay : public UBASE_WIDGET
{
	GENERATED_BODY()

// Properties
protected:
	// Base attributes
	UPROPERTY(
		meta = (BindWidget),
		VisibleAnywhere,
		BlueprintReadOnly,
		Category = "WIDGET|Overlay|binding_widgets"
	)
	UWrapBox * wrap_box_base_attr_widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WIDGET|Overlay|base_attributes")
	TSubclassOf<UUserWidget> widget_base_attributes_class;
	
	UPROPERTY(BlueprintReadOnly, Category = "WIDGET|Overlay|base_attributes")
	UUserWidget * widget_base_attributes;

	// Reticle
	UPROPERTY(
		meta = (BindWidget),
		VisibleAnywhere,
		BlueprintReadOnly,
		Category = "WIDGET|Overlay|binding_widgets"
	)
	UWrapBox * wrap_box_reticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WIDGET|Overlay|base_attributes")
	TSubclassOf<UUserWidget> widget_class_reticle;
	
	UPROPERTY(BlueprintReadOnly, Category = "WIDGET|Overlay|base_attributes")
	UUserWidget * widget_obj_reticle;


// Methods
protected:
	virtual void NativeOnInitialized() override;

	// Base Attributes
	UUserWidget * create_widget_base_attribute();

	UFUNCTION(BlueprintCallable, Category = "WIDGET|")
	void set_widget_base_attributes(UUserWidget * widget_base_attr);

	// Reticle
	UUserWidget * create_widget_reticle();

	UFUNCTION(BlueprintCallable, Category = "WIDGET|")
	void set_widget_reticle(UUserWidget * widget_reticle);

public:
	UUserWidget * get_widget_obj_base_attributes() override;

	UUserWidget * set_widget_obj_base_attributes(UUserWidget * widget_base_attr) override;


};
