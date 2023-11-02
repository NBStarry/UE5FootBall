#pragma once
#include "SlateBasics.h"
#include "SlateExtras.h"

class FCookBookStyle
{
public:
	static void Initialize();
	static void ShutDown();
	static void ReloadTextures();
	static const ISlateStyle& Get();
	static FName GetStyleSetName();

private:
	static TSharedRef<class FSlateStyleSet> Create();
	static TSharedPtr<class FSlateStyleSet> CookBookStyleInstance;
};
