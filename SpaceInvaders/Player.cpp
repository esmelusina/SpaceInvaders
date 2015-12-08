#include "Player.h"
#include "sfwdraw.h"
#include "declconst.h"

void Player::onUpdate()
{
	velocity = {0,0};

	if(sfw::getKey('A'))
	{
		velocity.x = -speed;
	}
	if (sfw::getKey('D'))
	{
		velocity.x = speed;
	}

	if (position.x - radius < BOUNDS_LEFT)
	{
		position.x = BOUNDS_LEFT + radius;
	}
	if (position.x + radius > BOUNDS_RIGHT)
	{
		position.x = BOUNDS_RIGHT - radius;
	}
}