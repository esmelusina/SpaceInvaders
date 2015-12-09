#include "Player.h"
#include "sfwdraw.h"
#include "declconst.h"
#include "GameState.h"

void Player::onUpdate()
{
	velocity = {0,0};
	delay += sfw::getDeltaTime();

	if (sfw::getKey(' ') && delay > rof)
	{
		delay = 0;
		gs->spawnBullet(position.x, position.y, 300);
	}
	if(sfw::getKey('A'))
	{
		velocity.x = -speed;
	}
	if (sfw::getKey('D'))
	{
		velocity.x = speed;
	}

	// checking to see if we bump the edges of the screen
	if (position.x - radius < BOUNDS_LEFT)
	{
		position.x = BOUNDS_LEFT + radius;
	}
	if (position.x + radius > BOUNDS_RIGHT)
	{
		position.x = BOUNDS_RIGHT - radius;
	}
}

void Player::onCollision(GameObject &o)
{
	if (o.velocity.y < 0)
	{
		health--;
		o.active = false;
		radius /= 1.1f;
		switch (health)
		{
		case 2: color  = GREEN;  break;
		case 1: color  = YELLOW; break;
		case 0: active = false;  break;
		}
	}
}