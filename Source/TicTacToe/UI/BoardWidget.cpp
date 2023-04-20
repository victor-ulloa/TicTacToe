// Fill out your copyright notice in the Description page of Project Settings.

#include "BoardWidget.h"
#include "Components/Button.h"
#include "CustomButton.h"
#include "Kismet/GameplayStatics.h"
#include "TicTacToe/TicTacToeGameModeBase.h"

void UBoardWidget::NativeConstruct()
{
    Super::NativeConstruct();

    APlayerController *PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        PC->bShowMouseCursor = true;
        PC->bEnableClickEvents = true;
        PC->bEnableMouseOverEvents = true;
    }

    ATicTacToeGameModeBase *GameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
    GameMode->SetBoard(this);

    initButtons();
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

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Buttons[i][j]->OnClickedDelegate.BindUObject(this, &UBoardWidget::OnButtonClicked);
        }
    }
}

void UBoardWidget::OnButtonClicked()
{
    Position p = manager.FindBestMove_(Buttons);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (Buttons[i][j]->State)
            {
            case UCustomButton::ButtonState::X:
                UE_LOG(LogTemp, Display, TEXT("X"));
                break;

            case UCustomButton::ButtonState::O:
                UE_LOG(LogTemp, Display, TEXT("O"));
                break;

            case UCustomButton::ButtonState::NONE:
                UE_LOG(LogTemp, Display, TEXT("_"));
                break;

            default:
                break;
            }
        }
    }

    Buttons[p.row][p.col]->drawImage(false);
}
