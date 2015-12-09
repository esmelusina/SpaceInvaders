#pragma once
#include "gameObject.h"
// In gamestate
	// vector of particles, spawn particle function
	// we have to update/draw particles
// Anywhere else, now, we can call spawnParticle and make magic!
class Particle : public GameObject
{
	float startRadius, endRadius;
	float lifespan, lifetime;

	Particle(float x, float y,
		float a_startRadius, float a_endRadius,
		float a_lifetime, unsigned a_color)

		: GameObject(x,y,a_startRadius),
		  endRadius(a_endRadius), startRadius(a_startRadius),
		  lifespan(0), lifetime(a_lifetime)
	{
		color = a_color;
	}
	void onUpdate()
	{
		radius = lerp(startRadius, endRadius, lifespan / lifetime);

		lifespan += sfw::getDeltaTime();		
		if (lifespan > lifetime) active = false;
	}
};