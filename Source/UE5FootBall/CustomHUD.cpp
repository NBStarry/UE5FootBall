// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomHUD.h"

#include "Engine/Canvas.h"

void ACustomHUD::DrawHUD()
{
	Super::DrawHUD();
	Canvas->DrawText(GEngine->GetSmallFont(), TEXT("Test string to be printed"), 10, 10);
	FCanvasBoxItem ProgressBar(FVector2D(5, 25), FVector2D(100, 5));
	Canvas->DrawItem(ProgressBar);
	DrawRect(FLinearColor::Blue, 5, 25, 100, 5);
}

void ACustomHUD::BeginPlay()
{
	Super::BeginPlay();

	//Add buttons
	SettingsButton = SNew(SVerticalBox) + SVerticalBox::Slot()
	.HAlign(HAlign_Left).VAlign(VAlign_Top)
	[
		SNew(SBox).WidthOverride(200.0f).HeightOverride(100.0f) // 尺寸
		[
			SNew(SButton).HAlign(HAlign_Center).VAlign(VAlign_Center).Content() // 按钮并居中
			[
				SNew(STextBlock) // 文字
				.Text(FText::FromString(TEXT("Settings")))
				.Justification(ETextJustify::Center)
				.Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 24))
			]
		]
	];
	
	FlashWidget = SNew(SVerticalBox) + SVerticalBox::Slot()
	.HAlign(HAlign_Center)
	.VAlign(VAlign_Top)
	[
		SNew(SButton)
		.OnClicked(FOnClicked::CreateUObject(this,
			&ACustomHUD::ButtonClicked))
		.Content()
		[
			SAssignNew(ButtonLabel, STextBlock)
			.Text(FText::FromString(TEXT("Click me!")))
		]
	];
	
	PositionWidget = SNew(SVerticalBox)
	+ SVerticalBox::Slot()
	.HAlign(HAlign_Right)
	.VAlign(VAlign_Top)
	[
		SNew(SButton)
		.Content()
		[
			SNew(STextBlock)
			.Text(TAttribute<FText>::Create(TAttribute<FText>
				::FGetter::CreateUObject(this,
					&ACustomHUD::GetButtonLabel)))
		]
	];
	
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()
		->GetFirstLocalPlayerFromController(),
		SettingsButton.ToSharedRef(), 1);

	GEngine->GameViewport
	->AddViewportWidgetForPlayer(GetWorld()
		->GetFirstLocalPlayerFromController(),
		PositionWidget.ToSharedRef(), 1);
	
	GEngine->GameViewport
	->AddViewportWidgetForPlayer(GetWorld()
		->GetFirstLocalPlayerFromController(),
		FlashWidget.ToSharedRef(), 1);
	
	GetWorld()->GetTimerManager().SetTimer(HUDToggleTimer,
		FTimerDelegate::CreateLambda
		([this]
		{
			if(this->FlashWidget->GetVisibility().IsVisible())
			{
				this->FlashWidget->SetVisibility(EVisibility::Hidden);
			}
			else
			{
				this->FlashWidget->SetVisibility(EVisibility::Visible);
			}
		}), 5, true);
}

void ACustomHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(HUDToggleTimer); //回收计时器
}

FReply ACustomHUD::ButtonClicked() const
{
	ButtonLabel->SetText(FText::FromString(TEXT("haha")));
	return FReply::Handled();
}

FText ACustomHUD::GetButtonLabel() const
{
	const FVector ActorLocation = GetWorld()
	->GetFirstPlayerController()->GetPawn()
	->GetActorLocation();
	return FText::FromString(FString::Printf(
		TEXT("%f, %f, %f"),
		ActorLocation.X, ActorLocation.Y, ActorLocation.Z));
}



