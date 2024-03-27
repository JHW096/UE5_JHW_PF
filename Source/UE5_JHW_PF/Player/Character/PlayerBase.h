// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../../Global/Enum/AnimState.h"
#include "PlayerBase.generated.h"

UCLASS()
class UE5_JHW_PF_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Getter, Setter of Member variable
public:

	void SetPlayerAnimState(AnimState _AnimState);
	AnimState GetAnimState() const;

	UAnimMontage* GetAnimMontageToAnimState(AnimState _AnimState) const;
	TMap<AnimState, UAnimMontage*> GetAllAnimations() const;

public:

	void GroundSpeedChecek();

protected:

	UPROPERTY(Category = "Animation_Value", EditAnywhere, BlueprintReadWrite)
	AnimState m_AnimState;

	UPROPERTY(Category = "Animation_Value", EditAnywhere, BlueprintReadWrite)
	TMap<AnimState, UAnimMontage*> m_Player_All_Animations;

private:

	class USpringArmComponent* m_SpringArmComponent;

	class UCameraComponent* m_TopDownCameraComponent;
};
