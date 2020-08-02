// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "mainChar.generated.h"

UCLASS()
class SIMPLEFPS_API AmainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AmainChar();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "camera")
	class UCameraComponent* camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "gun")
	class USkeletalMeshComponent* gun;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "gun")
		class UBoxComponent* box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ball;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void moveFB(float val);

	void mouseX(float val);

	void mouseY(float val);

	void Fire();


};
