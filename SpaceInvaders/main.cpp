#include "sfwdraw.h"
#include "declconst.h"

#include "GameState.h"
#include "SplashState.h"
#include "PauseState.h"
#include "VictoryState.h"

// definition
unsigned spritePlayer;
unsigned spriteEnemy;
unsigned spriteParticle;
unsigned spriteSpace;
unsigned spriteFont;

STATE applicationState = SPLASH;

int main()
{
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "Space Invaders!");

	//initialization
	spriteEnemy    = sfw::loadTextureMap("./textures/enemy.png");
	spriteParticle = sfw::loadTextureMap("./textures/particle.png");
	spritePlayer   = sfw::loadTextureMap("./textures/player.png");
	spriteSpace    = sfw::loadTextureMap("./textures/space.jpg");
	spriteFont     = sfw::loadTextureMap("./textures/fontmap.png",16,16);
	// github.com/esmelusina/sfw-AIE-Framework/blob/master/res/fontmap.png
	GameState	 gs;
	SplashState  ss;
	PauseState	 ps;
	VictoryState vs;
	// add a new state...
	while (sfw::stepContext() && applicationState != QUIT)
	{
		switch (applicationState)
		{
		case SPLASH:
			ss.update();
			ss.draw();
			break;
		case PLAY:
			gs.reset();
			applicationState = GAME;
		case GAME:
			gs.update();
			gs.draw();
			break;
		case PAUSE:
			gs.draw();
			ps.update();
			ps.draw();
			break;
		case VICTORY:
			gs.update();
			gs.draw();
			vs.update();
			vs.draw();
			break;
		}

	}

	sfw::termContext();	
	return 0;
}

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, float w, float h, unsigned color)
{
	x -= strlen(text) * w / 2;
	sfw::drawString(spriteFont, text, x, y, w, h, 0, 0, color);
}


