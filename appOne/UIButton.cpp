#include "UIButton.h"
Button::Button(const char* name, std::function<void()> onClick,
	const VECTOR2& pos, const VECTOR2& dims)
	: mName(name)
	, mOnClick(onClick)
	, mPosition(pos)
	, mDimensions(dims)
	, mHighlighted(false)
{
}

Button::~Button()
{
}

void Button::SetName(const char* name)
{
	mName = name;
}

bool Button::ContainsPoint(const VECTOR2& pt) const
{
	bool no =
		pt.x < (mPosition.x - mDimensions.x / 2.0f) ||
		pt.x >(mPosition.x + mDimensions.x / 2.0f) ||
		pt.y < (mPosition.y - mDimensions.y / 2.0f) ||
		pt.y >(mPosition.y + mDimensions.y / 2.0f);
	return !no;
}

void Button::OnClick()
{
	// Call attached handler, if it exists
	if (mOnClick)
	{
		mOnClick();
	}
}
