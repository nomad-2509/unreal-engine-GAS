// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/widget_overlay.h"


void Uwidget_overlay::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    // Create and set widget - base attributes
    UUserWidget * wid_base_attr_ = create_widget_base_attribute();

    if (wid_base_attr_)
        set_widget_base_attributes(wid_base_attr_);

    // Create and set widget - reticle
    UUserWidget * wid_reticle_ = create_widget_reticle();

    if (wid_reticle_)
        set_widget_reticle(wid_reticle_);

}

UUserWidget * Uwidget_overlay::create_widget_base_attribute()
{
    if (!widget_base_attributes_class)
        return nullptr;

    return
        CreateWidget<UUserWidget>(this, widget_base_attributes_class);

}

void Uwidget_overlay::set_widget_base_attributes(UUserWidget * widget_base_attr)
{
    if (!widget_base_attr) return;

    widget_base_attributes = widget_base_attr;

    wrap_box_base_attr_widget->ClearChildren();
    wrap_box_base_attr_widget->AddChildToWrapBox(widget_base_attributes);

}

UUserWidget * Uwidget_overlay::create_widget_reticle()
{
    if (!widget_class_reticle)
        return nullptr;

    return
        CreateWidget<UUserWidget>(this, widget_class_reticle);
}

void Uwidget_overlay::set_widget_reticle(UUserWidget * widget_reticle)
{
    if (!widget_reticle) return;

    widget_obj_reticle = widget_reticle;

    wrap_box_reticle->ClearChildren();
    wrap_box_reticle->AddChildToWrapBox(widget_obj_reticle);
}

UUserWidget * Uwidget_overlay::get_widget_obj_base_attributes()
{
    return widget_base_attributes;
}

UUserWidget * Uwidget_overlay::set_widget_obj_base_attributes(UUserWidget * widget_base_attr)
{
    set_widget_base_attributes(widget_base_attr);
    return widget_base_attributes;
}
