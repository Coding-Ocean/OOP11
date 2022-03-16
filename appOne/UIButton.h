#pragma once
#include<functional>
#include"VECTOR2.h"
//UIScreen内で使用する“補助的なクラス”（独立使用できない）
class Button
{
public:
	Button(const char* name,
		std::function<void()> onClick,
		const VECTOR2& pos, const VECTOR2& dims);
	~Button();

	// ボタン名のセット
	void SetName(const char* name);

	// Getters/setters
	const std::string& GetName() { return mName; }
	const VECTOR2& GetPosition() const { return mPosition; }
	void SetHighlighted(bool sel) { mHighlighted = sel; }
	bool GetHighlighted() const { return mHighlighted; }

	// マウスポインタがこのボタン内にあるか
	bool ContainsPoint(const VECTOR2& pt) const;
	// クリックされたときに呼び出される関数
	void OnClick();
private:
	std::string mName;
	VECTOR2 mPosition;
	VECTOR2 mDimensions;//ボタンの寸法
	bool mHighlighted;
	std::function<void()> mOnClick;
};
