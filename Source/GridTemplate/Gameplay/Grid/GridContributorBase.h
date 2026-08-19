// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridContributor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GridContributorBase.generated.h"

UENUM(BlueprintType)
enum class EGridContributorType : uint8
{
	Terrain, 
	Obstacle, 
	UnitSpawn
};

UCLASS(Abstract)
class GRIDTEMPLATE_API AGridContributorBase : public AActor, public IGridContributor
{
	GENERATED_BODY()
	
public:	
	AGridContributorBase();
	
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|Area")
	TObjectPtr<UBoxComponent> AffectedAreaBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|Area")
	TObjectPtr<UStaticMeshComponent> AreaPreviewMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid|Area")
	EGridContributorType ContributorType = EGridContributorType::Terrain;

	void UpdateAreaPreviewScale() const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid|Area")
	EGridContributorType GridContributorType = EGridContributorType::Obstacle;
	
	virtual TArray<FIntVector> GetAffectedCellCoords() override;

	/**
	 * Must implement on Subclasses.
	 * @return Is Apply Success?
	 */
	virtual bool Apply() override;
};
