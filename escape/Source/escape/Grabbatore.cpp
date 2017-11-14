// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabbatore.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "Components/InputComponent.h"


#define OUTPUT

// Sets default values for this component's properties
UGrabbatore::UGrabbatore()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabbatore::BeginPlay()
{
	Super::BeginPlay();

	//assegnazione dei componenti
	FindPhysicsHandleComponent();
	SetupInputComponent();

}

void UGrabbatore::SetupInputComponent()
{
	InputComp = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComp)
	{
		UE_LOG(LogTemp, Display, TEXT("Got InputComponent"));
		//Binding delle azioni 
		InputComp->BindAction("Grab", IE_Pressed, this, &UGrabbatore::Grab);
		InputComp->BindAction("Grab", IE_Released, this, &UGrabbatore::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error InputComponent not found"));
	}
}

void UGrabbatore::FindPhysicsHandleComponent()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (!PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("No PhysicsHandle"));
	}
}


// Called every frame
void UGrabbatore::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FVector PlayerViewPortPosition;
	FRotator PlayerViewPortRotator;

	//definendo il MACRO OUT con #define, il metodo GetPlayerViewport è void ma get, funziona quindi così:
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(

		OUT PlayerViewPortPosition,
		OUT PlayerViewPortRotator

	);
	// Log per aggiornare in ticking la position e rotation del Punto Vista del Giocatore.
	/*UE_LOG(LogTemp, Warning, TEXT("Posizione: %s Rotazione: %s"),  *PlayerViewPortPosition.ToString(), *PlayerViewPortRotator.ToString());*/


	FVector LineTraceEnd = PlayerViewPortPosition + PlayerViewPortRotator.Vector() * Reach;

	if (PhysicsHandle->GrabbedComponent) 
	{
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}

	
}

void UGrabbatore::Grab()
{
	UE_LOG(LogTemp, Log, TEXT("Grab key pressed"));
	FHitResult Hit = GetFirstTraceBody();
	auto ComponentGrabbato = Hit.GetComponent();
	auto ActorHit = Hit.GetActor();

	if (ActorHit)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			ComponentGrabbato,
			NAME_None,
			ComponentGrabbato->GetOwner()->GetActorLocation(),
			ComponentGrabbato->GetOwner()->GetActorRotation()
		);
	}
	else{ UE_LOG(LogTemp, Error, TEXT("Grabbing Error 104")); }
}

void UGrabbatore::Release()
{
	UE_LOG(LogTemp, Log, TEXT("Grab key released"));
	PhysicsHandle->ReleaseComponent();
}

FHitResult UGrabbatore::GetFirstTraceBody() const
{
	FVector PlayerViewPortPosition;
	FRotator PlayerViewPortRotator;

	//definendo il MACRO OUT con #define, il metodo GetPlayerViewport è void ma get, funziona quindi così:
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(

		OUT PlayerViewPortPosition,
		OUT PlayerViewPortRotator

	);
	// Log per aggiornare in ticking la position e rotation del Punto Vista del Giocatore.
	/*UE_LOG(LogTemp, Warning, TEXT("Posizione: %s Rotazione: %s"),  *PlayerViewPortPosition.ToString(), *PlayerViewPortRotator.ToString());*/


	FVector LineTraceEnd = PlayerViewPortPosition + PlayerViewPortRotator.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPortPosition,
		LineTraceEnd,
		ColorLineDD,
		false,
		0.f,
		0.f,
		10.0);
	
	FHitResult HitOut;


	GetWorld()->LineTraceSingleByObjectType(
		OUT HitOut,
		PlayerViewPortPosition,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
	);

	AActor* HittedActor = HitOut.GetActor();

	if (HittedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor colpito: %s"), *(HittedActor->GetName()));
	}
	return HitOut;
}

