#pragma once
#include "UIScreen.h"
class UIGaugeResult :
    public UIScreen
{
public:
    UIGaugeResult(class Game* game);
    void Draw() override;
private:
    VECTOR2 mPos;
    float mHp;
    float mWidth;
};

