#include "UIScreen.h"
#include "graphic.h"
#include "input.h"
#include "Game.h"

UIScreen::UIScreen(Game* game)
	:mGame(game)
	, mTextSize(40)
	, mTitlePos(width / 2, 100.0f)
	, mState(EActive)
{
	// Game��UIStack�ɒǉ�
	mGame->PushUI(this);
}

void UIScreen::Draw()
{
	// �^�C�g���\���i������������j
	textSize(mTextSize);
	fill(mTitleColor);
	if (mTitle.c_str())
	{
		text(mTitle.c_str(),
			mTitlePos.x - mTitle.length() * mTextSize / 4,//���p�����̂ݑΉ�
			mTitlePos.y + mTextSize / 2
		);
	}
}

void UIScreen::CloseMe()
{
	mState = EClosing;
}

