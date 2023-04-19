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
    UE_LOG(LogTemp, Display, TEXT("HERE 2"));
    MainButton->SetIsEnabled(false);
    MainButton->WidgetStyle.Normal.SetResourceObject(XImage);
    MainButton->WidgetStyle.Disabled.TintColor;
}
