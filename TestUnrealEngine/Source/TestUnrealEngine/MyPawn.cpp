// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
    Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));

    RootComponent = Mesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

    if (SM.Succeeded()) {
        Mesh->SetStaticMesh(SM.Object);
    }

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
    PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);
    // joystict of control
    
    

}

void AMyPawn::UpDown(float Value) {
    
    if (Value == 0.f)
        return;
    // if value is 0.0, no print
    
    // [22.01.01] Let's move Pawn
    AddMovementInput(GetActorForwardVector(), Value);
    
    // UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);
    
}

void AMyPawn::LeftRight(float Value) {
    
    if (Value == 0.f)
        return;
    // if value is 0.0, no print
    
    // [22.01.01] Let's move Pawn
    AddMovementInput(GetActorRightVector(), Value);
    
    // UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
    
    
}

