#include "sfwdraw.h"
#include "GameState.h"
#include "declconst.h"

unsigned spritePlayer;
unsigned spriteEnemy;
unsigned spriteParticle;
unsigned spriteSpace;
unsigned spriteFont;

int main()
{
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "Space Invaders!");

	spriteEnemy    = sfw::loadTextureMap("./textures/enemy.png");
	spriteParticle = sfw::loadTextureMap("./textures/particle.png");
	spritePlayer   = sfw::loadTextureMap("./textures/player.png");
	spriteSpace    = sfw::loadTextureMap("./textures/space.jpg");
	spriteFont     = sfw::loadTextureMap("./textures/fontmap.png",16,16);
	// github.com/esmelusina/sfw-AIE-Framework/blob/master/res/fontmap.png
	GameState gs;

	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		gs.update();
		gs.draw();
	}

	sfw::termContext();	
	return 0;
}