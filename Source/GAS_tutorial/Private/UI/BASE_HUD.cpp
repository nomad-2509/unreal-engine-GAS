// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BASE_HUD.h"

#include "UI/widget_overlay.h"


void ABASE_HUD::BeginPlay()
{
	Super::BeginPlay();

    initialize_HUD();
}

void ABASE_HUD::initialize_HUD()
{
	if (!widget_overlay_class) return;

    widget_overlay_obj = CreateWidget<UUserWidget>(
        GetWorld(),
        widget_overlay_class
    );

	widget_overlay_obj->AddToViewport();
}

UUserWidget * ABASE_HUD::get_widget_obj_base_attributes()
{
    if (Uwidget_overlay * wdg_ovl_ = Cast<Uwidget_overlay>(widget_overlay_obj))
        return wdg_ovl_->get_widget_obj_base_attributes();

    else return nullptr;
}

UUserWidget * ABASE_HUD::set_widget_obj_base_attributes(UUserWidget * widget_base_attr)
{
    if (Uwidget_overlay * wdg_ovl_ = Cast<Uwidget_overlay>(widget_overlay_obj))
        return wdg_ovl_->set_widget_obj_base_attributes(widget_base_attr);

    else return nullptr;

}
