// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "BaseUIManager.h"
#include "TicTacToe/TicTacToeGameModeBase.h"

void UGameOverWidget::NativeConstruct()
{
    Super::NativeConstruct();
    RestartButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnRestartButtonClicked);
}

void UGameOverWidget::OnRestartButtonClicked()
{
    if (ATicTacToeGameModeBase *GameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))) {
        GameMode->UIManager->DismissGameOverWidget();
    }
}
