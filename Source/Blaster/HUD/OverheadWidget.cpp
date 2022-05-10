// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	auto PlayerState = InPawn->GetPlayerState();

	if (!PlayerState)
	{
		return;
	}
	
	auto PlayerName = PlayerState->GetPlayerName();
	
	FString PlayerNameString = FString::Printf(TEXT("Name: %s"), *PlayerName);

	SetDisplayText(PlayerNameString);
}


void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch (LocalRole)
	{
		case ROLE_None:
			Role = FString("None");
			break;
		case ROLE_SimulatedProxy:
			Role = FString("SimulatedProxy");
			break;
		case ROLE_AutonomousProxy:
			Role = FString("AutonomousProxy");
			break;
		case ROLE_Authority:
			Role = FString("Authority");
			break;
	}
	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);

	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::ShowRemotePlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
		case ROLE_None:
			Role = FString("None");
			break;
		case ROLE_SimulatedProxy:
			Role = FString("SimulatedProxy");
			break;
		case ROLE_AutonomousProxy:
			Role = FString("AutonomousProxy");
			break;
		case ROLE_Authority:
			Role = FString("Authority");
			break;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);

	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);

	RemoveFromParent();
}
