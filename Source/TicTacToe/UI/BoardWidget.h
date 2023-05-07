// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TicTacToe/OptimalMovement.cpp"
#include "BoardWidget.generated.h"

class UPanelWidget;
class UImage;
class UUniformGridPanel;
class UCustomButton;
/**
 *
 */
UCLASS()
class TICTACTOE_API UBoardWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UPanelWidget *RootPanel;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage *Background;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UPanelWidget *GamePanel;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage *GameBackground;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UUniformGridPanel *GameGrid;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_0_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_0_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_0_2;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_1_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_1_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_1_2;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_2_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_2_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCustomButton *Button_2_2;

private:
	void initButtons();
	OptimalMovement manager;

	UFUNCTION()
	void OnButtonClicked();

	void displayEnd(bool IsTie);

public:
	UCustomButton *Buttons[3][3];
};
