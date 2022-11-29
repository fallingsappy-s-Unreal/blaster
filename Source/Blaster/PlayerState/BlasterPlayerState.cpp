// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterPlayerState.h"

#include "Blaster/Characters/MainCharacter/BlasterCharacter.h"
#include "Blaster/PlayerController/BlasterPlayerController.h"
#include "Net/UnrealNetwork.h"

void ABlasterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABlasterPlayerState, Defeats);
	DOREPLIFETIME(ABlasterPlayerState, Team);
}

void ABlasterPlayerState::AddToScore(float ScoreAmount)
{
	SetScore(GetScore() + ScoreAmount);

	ChangeScore(GetScore());
}

void ABlasterPlayerState::OnRep_Score()
{
	Super::OnRep_Score();

	ChangeScore(GetScore());
}

void ABlasterPlayerState::ChangeScore(float ScoreAmount)
{
	Character = Character == nullptr ? Cast<ABlasterCharacter>(GetPawn()) : Character;

	if (Character)
	{
		Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(Character->Controller) : Controller;

		if (Controller)
		{
			Controller->SetHUDScore(ScoreAmount);
		}
	}
}

void ABlasterPlayerState::AddToDefeats(int32 DefeatsAmount)
{
	Defeats += DefeatsAmount;
	
	ChangeDefeats(Defeats);
}

void ABlasterPlayerState::OnRep_Defeats()
{
	ChangeDefeats(Defeats);
}

void ABlasterPlayerState::ChangeDefeats(int32 DefeatsAmount)
{
	Character = Character == nullptr ? Cast<ABlasterCharacter>(GetPawn()) : Character;

	if (Character)
	{
		Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(Character->Controller) : Controller;

		if (Controller)
		{
			Controller->SetHUDDefeats(DefeatsAmount);
		}
	}
}

