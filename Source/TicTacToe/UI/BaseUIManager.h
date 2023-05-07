// Created by Spring2022_Capstone team

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseUIManager.generated.h"

class UUserWidget;
UCLASS()
class TICTACTOE_API ABaseUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseUIManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> RootWidget;
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> GameOverWidget;

	UFUNCTION()
	void DisplayWidget();
	UFUNCTION()
	void DismissWidget();

	UFUNCTION()
	void DisplayGameOverWidget(bool IsTie);
	UFUNCTION()
	void DismissGameOverWidget();

private:
	UUserWidget *_RootWidget;
	UUserWidget *_GameOverWidget;

};
