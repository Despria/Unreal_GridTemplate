// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridCellData.generated.h"

UENUM(BlueprintType)
enum class ETerrainType : uint8
{
	Ground = 0,   // 기본 보행 지형 — 별도 이동 능력 불필요
	Water  = 1,   // bCanSwim 또는 bCanFly 필요
	Air    = 2,   // bCanFly 필요 (허공, 낭떠러지 등 — 기존 bRequiresFlying 대체)
};

USTRUCT(BlueprintType)
struct FGridCellData
{
	GENERATED_BODY();
	
	// X, Y, Z Coordinate of Cell
	UPROPERTY(BlueprintReadWrite)
	FIntVector CellGridCoord = FIntVector(0, 0, 0);
	
	// World Vector Location of Cell
	UPROPERTY(BlueprintReadWrite)
	FVector CellWorldLocation = FVector(0, 0, 0);
	
	// MovementCost Minimum = 10
	UPROPERTY(BlueprintReadWrite)
	int32 MovementCost = 10;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsWalkable = true;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsOccupied = false;
	
	// 지형 종류 (기존 bIsWaterTerrain, bRequiresFlying 대체)
	UPROPERTY(BlueprintReadWrite)
	ETerrainType TerrainType = ETerrainType::Ground;
	
	UPROPERTY(BlueprintReadWrite)
	TMap<FIntVector, int32> ExtraMovableCells = TMap<FIntVector, int32>();
};
