#include "SplashState.h"
#include <cstring>
#include <cmath>

void SplashState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey(KEY_ENTER))
		applicationState = PLAY;
	if (sfw::getKey(KEY_ESCAPE))
		applicationState = QUIT;
}

void SplashState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT);

	unsigned x, y, s;

	s = 32;
	x = (WINDOW_WIDTH)/2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, TITLE, x, y, s, s);

	s = 20;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press Enter to Start", x, y, s, s, color);
	drawFontCentered(spriteFont, "Press Escape to Quit", x, y-20, s, s, color);

	s = 18;
	y = WINDOW_HEIGHT * 8 / 16;
	drawFontCentered(spriteFont, "Esmeralda Salamone", x, y, s, s);
	drawFontCentered(spriteFont, "esmelusina@gmail.com", x, y-19, 16, 16, MAGENTA);
}