// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Character Camera Setting Logic
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
    
    SpringArm->SetupAttachment(GetCapsuleComponent());
    Camera->SetupAttachment(SpringArm);
    
    SpringArm->TargetArmLength = 500.f;
    SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
    
    GetMesh()->SetRelativeLocationAndRotation(
                                              FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
    
    // set Mesh and revise USkeletalMesh file
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Users/mango_mac/CPP_UnrealEngine_basic/TestUnrealEngine/Content/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone'"));

    if (SM.Succeeded()) {
        GetMesh()->SetSkeletalMesh(SM.Object);
    }

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
    PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
    PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);
    // joystict of control

}

void AMyCharacter::UpDown(float Value) {
    
    if (Value == 0.f)
        return;
    // if value is 0.0, no print
    
    // [22.01.01] Let's move Pawn
    AddMovementInput(GetActorForwardVector(), Value);
    
    // UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);
    
}

void AMyCharacter::LeftRight(float Value) {
    
    if (Value == 0.f)
        return;
    // if value is 0.0, no print
    
    // [22.01.01] Let's move Pawn
    AddMovementInput(GetActorRightVector(), Value);
    
    // UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
    
}

void AMyCharacter::Yaw(float Value) {
    AddControllerYawInput(Value);
}
