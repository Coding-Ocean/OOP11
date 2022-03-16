#include "UIScreen.h"
#include "graphic.h"
#include "input.h"
#include "Game.h"
#include "UIButton.h"

UIScreen::UIScreen(Game* game)
	:mGame(game)
	, mState(EActive)
	, mTextSize(40)
	, mTitlePos(width / 2, 100.0f)
	, mNextButtonPos(width / 2, 170.0f)
{
	// GameのUIStackに追加
	mGame->PushUI(this);
	// ボタン画像
	mButtonOnImg = loadImage("Assets/ButtonYellow.png");
	mButtonOffImg = loadImage("Assets/ButtonBlue.png");
}

UIScreen::~UIScreen()
{
	for (auto b : mButtons)
	{
		delete b;
	}
	mButtons.clear();
}

void UIScreen::ProcessInput()
{
	// ボタンがあるなら
	if (!mButtons.empty())
	{
		// マウスの位置を取得
		VECTOR2 mousePos(mouseX, mouseY);
		// 全ボタンのチェック
		for (auto b : mButtons)
		{
			// ロールオーバーしていたらハイライト
			if (b->ContainsPoint(mousePos))
			{
				b->SetHighlighted(true);
				if (isTrigger(MOUSE_LBUTTON))
				{
					b->OnClick();
				}
			}
			else
			{
				b->SetHighlighted(false);
			}
		}
	}
}
void UIScreen::Draw()
{
	// タイトル表示（もしあったら）
	textSize(mTextSize);
	fill(mTitleColor);
	if (mTitle.c_str())
	{
		text(mTitle.c_str(),
			mTitlePos.x - mTitle.length() * mTextSize / 4,//半角文字のみ対応
			mTitlePos.y + mTextSize / 2
		);
	}

	// ボタン表示（もしあったら）
	for (auto b : mButtons)
	{
		// ボタン画像表示
		int buttonImg = b->GetHighlighted() ? mButtonOnImg : mButtonOffImg;
		VECTOR2 pos = b->GetPosition();
		image(buttonImg, pos.x, pos.y);
		// ボタン文字表示
		pos.x -= b->GetName().length() * mTextSize / 4;//半角文字のみ対応
		pos.y += mTextSize / 2 - 2;
		text(b->GetName().c_str(), pos.x, pos.y);
	}
}

void UIScreen::CloseMe()
{
	mState = EClosing;
}

void UIScreen::AddButton(const std::string& name, std::function<void()> onClick)
{
	VECTOR2 dims = getTextureSize(mButtonOnImg);
	Button* b = new Button(name.c_str(), onClick, mNextButtonPos, dims);
	mButtons.emplace_back(b);

	// 次に追加されるボタンの位置を計算しておく（画像の高さ＋間隔）
	mNextButtonPos.y += dims.y + 20.0f;
}
