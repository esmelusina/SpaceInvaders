#pragma once
#include "gameObject.h"
#include <cmath>
//Player inherits from gameobject
class Bullet : public GameObject
{
public:
	float lifespan;

	Bullet(float x, float y, float a_speed)
		: GameObject(x, y, 18), lifespan(3.f)
	{
		speed = a_speed;
		color = CYAN;
		velocity.y = speed;
	}

	void onUpdate()
	{
		lifespan -= sfw::getDeltaTime();
		position.x += sin(lifespan*10)*2;
		radius -= sfw::getDeltaTime()*10;
		if (lifespan < 0) active = false;
	}

};