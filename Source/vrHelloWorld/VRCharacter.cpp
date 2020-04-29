// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Camera/PlayerCameraManager.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"
#include "NavigationSystem.h"
#include "Components/PostProcessComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Curves/CurveFloat.h"
#include "Math/Vector.h"



// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());

	DestinationMarker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DestinationMarker"));
	DestinationMarker->SetupAttachment(GetRootComponent());
	DestinationMarker->SetVisibility(false);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);

	PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcessingComponent"));
	PostProcessComponent->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (BlinkerMaterialBase != nullptr)
	{
		BlinkerMaterialInstance = UMaterialInstanceDynamic::Create(BlinkerMaterialBase, this);
		PostProcessComponent->AddOrUpdateBlendable(BlinkerMaterialInstance);
	}	
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

	UpdateBlinkers();
	
}

bool AVRCharacter::FindTeleportDestination(FVector &OutLocation)
{
	
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + Camera->GetForwardVector() * MaxTeleportDistance; 

	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	
	//DrawDebugLine(GetWorld(), Start, End, FColor::Blue );
	if(!bHit) return false;
		
		
	FNavLocation NavLocation;
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	bool bOnNavMesh = NavSystem->ProjectPointToNavigation(HitResult.Location, NavLocation, TeleportProjectionExtent);

	if(!bOnNavMesh) return false;
	
	OutLocation = NavLocation.Location;
	
	return true;
}


void AVRCharacter::UpdateDestinationMarker()
{
	FVector Location;
	bool bHasDestination = FindTeleportDestination(Location);

	if (bHasDestination)
	{

		DestinationMarker->SetVisibility(true);
		DestinationMarker->SetWorldLocation(Location);
	}

	else
	{
		DestinationMarker->SetVisibility(false);
	}

}

// Called to bind functionality to input, bind the forward and right axis to directional keys
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"),this,&AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"),this,&AVRCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Teleport"),IE_Released,this, &AVRCharacter::BeginTeleport);


}

void AVRCharacter::MoveForward(float throttle)
{
	AddMovementInput(throttle * Camera->GetForwardVector()); 
}

void AVRCharacter::MoveRight(float throttle){
	AddMovementInput(throttle * Camera->GetRightVector());

}

void AVRCharacter::BeginTeleport()
{
	//Fade Out, teleport, and Fade in 
	StartFade(0,1);
	
	FTimerHandle Handle;
	GetWorldTimerManager().SetTimer(Handle, this, &AVRCharacter::FinishTeleport, TeleportFadeTime);
	
}

void AVRCharacter::FinishTeleport()
{
	
	FVector Destination = DestinationMarker->GetComponentLocation();
	Destination += GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * GetActorUpVector();
	SetActorLocation(Destination);
	
	//Fade Out, teleport, and Fade in 
	StartFade(1,0);
	
}

void AVRCharacter::StartFade(float FromAlpha, float ToAlpha){
	
	APlayerController* PC = Cast<APlayerController>(GetController());
	if( PC != nullptr)
	{
		PC->PlayerCameraManager->StartCameraFade(FromAlpha, ToAlpha, TeleportFadeTime, FLinearColor::Black, false, true);
	}
}

void AVRCharacter::UpdateBlinkers()
{

	if (RadiusVsVelocity == nullptr) return;

	float Speed = GetVelocity().Size();
	float Radius = RadiusVsVelocity->GetFloatValue(Speed);
	BlinkerMaterialInstance->SetScalarParameterValue(TEXT("Radius"), Radius);

	FVector2D Center = GetBlinkerCenter();
	BlinkerMaterialInstance->SetVectorParameterValue(TEXT("Center"), FLinearColor(Center.X, Center.Y, 0));


}

//Calculate the direction the player is moving. Get the camera's location and add the movement direction to it. Then, project 
///that world location back onto the screen
FVector2D AVRCharacter::GetBlinkerCenter()
{
	FVector MovementDirection = GetVelocity().GetSafeNormal();
	
	if (MovementDirection.IsNearlyZero())
	{
		return FVector2D(0.5,0.5);
	}

	FVector WorldStationaryLocation;
	if (FVector::DotProduct(Camera->GetForwardVector(), MovementDirection) > 0)
	{
			WorldStationaryLocation = Camera->GetComponentLocation() + MovementDirection * 1000;
	} 
	else
	{
			WorldStationaryLocation = Camera->GetComponentLocation() - MovementDirection * 1000;
	}
	APlayerController* PC = Cast<APlayerController>(GetController());
	
	if(PC == nullptr)
	{
		return FVector2D(0.5,0.5);
	}

	FVector2D ScreenStationaryLocation;
	PC->ProjectWorldLocationToScreen(WorldStationaryLocation, ScreenStationaryLocation);

	int32 SizeX, SizeY;
	PC->GetViewportSize(SizeX, SizeY);

	ScreenStationaryLocation.X /= SizeX;
	ScreenStationaryLocation.Y /= SizeY;

	return ScreenStationaryLocation;
	
}


