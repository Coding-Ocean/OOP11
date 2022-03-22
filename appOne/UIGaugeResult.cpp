#include "UIGaugeResult.h"
#include "graphic.h"
#include "Game.h"
#include "Ship.h"
#include "UIQuit.h"

UIGaugeResult::UIGaugeResult(Game* game)
	:UIScreen(game)
	, mPos(300, height - 30)
{
	mHp = (float)mGame->GetShip()->GetHP();
	mWidth = 10;
	mPos.x = (width - mHp * mWidth) / 2;
	mSetFlag = false;
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

	bool ufosEmpty = mGame->GetUfos().empty();
	if ((ship == nullptr || ufosEmpty)&&mSetFlag==false)
	{
		if (ship == nullptr) {
			mTitle = "GameOver";
			mTitleColor = COLOR(255, 0, 0);
		}
		else {
			mTitle = "GameClear";
			mTitleColor = COLOR(255, 255, 0);
		}

		mSetFlag = true;
		mTitlePos.y = height / 2;
		mTextSize = 200;
		
		AddButton("Restart",
			[this]() {
				mGame->SetState(Game::ERestart);
			}
		);
		AddButton("Quit",
			[this]() {
				new UIQuit(mGame);
			}
		);
	}

	//デフォルト設定に戻す
	rectMode(CENTER);
	UIScreen::Draw();

	printSize(25);
	fill(200);
	print("レーザー発射:マウス左ボタン");
	print("一時停止　　:スペースキー");
}
