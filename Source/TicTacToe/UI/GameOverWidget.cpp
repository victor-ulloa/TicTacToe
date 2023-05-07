// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverWidget.h"
#include "Components/Button.h"

void UGameOverWidget::NativeConstruct()
{
    Super::NativeConstruct();
    RestartButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnRestartButtonClicked);
}

void UGameOverWidget::OnRestartButtonClicked()
{
    
}
