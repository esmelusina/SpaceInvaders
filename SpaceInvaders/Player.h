#pragma once
#include "gameObject.h"

//Player inherits from gameobject
class Player : public GameObject
{
public:
	Player(float x, float y)
			: GameObject(x,y,35)
	{
		speed = 120; //add speed to gameObject
	}

	void onUpdate();
};