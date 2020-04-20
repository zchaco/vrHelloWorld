// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());

	DestinationMarker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DestinationMarker"));
	DestinationMarker->SetupAttachment(GetRootComponent());
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);

}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector cameraOffset = Camera->GetComponentLocation() - GetActorLocation(); 
	cameraOffset.Z = 0;
	AddActorWorldOffset(cameraOffset);

	VRRoot->AddWorldOffset(-cameraOffset);
	UpdateDestinationMarker();

}

void AVRCharacter::UpdateDestinationMarker()
{
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + Camera->GetForwardVector() * MaxTeleportDistance; 

	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	
	DrawDebugLine(GetWorld(), Start, End, FColor::Blue );

	if (bHit){

		DestinationMarker->SetWorldLocation(HitResult.Location);
	}

}

// Called to bind functionality to input, bind the forward and right axis to directional keys
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"),this,&AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"),this,&AVRCharacter::MoveRight);


}

void AVRCharacter::MoveForward(float throttle){
	AddMovementInput(throttle * Camera->GetForwardVector()); 
}

void AVRCharacter::MoveRight(float throttle){
	AddMovementInput(throttle * Camera->GetRightVector());

}


