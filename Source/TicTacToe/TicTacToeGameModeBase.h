// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TicTacToeGameModeBase.generated.h"

class UBoardWidget;
class ABaseUIManager;
/**
 *
 */
UCLASS()
class TICTACTOE_API ATicTacToeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UBoardWidget *Board;

public:

	ABaseUIManager *UIManager;

	void SetBoard(UBoardWidget *NewBoard);
	void SetManager(ABaseUIManager *NewUIManager);
};
