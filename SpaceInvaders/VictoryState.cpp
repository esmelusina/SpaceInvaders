#include "victorystate.h"
#include "declconst.h"
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>

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

	float x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, "You Lose!", x, y, s, s);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press R to Return to Main", x, y, s, s, color);

	/////////////////////////////////////////////////////////////////////////
	std::fstream fin("scores.dat", std::ios_base::in);
	std::vector<unsigned> scores;
	unsigned highScore = 0;
	while (!fin.eof())	// EOF tells us when we reach the end of the file
	{
		unsigned t;
		fin >> t;				// EOF doesn't get flagged until we try to input something something

		if (t > highScore) highScore = t;
		scores.push_back(t);
	}
	scores.pop_back();	// So we have to throw away the last value!
 	fin.close();

	
	y = WINDOW_HEIGHT / 2;	// Draw the latest score at the center of the screen

	s = 24 + sinf(sfw::getTime() * 6) * 2; // sin function w/time lets me modulate the size of my characters	
	std::string score = "New high score!";
	if(scores[scores.size() - 1] == highScore)
		drawFontCentered(spriteFont, score.c_str(), //last score is most recent
			x + sinf(sfw::getTime() * 2) * 9,
			y + cosf(sfw::getTime() * 2) * 9 + 64,   // x+cos and y+sin = circular!
			s, s, RED);
	
	s = 24 + sinf(sfw::getTime()*5)*3; // sin function w/time lets me modulate the size of my characters	
	score = "High Score: " + std::to_string(highScore);
	drawFontCentered(spriteFont, score.c_str(), //last score is most recent
		x + sinf(sfw::getTime() * 4) * 7,
		y + cosf(sfw::getTime() * 4) * 7 + 32,   // x+cos and y+sin = circular!
		s, s, RED);

	s = 24 + sinf(sfw::getTime() * 4) * 4; // sin function w/time lets me modulate the size of my characters
	score = "Your Score: " + std::to_string(scores[scores.size() - 1]);
	drawFontCentered(spriteFont, score.c_str(), //last score is most recent
								 x + sinf(sfw::getTime() * 3) * 8,	
								 y + cosf(sfw::getTime() * 3) * 8,   // x+cos and y+sin = circular!
								 s, s,CYAN);

	s = 18;
	y = WINDOW_HEIGHT / 2 - scores.size() * s;	// Figure out where we start drawing scores.
	for (int i = scores.size() - 2; i >= 0 && scores.size()-i < 12; --i)
	{
		drawFontCentered(spriteFont, std::to_string(scores[i]).c_str(),
																x, y+18*i, s, s);
	}
}