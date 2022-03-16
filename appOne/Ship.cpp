#include "Ship.h"
#include "Game.h"
#include "graphic.h"
#include "window.h"
#include "input.h"
#include "InputComponent.h"
#include "AnimSpriteComponent.h"
#include "RectComponent.h"
#include "ShipLaser.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mTimer(0.0f)
	,mInterval(0.1f)
{
    SetPosition(VECTOR2(width / 2, height-100));
	SetRotation(-1.57f);
    SetScale(1.5f);

	//このコンポーネントはMoveComponentを継承している
	auto ic = new InputComponent(this);
	ic->SetMoveSpeed(300);

    mAnimSprite = new AnimSpriteComponent(this);
    mAnimSprite->SetInterval(0.016f * 3);
    mAnimSprite->AddImage(loadImage("Assets\\Ship01.png"));
    mAnimSprite->AddImage(loadImage("Assets\\Ship02.png"));
    mAnimSprite->AddImage(loadImage("Assets\\Ship03.png"));
    mAnimSprite->AddImage(loadImage("Assets\\Ship04.png"));

	mRect = new RectComponent(this, 150);
	mRect->SetHalfW(10);
	mRect->SetHalfH(30);

	mHP = 20;

	GetGame()->SetShip(this);
}

Ship::~Ship()
{
	GetGame()->SetShip(nullptr);
}

void Ship::ActorInput()
{
	if (isPress(MOUSE_LBUTTON))
	{
		mTimer += delta;
		if (mTimer >= mInterval)
		{
			mTimer -= mInterval;
			auto laser = new ShipLaser(GetGame());
			//発射位置をずらす
			VECTOR2 pos = GetPosition()+VECTOR2(0,-60);
			laser->SetPosition(pos);
			laser->SetDirection(VECTOR2(0,-1));
			laser->SetRotation(-1.57f);
		}
	}
	else
	{
		mTimer = mInterval;
	}
}

void Ship::Damage()
{
	if (--mHP <= 0)
	{
		SetState(EDead);
	}
	mAnimSprite->StartFlash(0.032f, COLOR(255, 0, 255));
}
