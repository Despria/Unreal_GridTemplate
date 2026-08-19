// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridContributorBase.h"

#include "GridMath.h"
#include "GridSettings.h"
#include "Kismet/GameplayStatics.h"

AGridContributorBase::AGridContributorBase()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	AffectedAreaBox = CreateDefaultSubobject<UBoxComponent>(TEXT("AffectedAreaBox"));
	AffectedAreaBox->SetupAttachment(RootComponent);
	AffectedAreaBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AffectedAreaBox->SetGenerateOverlapEvents(false);
	AffectedAreaBox->SetHiddenInGame(true);
	AffectedAreaBox->SetCastShadow(false);
	AffectedAreaBox->SetBoxExtent(FVector(50.f));

	AreaPreviewMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AreaPreviewMesh"));
	AreaPreviewMesh->SetupAttachment(AffectedAreaBox);
	AreaPreviewMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AreaPreviewMesh->SetGenerateOverlapEvents(false);
	AreaPreviewMesh->SetHiddenInGame(true); // 런타임에는 숨김, 에디터에서만 표시
	AreaPreviewMesh->SetCastShadow(false);
	
	const FVector Extent = AffectedAreaBox->GetUnscaledBoxExtent();
	AreaPreviewMesh->SetRelativeScale3D(Extent * 2.f / 100.f);
	UpdateAreaPreviewScale();
}

void AGridContributorBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGridContributorBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateAreaPreviewScale();
}

void AGridContributorBase::UpdateAreaPreviewScale() const
{
	if (!AreaPreviewMesh || !AffectedAreaBox) return;

	// BoxComponent의 Extent -> Box 원점으로부터의 반경을 의미함.
	// 예를 들어, (200, 200, 100)인 경우, Box의 크기는 (400, 400, 200)임 (X = -200~200, Y = -200~200, Z = -100~100).
	const FVector Extent = AffectedAreaBox->GetUnscaledBoxExtent();
	AreaPreviewMesh->SetRelativeScale3D(Extent * 2.f / 100.f); // 엔진 기본 큐브가 100uu 기준일 때
}

TArray<FIntVector> AGridContributorBase::GetAffectedCellCoords()
{
	TArray<FIntVector> Result;
	AActor* Actor = UGameplayStatics::GetActorOfClass(GetWorld(), AGridSettings::StaticClass());
	AGridSettings* GridSettings = Cast<AGridSettings>(Actor);
	if (!GridSettings) return Result;

	const FTransform& BoxTransform = AffectedAreaBox->GetComponentTransform();
	const FVector Extent = AffectedAreaBox->GetUnscaledBoxExtent();

	// 현재는 그리드 상의 모든 Cell을 대상으로 특정 GridContributor 내부에 속하는 지 검사함.
	// 추후 레벨의 그리드 크기 또는 레이어 규모가 커진다면 문제가 될 수 있음. 
	// 이 때는 Box의 각 모서리 위치를 구해서 이를 통해 특정 Cell들만 검사하는 것이 좋아보임.
	for (const auto& Pair : GridSettings->GetGridCellData())
	{
		FVector CellLocalPosition = BoxTransform.InverseTransformPosition(
			UGridMath::CellCenterToWorldLocation
			(Pair.Key, GridSettings->GetGridOrigin(), GridSettings->GetCellSize(), GridSettings->GetLayerBaseHeights()));
		
		if (FMath::Abs(CellLocalPosition.X) <= Extent.X &&
			FMath::Abs(CellLocalPosition.Y) <= Extent.Y &&
			FMath::Abs(CellLocalPosition.Z) <= Extent.Z)
		{
			Result.Add(Pair.Key);
		}
	}
	return Result;
}

bool AGridContributorBase::Apply()
{
	/**
	 * Implement on Subclasses
	 */
	return false;
}

