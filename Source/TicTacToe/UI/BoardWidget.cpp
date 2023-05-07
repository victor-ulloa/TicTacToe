// Fill out your copyright notice in the Description page of Project Settings.

#include "BoardWidget.h"
#include "CustomButton.h"
#include "Kismet/GameplayStatics.h"
#include "BaseUIManager.h"
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
    Position p = manager.FindBestMove(Buttons);
    if (p.col == -1 || p.row == -1)
    {
        UE_LOG(LogTemp, Display, TEXT("TIE"));
        displayEnd(true);
        return;
    }

    Buttons[p.row][p.col]->drawImage(false);

    int evaluate = manager.EvaluateBoard(Buttons);
    if (evaluate == -10) {
        UE_LOG(LogTemp, Display, TEXT("PC WON GAME"));
        displayEnd(false);
        return;
    }

    // UE_LOG(LogTemp, Display, TEXT("%c %c %c"), Buttons[0][0]->ToChar(), Buttons[0][1]->ToChar(), Buttons[0][2]->ToChar());
    // UE_LOG(LogTemp, Display, TEXT("%c %c %c"), Buttons[1][0]->ToChar(), Buttons[1][1]->ToChar(), Buttons[1][2]->ToChar());
    // UE_LOG(LogTemp, Display, TEXT("%c %c %c"), Buttons[2][0]->ToChar(), Buttons[2][1]->ToChar(), Buttons[2][2]->ToChar());
}

void UBoardWidget::displayEnd(bool IsTie)
{
    if (ATicTacToeGameModeBase *GameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))) {
        GameMode->UIManager->DisplayGameOverWidget(IsTie);
    }
}

void UBoardWidget::resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Buttons[i][j]->clear();
        }
    }
}
