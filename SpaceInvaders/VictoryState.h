#pragma once
#include "declconst.h"
#include "BaseState.h"
#include "sfwdraw.h"

class VictoryState : public BaseState
{
public:
	unsigned color, baseColor;
	VictoryState()
		: color(CYAN), baseColor(color - 0xff)
	{
	}

	void update();
	void draw();
};