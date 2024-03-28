// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PFHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE5_JHW_PF_API APFHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	APFHUD();
	~APFHUD();

protected:

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

public:
	
	class UMainWidget* m_MainWidget;
};
