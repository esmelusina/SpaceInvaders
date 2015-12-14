#pragma once
#include "declconst.h"
#include "BaseState.h"
#include "sfwdraw.h"

class PauseState : public BaseState
{
public:
	unsigned color, baseColor;
	PauseState()
		: color(CYAN), baseColor(color - 0xff)
	{

	}

	void update();
	void draw();
};