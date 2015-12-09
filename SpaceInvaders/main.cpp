#include "sfwdraw.h"
#include "GameState.h"
#include "declconst.h"

int main()
{
	sfw::initContext(WINDOW_WIDTH,
					 WINDOW_HEIGHT,
				     "Space Invaders!");

	GameState gs;

	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		gs.update();
		gs.draw();
	}

	sfw::termContext();	
	return 0;
}