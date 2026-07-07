// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/GameMode/GridGameMode.h"
#include "Gameplay/PlayerController/GridPlayerController.h"

AGridGameMode::AGridGameMode()
{
	PlayerControllerClass = AGridPlayerController::StaticClass();
}
