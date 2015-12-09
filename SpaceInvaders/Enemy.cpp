#include "Enemy.h"
#include "GameState.h"
#include <iostream>
void Enemy::onUpdate()
{
	trailDelay += sfw::getDeltaTime();
	if (trailDelay > trailRate)
	{
		trailDelay = 0;
		gs->spawnParticle(position.x + randRange(-1.f, 1.f), position.y + radius, 3, 0, 1, RED);
	}
	delay += sfw::getDeltaTime();
	if (delay > rof)
	{
		delay = randRange(-.5f,.5f);
		gs->spawnBullet(position.x, position.y-radius, -300);
		
	}

	if (position.y < BOUNDS_BOTTOM)
		active = false;
}

void Enemy::onCollision(GameObject &o)
{
	if (o.velocity.y > 0)
	{
		setInactive();
		o.setInactive();
		gs->score++;
		std::cout << gs->score << std::endl;
	}
}

void Enemy::onInactive()
{
	gs->spawnParticle(position.x, position.y, 0, 100, .1f, RED);
	gs->spawnParticle(position.x, position.y, 3, 15, .4f, YELLOW);
	gs->spawnParticle(position.x, position.y, 12, 0, .3f, MAGENTA);
}