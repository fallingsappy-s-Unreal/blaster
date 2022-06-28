// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BlasterHUD.generated.h"

USTRUCT(BlueprintType)
struct FHUDPackage
{
	GENERATED_BODY()

public:
	FHUDPackage() {  }
	
	FHUDPackage(UTexture2D* CrosshairsCenter, UTexture2D* CrosshairsLeft, UTexture2D* CrosshairsRight,
	            UTexture2D* CrosshairsBottom, UTexture2D* CrosshairsTop)
	{
		this->CrosshairsCenter = CrosshairsCenter;
		this->CrosshairsLeft = CrosshairsLeft;
		this->CrosshairsRight = CrosshairsRight;
		this->CrosshairsBottom = CrosshairsBottom;
		this->CrosshairsTop = CrosshairsTop;
	}

	class UTexture2D* CrosshairsCenter;
	UTexture2D* CrosshairsLeft;
	UTexture2D* CrosshairsRight;
	UTexture2D* CrosshairsBottom;
	UTexture2D* CrosshairsTop;
	
	float CrosshairsSpread;
};

/**
 * 
 */
UCLASS()
class BLASTER_API ABlasterHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

private:
	FHUDPackage HUDPackage;
	
	void DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter, FVector2D Spread);

	UPROPERTY(EditAnywhere)
	float CrosshairSpreadMax = 16.f;
public:
	FORCEINLINE void SetHUDPackage(const FHUDPackage& Package) { HUDPackage = Package; }
};
