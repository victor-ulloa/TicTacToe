// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"
#include "UI/BoardWidget.h"
#include "UI/CustomButton.h"

void ATicTacToeGameModeBase::SetBoard(UBoardWidget *NewBoard)
{
    Board = NewBoard;
}

void ATicTacToeGameModeBase::SetManager(ABaseUIManager *NewUIManager)
{
    if (!UIManager){
        UIManager = NewUIManager;
    }
}
