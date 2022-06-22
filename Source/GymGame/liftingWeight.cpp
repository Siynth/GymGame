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
    totalStrength = 0.0f;
}

// Called every frame
void AliftingWeight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //framework to modify strength values, replace ifs below by modifying the mass of objects instead to create more fluid game environment
    if (raiseStrength == true) {
        totalStrength += 0.1f;
        AWorldSettings* MyWorldSetting=GetWorldSettings();
 
        if (totalStrength <= 1) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 2) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 3) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 4) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 5) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 6) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 7) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 8) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 9) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else if (totalStrength <= 10) {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        else {
            MyWorldSetting->GlobalGravityZ = 1000.f;
        }
        raiseStrength = false;
    }

}

