// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridMath.h"

/**
 * Switch Cell Coordinate into World Location.
 * Unreal World Coordinate -> X Axis = Front/Back, Y Axis = Left/Right,
 * Need to Swap X <-> Y to make it looks like Unreal X/Y Axis Coordinate.
 * @param CellCoord FIntVector Cell Coordinate to convert into World Location.
 * @return WorldLocation FVector
 */
FVector UGridMath::CellCoordToWorldLocation(FIntVector CellCoord, FVector GridOrigin, float CellSize,
	TMap<int32, float> LayerBaseHeights)
{
	// 그리드 좌표를 월드 좌표로 변환
	const float* BaseHeight = LayerBaseHeights.Find(CellCoord.Z);
	const float LayerZ = BaseHeight ? *BaseHeight : 0.f;

	return FVector(
		// 언리얼의 좌표계는 Y축이 좌/우, X축이 앞/뒤를 가리키므로, 서로 변환해서 반환해야 함.
		GridOrigin.X + (CellCoord.Y * CellSize),
		GridOrigin.Y + (CellCoord.X * CellSize),
		GridOrigin.Z + LayerZ + 0.f  // HeightOffset은 SetCellHeightOffset으로 별도 설정
	);
}

/**
 * Switch Cell Coordinate into World Location.
 * Unreal World Coordinate -> X Axis = Front/Back, Y Axis = Left/Right,
 * Need to Swap X <-> Y to make it looks like Unreal X/Y Axis Coordinate.
 * @param CellCoord FIntVector Cell Coordinate to convert into World Location.
 * @return WorldLocation FVector
 */
FVector UGridMath::CellCenterToWorldLocation(FIntVector CellCoord, FVector GridOrigin, float CellSize,
	TMap<int32, float> LayerBaseHeights)
{
	const float* BaseHeight = LayerBaseHeights.Find(CellCoord.Z);
	const float LayerZ = BaseHeight ? *BaseHeight : 0.f;

	return FVector(
		GridOrigin.X + (CellCoord.Y * CellSize) + (CellSize * 0.5f),
		GridOrigin.Y + (CellCoord.X * CellSize) + (CellSize * 0.5f),
		GridOrigin.Z + LayerZ + 0.f  // HeightOffset은 SetCellHeightOffset으로 별도 설정
	);
}

/**
 * Switch World Location into Cell Coordinate.
 * Unreal World Coordinate -> X Axis = Front/Back, Y Axis = Left/Right,
 * Need to Swap X <-> Y to make it looks like Standard X/Y Axis Coordinate.
 * @param WorldLocation FVector World Location to convert into Cell Coordinate.
 * @return CellCoord FIntVector
 */
FIntVector UGridMath::WorldLocationToCellCoord(FVector WorldLocation, FVector GridOrigin, float CellSize,
                                               int32 ActiveLayer)
{
	int32 CoordX= FMath::FloorToInt((WorldLocation.Y - GridOrigin.Y) / CellSize);
	int32 CoordY= FMath::FloorToInt((WorldLocation.X - GridOrigin.X) / CellSize);
	
	return FIntVector(CoordX, CoordY, ActiveLayer);
}

