// Fill out your copyright notice in the Description page of Project Settings.


#include "mainChar.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AmainChar::AmainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(RootComponent);

	gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("gun"));
	gun->SetupAttachment(camera);

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	box->SetupAttachment(camera);

}

// Called when the game starts or when spawned
void AmainChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AmainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("forward", this, &AmainChar::moveFB);
	PlayerInputComponent->BindAxis("xaxis", this, &AmainChar::mouseX);
	PlayerInputComponent->BindAxis("yaxis", this, &AmainChar::mouseY);

}

void AmainChar :: moveFB(float val) {
	if (Controller) {
		FRotator rotation = camera->GetRelativeRotation();
		FRotator yawRoation = FRotator(0, rotation.Yaw, 0);

		FVector dir = FRotationMatrix(yawRoation).GetUnitAxis(EAxis::X);

		AddMovementInput(dir, val);

	}
}

void AmainChar::mouseX(float val) {
	FRotator rot = camera->GetRelativeRotation();

	rot.Yaw += val;

	camera->SetRelativeRotation(rot);
}

void AmainChar::mouseY(float val) {
	FRotator newR = camera->GetRelativeRotation();

	newR.Pitch = FMath::Clamp(newR.Pitch+val, -20.0f,80.0f);

	camera->SetRelativeRotation(newR);

}
