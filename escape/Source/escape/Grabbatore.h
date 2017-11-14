// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabbatore.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UGrabbatore : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabbatore();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Setup Input Component	
	void SetupInputComponent();

	// Setup Physics Handle Component
	void FindPhysicsHandleComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComp = nullptr;

	float Reach = 100.f;

	UPROPERTY(EditAnywhere)
		FColor ColorLineDD;
	
	void Grab();
	void Release();

	FHitResult GetFirstTraceBody() const;
};
