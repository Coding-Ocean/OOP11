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
	// Game��UIStack�ɒǉ�
	mGame->PushUI(this);
	// �{�^���摜
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
	// �{�^��������Ȃ�
	if (!mButtons.empty())
	{
		// �}�E�X�̈ʒu���擾
		VECTOR2 mousePos(mouseX, mouseY);
		// �S�{�^���̃`�F�b�N
		for (auto b : mButtons)
		{
			// ���[���I�[�o�[���Ă�����n�C���C�g
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

	// �{�^���\���i������������j
	for (auto b : mButtons)
	{
		// �{�^���摜�\��
		int buttonImg = b->GetHighlighted() ? mButtonOnImg : mButtonOffImg;
		VECTOR2 pos = b->GetPosition();
		image(buttonImg, pos.x, pos.y);
		// �{�^�������\��
		pos.x -= b->GetName().length() * mTextSize / 4;//���p�����̂ݑΉ�
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

	// ���ɒǉ������{�^���̈ʒu���v�Z���Ă����i�摜�̍����{�Ԋu�j
	mNextButtonPos.y += dims.y + 20.0f;
}
