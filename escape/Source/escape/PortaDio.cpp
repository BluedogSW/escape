// Fill out your copyright notice in the Description page of Project Settings.

#include "PortaDio.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPortaDio::UPortaDio()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPortaDio::BeginPlay()
{
	Super::BeginPlay();


	WhoTriggerPlate = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UPortaDio::ApriPorta()
{
	AActor* Owner = GetOwner();

	FRotator newRotation = FRotator(0.0f, OpenAngle, 0.0f);

	Owner->SetActorRotation(newRotation);
}

void UPortaDio::ChiudiPorta()
{
	AActor* Owner = GetOwner();

	Owner->SetActorRotation(FRotator(0.0f, 179.999756f, 0.0f));
}


// Called every frame
void UPortaDio::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (LastraPressure->IsOverlappingActor(WhoTriggerPlate)) {

		ApriPorta();
		MomentoAperturaPorta = GetWorld()->GetTimeSeconds();
	}

	if(GetWorld()->GetTimeSeconds() - MomentoAperturaPorta > TempoPortaAperta){
		ChiudiPorta();
	}

}

