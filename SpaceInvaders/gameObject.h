#pragma once

#include "vec2.h"
#include "sfwdraw.h"
#include "declconst.h"

class GameObject
{
public:
	static GameState *gs;

	vec2 position, velocity;
	float radius;
	unsigned color;
	float speed;
	bool active;


	GameObject(float x, float y, float radius)
	: position({ x, y }), speed(0), color(MAGENTA),
	  velocity({ 0, 0 }), radius(radius), active(true)
	{ }


	void update();
	void draw();

	virtual void onUpdate() {}
	virtual void onDraw()	{}
	virtual void onCollision(GameObject &o) {}
};

void collides(GameObject &a, GameObject &b);