#include "victorystate.h"
#include "declconst.h"
#include <cstring>
#include <cmath>

void VictoryState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey('R'))
		applicationState = SPLASH;
}

void VictoryState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0, true, 0, 0x88888888);

	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, "You Lose!", x, y, s, s);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press R to Return to Main", x, y, s, s, color);
}