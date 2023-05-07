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

char UCustomButton::ToChar()
{
     switch (State)
            {
            case UCustomButton::ButtonState::X:
                return 'X';

            case UCustomButton::ButtonState::O:
                return 'O';

            default:
                return '_';
            }
}

void UCustomButton::drawImage(bool isPlayer)
{
    State = isPlayer ? ButtonState::X : ButtonState::O;
    MainButton->SetIsEnabled(false);
    MainButton->WidgetStyle.Normal.SetResourceObject(isPlayer ? XImage : OImage);
    // MainButton->WidgetStyle.Disabled.TintColor;
}

void UCustomButton::clear()
{
    State = ButtonState::NONE;
    MainButton->SetIsEnabled(true);
    MainButton->WidgetStyle.Normal.SetResourceObject(nullptr);
}
