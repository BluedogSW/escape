// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"

#include "PortaDio.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UPortaDio : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPortaDio();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void ApriPorta();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
		
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* LastraPressure;

		AActor* WhoTriggerPlate;
	
};
