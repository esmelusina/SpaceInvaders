#include "Enemy.h"
#include "GameState.h"
#include <iostream>
void Enemy::onUpdate()
{
	delay += sfw::getDeltaTime();
	if (delay > rof)
	{
		delay = 0;
		gs->spawnBullet(position.x, position.y, -300);
	}

	if (position.y < BOUNDS_BOTTOM)
		active = false;
}

void Enemy::onCollision(GameObject &o)
{
	if (o.velocity.y > 0)
	{
		active = false;
		o.active = false;
		gs->score++;
		std::cout << gs->score << std::endl;
	}
}