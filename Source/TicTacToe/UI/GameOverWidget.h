// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UPanelWidget;
class UImage;
class UTextBlock;
class UButton;

/**
 *
 */
UCLASS()
class TICTACTOE_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UPanelWidget *RootPanel;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage *Background;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock *GameOverText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *RestartButton;
};
