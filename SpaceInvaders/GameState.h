#pragma once
#include "Player.h"
#include "declconst.h"

class GameState
{
public:
	Player player;

	GameState() :
		player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2,
									BOUNDS_BOTTOM)
	{ }

	void update();
	void draw();
};