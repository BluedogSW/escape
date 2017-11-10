// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabbatore.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"


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

	// ...
	
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

	DrawDebugLine(
		GetWorld(), 
		PlayerViewPortPosition, 
		LineTraceEnd,
		ColorLineDD,
		false, 
		0.f, 
		0.f,
		5.0);

}

