// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomButton.generated.h"

class UTexture2D;
class UCustomButton;

DECLARE_DELEGATE(FOnClickedSignature);

/**
 *
 */
UCLASS()
class TICTACTOE_API UCustomButton : public UUserWidget
{
	GENERATED_BODY()

public:
	FOnClickedSignature OnClickedDelegate;

protected:
	virtual void NativeConstruct() override;

	// In the Blueprint subclass, make sure you create aButton called "MainButton"
	UPROPERTY(meta = (BindWidget))
	class UButton *MainButton;

	UFUNCTION()
	void OnButtonClicked();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Images")
	UTexture2D *XImage;
	UPROPERTY(EditDefaultsOnly, Category = "Images")
	UTexture2D *OImage;

public:

	enum ButtonState {
		X,
		O,
		NONE,
	};

	ButtonState State = ButtonState::NONE;
	
	void drawImage(bool isPlayer = true);
};
