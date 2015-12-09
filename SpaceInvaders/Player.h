#pragma once
#include "gameObject.h"

//Player inherits from gameobject
class Player : public GameObject
{
public:
	float delay, rof;
	int health;

	Player(float x, float y)
			: GameObject(x,y,35),
			  delay(0), rof(.2f),
			health(3)
	{
		color = BLUE;
		speed = 120; //add speed to gameObject
	}

	void onUpdate();
	void onCollision(GameObject &o);
};