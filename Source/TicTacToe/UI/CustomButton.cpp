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
    OnClickedDelegate.ExecuteIfBound();
}

void UCustomButton::drawImage(bool isPlayer)
{
    State = isPlayer ? ButtonState::X : ButtonState::O;
    MainButton->SetIsEnabled(false);
    MainButton->WidgetStyle.Normal.SetResourceObject(isPlayer ? XImage : OImage);
    MainButton->WidgetStyle.Disabled.TintColor;
}
