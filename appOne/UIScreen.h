#pragma once
#include<string>
#include"COLOR.h"
#include"VECTOR2.h"
//���[�U�[�C���^�[�t�F�C�X���N���X
class UIScreen
{
public:
	UIScreen(class Game* game);
	virtual ~UIScreen() {};
	// �h���N���X�ŃI�[�o�[���C�h�\
	virtual void ProcessInput() {};
	virtual void Update(){};
	virtual void Draw();
	// UI�X�e�[�g�B�A�N�e�B�u���A���邩
	enum UIState
	{
		EActive,
		EClosing
	};
	// UI�X�e�[�g��Closing�ɐݒ�
	void CloseMe();
	// UI�X�e�[�g���擾
	UIState GetState() const { return mState; }
	// UI�^�C�g����ݒ�
	void SetTitle(const char* text) { mTitle = text; }
protected:
	class Game* mGame;

	//�^�C�g�������Ƃ��̑���
	std::string mTitle;
	COLOR mTitleColor;
	VECTOR2 mTitlePos;
	float mTextSize;

	// �X�e�[�g
	UIState mState;
};

