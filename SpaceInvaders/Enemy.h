#pragma once
#include "gameObject.h"

//Player inherits from gameobject
class Enemy : public GameObject
{
public:
	float delay, rof;
	Enemy(float x, float y)
		: GameObject(x, y, 34),
		delay(0), rof(1.2f)
	{
		color = RED;
		speed = 50;
		velocity.y = -speed;
	}

	void onCollision(GameObject &o);

	void onUpdate();
};