#include "UIPause.h"
#include "Game.h"
#include "graphic.h"
#include "input.h"

UIPause::UIPause(Game* game)
	:UIScreen(game)
{
	mGame->SetState(Game::EPaused);
	
	mTitle = "Pause";

	AddButton("Resume",
		[this]() {
			CloseMe();
		}
	);

	AddButton("Quit",
		[this]() {
			mGame->SetState(Game::EQuit);
		}
	);
}

UIPause::~UIPause()
{
	mGame->SetState(Game::EGameplay);
}

void UIPause::ProcessInput()
{
	UIScreen::ProcessInput();

	if (isTrigger(KEY_SPACE))
	{
		CloseMe();
	}
}

void UIPause::Draw()
{
	fill(0, 0, 0, 128);
	rect(width / 2, height / 2, width, height);

	UIScreen::Draw();
}
