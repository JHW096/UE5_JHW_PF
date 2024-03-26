// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstanceBase.h"
#include "../Character/PlayerBase.h"

void UAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	//Get Animations from Owning Player
	m_AnimInst_All_Animations = Cast<APlayerBase>(GetOwningActor())->GetAllAnimations();
}

void UAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (m_AnimInst_All_Animations.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) AnimInstBase_Animations has nono of Animations"), __FUNCTION__, __LINE__);
		return;
	}
	
	m_AnimState = Cast<APlayerBase>(GetOwningActor())->GetAnimState();
	m_CurrentMontage = m_AnimInst_All_Animations[m_AnimState];

	if (m_CurrentMontage == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) AnimInstBase_CurrentMontage is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	if (!Montage_IsPlaying(m_CurrentMontage))
	{
		Montage_Play(m_CurrentMontage, m_AnimSpeed);
	}
}
