#pragma once
#include<string>
#include"COLOR.h"
#include"VECTOR2.h"
//ユーザーインターフェイス基底クラス
class UIScreen
{
public:
	UIScreen(class Game* game);
	virtual ~UIScreen() {};
	// 派生クラスでオーバーライド可能
	virtual void ProcessInput() {};
	virtual void Update(){};
	virtual void Draw();
	// UIステート。アクティブか、閉じるか
	enum UIState
	{
		EActive,
		EClosing
	};
	// UIステートをClosingに設定
	void CloseMe();
	// UIステートを取得
	UIState GetState() const { return mState; }
	// UIタイトルを設定
	void SetTitle(const char* text) { mTitle = text; }
protected:
	class Game* mGame;

	//タイトル文字とその属性
	std::string mTitle;
	COLOR mTitleColor;
	VECTOR2 mTitlePos;
	float mTextSize;

	// ステート
	UIState mState;
};

