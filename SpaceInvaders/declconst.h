#pragma once

#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 800

#define BOUNDS_TOP	  WINDOW_HEIGHT-60
#define BOUNDS_BOTTOM  60
#define BOUNDS_LEFT    80
#define BOUNDS_RIGHT  WINDOW_WIDTH-80

#define ORANGE 0xffA500ff

#define TITLE "Spacey Invaders"

class GameState;

//declaration
extern unsigned spritePlayer;
extern unsigned spriteEnemy;
extern unsigned spriteParticle;
extern unsigned spriteSpace;
extern unsigned spriteFont;

enum STATE {SPLASH, PLAY, GAME, PAUSE, VICTORY, QUIT, HELP};

extern STATE applicationState;

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color = 0xffffffff);

