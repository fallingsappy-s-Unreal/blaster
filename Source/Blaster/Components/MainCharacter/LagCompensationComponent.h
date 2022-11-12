// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LagCompensationComponent.generated.h"

UCLASS()
class BLASTER_API ALagCompensationComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	ALagCompensationComponent();
	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

public:	



};
