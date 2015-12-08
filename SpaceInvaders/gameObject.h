#pragma once

#include "vec2.h"

class GameObject
{
public:
	vec2 position,
		velocity;
	float radius;

	float speed;

	GameObject(float x, float y, float radius)
	: position({ x, y }), speed(0),
	  velocity({ 0, 0 }), radius(radius)
	{ }


	void update();
	void draw();

	virtual void onUpdate() {}
	virtual void onDraw() {}
	virtual void onCollision(GameObject &o) {}
};

void collides(GameObject &a, GameObject &b);