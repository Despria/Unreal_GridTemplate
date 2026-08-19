// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridContributorBase.h"
#include "GameFramework/Actor.h"
#include "GridContributorObstacle.generated.h"

UCLASS()
class GRIDTEMPLATE_API AGridContributorObstacle : public AGridContributorBase
{
	GENERATED_BODY()
	
public:	
	AGridContributorObstacle();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Build")
	TObjectPtr<UStaticMeshComponent> ObstacleStaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Build")
	TObjectPtr<USkeletalMeshComponent> ObstacleSkeletalMesh;
	
	virtual TArray<FIntVector> GetAffectedCellCoords() override;
	virtual bool Apply() override;
};
