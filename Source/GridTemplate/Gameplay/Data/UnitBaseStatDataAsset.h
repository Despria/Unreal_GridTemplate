// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UnitBaseStatDataAsset.generated.h"


UENUM(Blueprintable)
enum class EGridUnitStatusEffect : uint8
{
	Normal = 0,
	Poison = 1,
	Paralyzed = 2,
	Frozen = 3,
	Burn = 4,
	Sleep = 5,
	Bleeding = 6,
	Stun = 7,
	Silence = 8,
	Blind = 9,
	Invincible = 99
};

/**
 * Data Asset to define Unit Status, e.g. HP, AttackPoint, MovementPoint.
 */
UCLASS(Abstract)
class GRIDTEMPLATE_API UUnitBaseStatDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(TEXT("UnitBaseStat"), GetFName());
	};
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status")
	FName UnitName;
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseHitPoint;
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseAttackPoint;
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseDefencePoint;

	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseActionSpeed;
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	EGridUnitStatusEffect StatusEffect;
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	int32 MovementPoint;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	bool bIsDiagonal;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	bool bIsFlyable;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	bool bIsSwimmable;
};

USTRUCT(Blueprintable)
struct FUnitBaseStatData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit")
	FName UnitName;
	
	// Hit Point(HP)
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseHitPoint = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BonusHitPoint = 0;
	
	// Attack Point, Spells
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseAttackPoint = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BonusAttackPoint = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BonusAttackRange = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	TArray<TSoftObjectPtr<UDataAsset>> Spells = TArray<TSoftObjectPtr<UDataAsset>>();
	
	// Defense Point
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseDefencePoint = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BonusDefencePoint = 0;
	
	// Action Speed
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BaseActionSpeed = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	int32 BonusActionSpeed = 0;
	
	// Status Effect
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Combat")
	EGridUnitStatusEffect StatusEffect = EGridUnitStatusEffect::Normal;
	
	// Movement
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	int32 MovementPoint = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	bool bIsDiagonal = true;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	bool bIsFlyable = false;
	UPROPERTY(BlueprintReadWrite, Category = "Grid|Unit|Status|Movement")
	bool bIsSwimmable = false;
	
	virtual void InitializeFromBaseStat(const UUnitBaseStatDataAsset* UnitBaseStatDataAsset)
	{
		if (!UnitBaseStatDataAsset) return;
		
		UnitName = UnitBaseStatDataAsset->UnitName;
		BaseHitPoint = UnitBaseStatDataAsset->BaseHitPoint;
		BaseAttackPoint = UnitBaseStatDataAsset->BaseAttackPoint;
		BaseDefencePoint = UnitBaseStatDataAsset->BaseDefencePoint;
		BaseActionSpeed = UnitBaseStatDataAsset->BaseActionSpeed;
		MovementPoint = UnitBaseStatDataAsset->MovementPoint;
		bIsDiagonal = UnitBaseStatDataAsset->bIsDiagonal;
		bIsFlyable = UnitBaseStatDataAsset->bIsFlyable;
		bIsSwimmable = UnitBaseStatDataAsset->bIsSwimmable;
		StatusEffect = UnitBaseStatDataAsset->StatusEffect;
		
		// 구조를 유닛을 매개변수로 받아서 유닛 데이터를 초기화 하는 것으로 변경해야 할 듯
	}
};
