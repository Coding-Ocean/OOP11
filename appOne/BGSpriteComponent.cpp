#include "BGSpriteComponent.h"
#include "Actor.h"
#include "window.h"

BGSpriteComponent::BGSpriteComponent(Actor* owner, int drawOrder)
	: SpriteComponent(owner,drawOrder)
	, mScrollSpeed(0.0f)
{
}

BGSpriteComponent::~BGSpriteComponent()
{
}

void BGSpriteComponent::SetImage(int img)
{
	Back back;
	back.img = img;
	back.pos.x = width / 2;
	back.pos.y = height / 2 + height * mBack.size();
	mBack.emplace_back(back);
}

void BGSpriteComponent::Update()
{
	for (auto& back : mBack)
	{
		back.pos.y += mScrollSpeed * delta;
		if (back.pos.y > height + height / 2) {
			back.pos.y += -height * 2;
		}
	}
}

void BGSpriteComponent::Draw()
{
	for (auto& back : mBack)
	{
		mOwner->SetPosition(back.pos);
		SpriteComponent::SetImage(back.img);
		SpriteComponent::Draw();
	}
}
