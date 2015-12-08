#include "GameState.h"

void GameState::update()
{
	player.update();
}


void GameState::draw()
{
	player.draw();
}