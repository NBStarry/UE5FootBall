// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ColoredTexture.h"
#include "UserProfile.h"
#include "UE5FootBallCharacter.generated.h"

UENUM(BlueprintType)
enum class EStatus : uint8
{
	Stopped UMETA(DisplayName = "Stopped"),
	Moving UMETA(DisplayName = "Moving"),
	Attacking UMETA(DisplayName = "Attacking"),
};

UCLASS(Blueprintable, BlueprintType)
class AUE5FootBallCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUE5FootBallCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	FColoredTexture Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	EStatus Status; 

	UFUNCTION(BlueprintCallable, Category = Properties)
	FString ToString() const;
	
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};

