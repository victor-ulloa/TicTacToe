// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomButton.h"
#include "Components/Button.h"
#include "Engine/Texture2D.h"

void UCustomButton::NativeConstruct()
{
    Super::NativeConstruct();

    MainButton->OnClicked.AddUniqueDynamic(this, &UCustomButton::OnButtonClicked);
}

void UCustomButton::OnButtonClicked()
{
    drawImage();
}

void UCustomButton::drawImage(bool isPlayer)
{
    MainButton->SetIsEnabled(false);
    MainButton->WidgetStyle.Normal.SetResourceObject(isPlayer ? XImage : OImage);
    MainButton->WidgetStyle.Disabled.TintColor;
}
