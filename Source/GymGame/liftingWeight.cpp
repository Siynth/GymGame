// Fill out your copyright notice in the Description page of Project Settings.


#include "liftingWeight.h"

// Sets default values
AliftingWeight::AliftingWeight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    VisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
}

// Called when the game starts or when spawned
void AliftingWeight::BeginPlay()
{
	Super::BeginPlay();
	raiseStrength = false;
}

// Called every frame
void AliftingWeight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (raiseStrength == true) {
        AWorldSettings* MyWorldSetting=GetWorldSettings();
        MyWorldSetting->GlobalGravityZ = 1000.f;
    }

}

