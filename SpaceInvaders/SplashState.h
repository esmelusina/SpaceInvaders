#pragma once
#include "declconst.h"
#include "BaseState.h"
#include "sfwdraw.h"

class SplashState : public BaseState
{
public:
	unsigned color, baseColor;
	SplashState()
		: color(CYAN), baseColor(color-0xff)
	{

	}

	void update();
	void draw();
};