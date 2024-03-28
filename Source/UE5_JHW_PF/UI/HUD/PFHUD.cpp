// Fill out your copyright notice in the Description page of Project Settings.


#include "PFHUD.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "../../UI/MainWidget/MainWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"


APFHUD::APFHUD()
{
	

	

	
}

APFHUD::~APFHUD()
{
}

void APFHUD::BeginPlay()
{
	Super::BeginPlay();

	//Create MainWidget
	{
		FSoftClassPath WBP_MainWidget_Path(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_MainWidget.WBP_MainWidget_C'"));
		TSubclassOf<UUserWidget> MainWidgetClass = WBP_MainWidget_Path.TryLoadClass<UUserWidget>();

		UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);
		m_MainWidget = Cast<UMainWidget>(Widget);
		m_MainWidget->AddToViewport();
	}

	//Params(APlayerController* _PlayerController, UWidget* _WidgetToFocus, EMouseLockMode InMouseLockMode, bool bHideCursorDuringCapture, const bool bFlushInput /* = false */)
	//(PlayerController, MainWidget, DoNotLock, False, False)

	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(UGameplayStatics::GetPlayerController(GetWorld(), 0), m_MainWidget, EMouseLockMode::DoNotLock, false);
}

void APFHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
