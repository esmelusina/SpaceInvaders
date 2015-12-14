#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "declconst.h"
#include <vector>
#include "Particle.h"
#include "BaseState.h"

class GameState : public BaseState
{
public:
	Player player;
	std::vector<Bullet>   bullets;
	std::vector<Enemy>    enemies;
	std::vector<Particle> particles;

	float spawnRate;
	float spawnDelay;
	unsigned score;

	GameState() :
		player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM),
		spawnDelay(0), spawnRate(1.8f), score(0)
	{
		GameObject::gs = this;
	}

	void reset()
	{
		score = 0;
		spawnDelay = 0;
		spawnRate = 1.8f;
		player = Player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM);
		bullets.clear();
		enemies.clear();
		particles.clear();
	}

	void update();
	void draw();
	void spawnBullet(float x, float y, float a_speed);
	void spawnEnemy(float x, float y);
	void spawnParticle(float x, float y,
		float a_startRadius, float a_endRadius,
		float a_lifetime, unsigned a_color);
};