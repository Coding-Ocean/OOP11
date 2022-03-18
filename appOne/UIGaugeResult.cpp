#include "UIGaugeResult.h"
#include "graphic.h"
#include "Game.h"
#include "Ship.h"

UIGaugeResult::UIGaugeResult(Game* game)
	:UIScreen(game)
	, mPos(300, height - 30)
{
	mHp = (float)mGame->GetShip()->GetHP();
	mWidth = 10;
	mPos.x = (width - mHp * mWidth) / 2;
}

void UIGaugeResult::Draw()
{
	//HP Bar背景
	noStroke();
	fill(120, 120, 120, 120);
	rectMode(CORNER);
	rect(mPos.x, mPos.y, mHp * mWidth, 20);

	auto ship = mGame->GetShip();
	if (ship)
	{
		//HP Bar
		int hp = ship->GetHP();
		if (hp / mHp > 0.1f)
			fill(0, 255, 0, 128);
		else
			fill(255, 0, 0, 128);
		rect(mPos.x, mPos.y, hp * mWidth, 20);
	}
	else
	{
		//GameOver Text
		textSize(200);
		fill(255, 0, 0);
		text("GameOver", (width-800)/2, height / 2);
	}
	if (mGame->GetUfos().empty())
	{
		//GameClear Text
		textSize(200);
		fill(255, 255, 0);
		text("GameClear", (width - 900) / 2, height / 2);
	}

	//デフォルト設定に戻す
	rectMode(CENTER);
}
