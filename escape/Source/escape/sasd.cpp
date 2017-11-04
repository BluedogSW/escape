// Fill out your copyright notice in the Description page of Project Settings.

#include "sasd.h"


// Sets default values for this component's properties
Usasd::Usasd()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Usasd::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Usasd::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

