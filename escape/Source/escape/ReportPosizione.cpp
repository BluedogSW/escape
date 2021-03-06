// Fill out your copyright notice in the Description page of Project Settings.

#include "ReportPosizione.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UReportPosizione::UReportPosizione()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReportPosizione::BeginPlay()
{
	Super::BeginPlay();
	
	FString NomeOggetto = GetOwner()->GetName();
	FVector PosOggetto = GetOwner()->GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("%s � nella posizione X: %.2f Y: %.2f Z: %.2f"), *NomeOggetto, PosOggetto.X, PosOggetto.Y, PosOggetto.Z);
	
}


// Called every frame
void UReportPosizione::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

