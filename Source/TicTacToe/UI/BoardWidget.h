// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BoardWidget.generated.h"

class UPanelWidget;
class UImage;
class UUniformGridPanel;
class UButton;
class UTexture2D;
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
	UButton *Button_0_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_0_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_0_2;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_1_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_1_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_1_2;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_2_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_2_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton *Button_2_2;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Images")
	UTexture2D *XImage;
	UPROPERTY(EditDefaultsOnly, Category = "Images")
	UTexture2D *OImage;

	UFUNCTION()
	void OnButtonPressed();

	UButton *Buttons[3][3];

	void initButtons();
};
