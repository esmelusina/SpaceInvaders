#include "GameState.h"
#include <string>
void GameState::update()
{
	////////////////////////////////////////////////////
	//// Spawning Enemies
	// the accumulator 'accumulates' time
	spawnDelay += sfw::getDeltaTime();
		  // How do we keep track of time?

	if (spawnDelay > spawnRate) // what is the condition?
	{
		spawnDelay = 0;
		spawnRate *= .98f;
		// How do we reset our timer?
		spawnEnemy(randRange(BOUNDS_LEFT,BOUNDS_RIGHT),
										BOUNDS_TOP+40);
	}
	
	//////////////////////////////////////////////////////
	//////// Updating
	player.update();
	for (int i = 0; i < bullets.size(); ++i)
		bullets[i].update();
	for (int i = 0; i < enemies.size(); ++i)
		enemies[i].update();
	for (int i = 0; i < particles.size(); ++i)
		particles[i].update();


	///////////////////////////////////////////////////
	//////////// Collision
	// Player vs Bullets
	for (int i = 0; i < bullets.size(); ++i)
		collides(player, bullets[i]);
	for (int i = 0; i < enemies.size(); ++i)
		collides(player, enemies[i]);


	// For every bullet and every enemy,
	for (int i = 0; i < enemies.size(); ++i) // for each enemy,
		for (int j = 0; j < bullets.size(); ++j) // for every bullet
			collides(enemies[i], bullets[j]);

	for (int i = 0; i+1 < bullets.size(); ++i)	// for each bullet,
		for (int j = i+1; j < bullets.size(); ++j) // for every bullet after
			collides(bullets[i], bullets[j]);
}


void GameState::draw()
{
	sfw::drawTexture(spriteSpace,WINDOW_WIDTH/2,WINDOW_HEIGHT/2,
								   WINDOW_WIDTH, WINDOW_HEIGHT);

	player.draw();
	for (int i = 0; i < bullets.size(); ++i)
		bullets[i].draw();
	for (int i = 0; i < enemies.size(); ++i)
		enemies[i].draw();
	for (int i = 0; i < particles.size(); ++i)
		particles[i].draw();

	
	sfw::drawString(spriteFont, std::to_string(score).c_str(),
										0, WINDOW_HEIGHT, 20, 20);
}

void GameState::spawnEnemy(float x, float y)
{
	Enemy b(x, y);

	for (int i = 0; i < enemies.size(); ++i)
		if (!enemies[i].active)
		{
			enemies[i] = b;
			return;
		}
	enemies.push_back(b);
}

void GameState::spawnParticle(float x, float y, float a_startRadius, float a_endRadius, float a_lifetime, unsigned a_color)
{
	Particle b(x, y,a_startRadius,a_endRadius,a_lifetime,a_color);

	for (int i = 0; i < particles.size(); ++i)
		if (!particles[i].active)
		{
			particles[i] = b;
			return;
		}
	particles.push_back(b);
}

void GameState::spawnBullet(float x, float y, float a_speed)
{
	Bullet b(x, y, a_speed);

	for (int i = 0; i < bullets.size(); ++i)
		if (!bullets[i].active)
		{
			bullets[i] = b;
			return;
		}
	bullets.push_back(b);
}