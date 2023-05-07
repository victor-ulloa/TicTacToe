// Created by Spring2022_Capstone team

#include "BaseUIManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameOverWidget.h"
#include "BoardWidget.h"
#include "Components/TextBlock.h"
#include "TicTacToe/TicTacToeGameModeBase.h"

ABaseUIManager::ABaseUIManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseUIManager::BeginPlay()
{
	Super::BeginPlay();

	ATicTacToeGameModeBase *GameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->SetManager(this);

	DisplayWidget();
}

void ABaseUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseUIManager::DisplayWidget()
{
	if (RootWidget)
	{
		_RootWidget = CreateWidget(GetWorld(), RootWidget);
		_RootWidget->AddToViewport(1);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Type not specizfied for Root Widget"));
	}
}

void ABaseUIManager::DismissWidget()
{
	_RootWidget->RemoveFromParent();
}

void ABaseUIManager::DisplayGameOverWidget(bool IsTie)
{
	if (GameOverWidget)
	{
		_GameOverWidget = CreateWidget(GetWorld(), GameOverWidget);
		_GameOverWidget->AddToViewport(2);

		if (UGameOverWidget *widget = Cast<UGameOverWidget>(_GameOverWidget))
		{
			if (IsTie)
			{
				widget->GameOverText->SetText(FText::FromString(TEXT("TIE")));
			}
			else
			{
				widget->GameOverText->SetText(FText::FromString(TEXT("YOU LOST")));
			}
			// widget->GameOverText->SetText( FText::FromString(TEXT((IsTie ? "TIE" : "YOU LOST"))));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Type not specizfied for Game Over Widget"));
	}
}

void ABaseUIManager::DismissGameOverWidget()
{
	_GameOverWidget->RemoveFromParent();
	_GameOverWidget = nullptr;

	if (UBoardWidget *widget = Cast<UBoardWidget>(_RootWidget))
	{
		widget->resetBoard();
	}
}
