// Fill out your copyright notice in the Description page of Project Settings.


#include "enemyNPC.h"

// Sets default values
AenemyNPC::AenemyNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    VisualMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AenemyNPC::BeginPlay()
{
	Super::BeginPlay();

    NewScale = 50.f;

    float Mass = VisualMesh->GetMass();
    UE_LOG(LogTemp, Warning, TEXT(">>>> Starting Mass = %s"),*FString::SanitizeFloat(Mass));

    VisualMesh->GetBodyInstance()->bOverrideMass = true;
    VisualMesh->SetMassOverrideInKg(NAME_None,this->NewScale);
    VisualMesh->GetBodyInstance()->UpdateMassProperties();

    Mass = VisualMesh->GetMass();
    UE_LOG(LogTemp, Warning, TEXT(">>>> New Mass = %s"),*FString::SanitizeFloat(Mass));
}

// Called every frame
void AenemyNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

