// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "../../Global/Enum/AnimState.h"
#include "AnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class UE5_JHW_PF_API UAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	//Override
	void NativeBeginPlay() override;
	void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	/*This Function(Delegate) requires Conditions that
		1. Event Binding (AddDynamic) at NativeBeginPlay
	*/
	UFUNCTION()
	virtual void MontageBlendOut(UAnimMontage* _Anim, bool _Inter);

protected:

	TMap<AnimState, UAnimMontage* > m_AnimInst_All_Animations;

	UAnimMontage* m_CurrentMontage = nullptr;

	AnimState m_AnimState;

	float m_AnimSpeed = 1.0f;

};
