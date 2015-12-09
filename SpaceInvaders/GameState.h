#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "declconst.h"
#include <vector>

class GameState
{
public:
	Player player;
	std::vector<Bullet> bullets;
	std::vector<Enemy> enemies;
	float spawnRate;
	float spawnDelay;
	unsigned score;

	GameState() :
		player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM),
		spawnDelay(0), spawnRate(1.8f), score(0)
	{
		GameObject::gs = this;

		spawnEnemy(player.position.x, BOUNDS_TOP);
	}

	void update();
	void draw();
	void spawnBullet(float x, float y, float a_speed);
	void spawnEnemy(float x, float y);
};