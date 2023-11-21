#pragma once
  
#include "UE5FootBall.h"
#include "ColoredTexture.generated.h"

USTRUCT(BlueprintType)
struct UE5FOOTBALL_API FColoredTexture
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	UTexture *Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	FLinearColor Color;
};
