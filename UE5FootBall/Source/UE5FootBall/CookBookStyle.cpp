#include "CookBookStyle.h"
// #include "UE5FootBall.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FCookBookStyle::CookBookStyleInstance = nullptr;

void FCookBookStyle::Initialize()
{
	if(!CookBookStyleInstance.IsValid())
	{
		CookBookStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*CookBookStyleInstance);
	}
}

void FCookBookStyle::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*CookBookStyleInstance);
	ensure(CookBookStyleInstance.IsUnique());
	CookBookStyleInstance.Reset();
}

FName FCookBookStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("CookbookStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(FPaths::ProjectContentDir() / "Slate" / RelativePath + TEXT(".png"), __VA_ARGS__)
#define BOX_BRUSH(RelativePath, ...) FSlateBoxBrush(FPaths::ProjectContentDir() / "Slate" / RelativePath + TEXT(".png"), __VA_ARGS__)
#define BORDER_BRUSH(RelativePath, ...) FSlateBorderBrush(FPaths::ProjectContentDir() / "Slate" / RelativePath + TEXT(".png"), __VA_ARGS__)
#define TTF_FONT(RelativePath, ...) FSlateFontInfo(FPaths::ProjectContentDir() / "Slate" / RelativePath + TEXT(".ttf"), __VA_ARGS__)
#define OTF_BRUSH(RelativePath, ...) FSlateFontInfo(FPaths::ProjectContentDir() / "Slate" / RelativePath + TEXT(".otf"), __VA_ARGS__)

TSharedRef<FSlateStyleSet> FCookBookStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef =
		FSlateGameResources::New
	(FCookBookStyle::GetStyleSetName(), "/Game/Slate",
	"/Game/Slate");
	FSlateStyleSet& Style = StyleRef.Get();
	Style.Set("NormalButtonBrush",
		FButtonStyle()
		.SetNormal(BOX_BRUSH("Button", FVector2D(54, 54), FMargin(14.0f/54.0f))));
	Style.Set("NormalButtonText",
		FTextBlockStyle(FTextBlockStyle::GetDefault())
		.SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 1))));

	return StyleRef;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_BRUSH

void FCookBookStyle::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()
	->ReloadTextureResources();
}

const ISlateStyle& FCookBookStyle::Get()
{
	return *CookBookStyleInstance;
}


