#pragma once
#include<functional>
#include"VECTOR2.h"
//UIScreen���Ŏg�p����g�⏕�I�ȃN���X�h�i�Ɨ��g�p�ł��Ȃ��j
class Button
{
public:
	Button(const char* name,
		std::function<void()> onClick,
		const VECTOR2& pos, const VECTOR2& dims);
	~Button();

	// �{�^�����̃Z�b�g
	void SetName(const char* name);

	// Getters/setters
	const std::string& GetName() { return mName; }
	const VECTOR2& GetPosition() const { return mPosition; }
	void SetHighlighted(bool sel) { mHighlighted = sel; }
	bool GetHighlighted() const { return mHighlighted; }

	// �}�E�X�|�C���^�����̃{�^�����ɂ��邩
	bool ContainsPoint(const VECTOR2& pt) const;
	// �N���b�N���ꂽ�Ƃ��ɌĂяo�����֐�
	void OnClick();
private:
	std::string mName;
	VECTOR2 mPosition;
	VECTOR2 mDimensions;//�{�^���̐��@
	bool mHighlighted;
	std::function<void()> mOnClick;
};
