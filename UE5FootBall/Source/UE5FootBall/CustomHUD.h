// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE5FOOTBALL_API ACustomHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	FReply ButtonClicked() const;
	FText GetButtonLabel() const;

private:
	UPROPERTY() // 让timer不要被当做垃圾回收
	FTimerHandle HUDToggleTimer;

	// TSharedPtr<SVerticalBox> StyledButton;
	TSharedPtr<SVerticalBox> FlashWidget;
	TSharedPtr<STextBlock> ButtonLabel;
	TSharedPtr<SVerticalBox> SettingsButton;
	TSharedPtr<SVerticalBox> PositionWidget;
	
};
