#include "UIPause.h"
#include "Game.h"
#include "graphic.h"
#include "input.h"

UIPause::UIPause(Game* game)
	:UIScreen(game)
{
	mTitle = "Pause";
	mGame->SetState(Game::EPaused);
}

void UIPause::ProcessInput()
{
	if (isTrigger(KEY_SPACE))
	{
		CloseMe();
		mGame->SetState(Game::EGameplay);
	}
}

void UIPause::Draw()
{
	fill(0, 0, 0, 128);
	rect(width / 2, height / 2, width, height);

	UIScreen::Draw();
}
