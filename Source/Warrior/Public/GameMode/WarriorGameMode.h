// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WarriorTypes/WarriorEnumTypes.h"
#include "WarriorGameMode.generated.h"


/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AWarriorGameMode();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	EWarriorGameDifficulty CurrentGameDifficulty;
	

public:
	FORCEINLINE EWarriorGameDifficulty GetCurrentGameDifficulty() const {return CurrentGameDifficulty;}
	
};
