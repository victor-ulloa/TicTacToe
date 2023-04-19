// Fill out your copyright notice in the Description page of Project Settings.

#include "BoardWidget.h"
#include "Components/Button.h"

void UBoardWidget::NativeConstruct()
{
    Super::NativeConstruct();


}

void UBoardWidget::OnButtonPressed()
{
    
}

void UBoardWidget::initButtons()
{
    Buttons[0][0] = Button_0_0;
    Buttons[0][1] = Button_0_1;
    Buttons[0][2] = Button_0_2;
    Buttons[1][0] = Button_1_0;
    Buttons[1][1] = Button_1_1;
    Buttons[1][2] = Button_1_2;
    Buttons[2][0] = Button_2_0;
    Buttons[2][1] = Button_2_1;
    Buttons[2][2] = Button_2_2;

    Button_0_0->OnClicked.AddUniqueDynamic(this, &UBoardWidget::OnButtonPressed);
}
