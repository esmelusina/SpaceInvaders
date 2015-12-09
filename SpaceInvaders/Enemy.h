#pragma once
#include "gameObject.h"

//Player inherits from gameobject
class Enemy : public GameObject
{
public:
	float delay, rof, trailDelay, trailRate;
	Enemy(float x, float y)
		: GameObject(x, y, 18),
		delay(0), rof(1.2f),
		trailDelay(0), trailRate(.2f)
	{
		sprite = spriteEnemy;
		//color = RED;
		speed = 50;
		velocity.y = -speed;
	}

	void onCollision(GameObject &o);

	void onUpdate();

	void onInactive();
};