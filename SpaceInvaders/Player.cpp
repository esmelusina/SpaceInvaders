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
		gs->spawnBullet(position.x, position.y+radius, 300);
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
		o.setInactive();
		switch (health)
		{
		case 2: color  = MAGENTA;  break;
		case 1: color  = ORANGE; break;
		case 0: setInactive();  break;
		}
	}
}

void Player::onInactive()
{
	gs->spawnParticle(position.x, position.y, 0, 600, .2f, RED);
	gs->spawnParticle(position.x, position.y, 3, 15, .4f, YELLOW);
	gs->spawnParticle(position.x, position.y, 12, 0, .3f, MAGENTA);
	gs->spawnParticle(position.x, position.y, 15, 24, .6f, GREEN);
}