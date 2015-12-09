#include "vec2.h"
#include <cmath>
#include <ctime>

//  0 = start
// .5 = midpoint
//  1 = end
float lerp(float start, float end, float alpha)
{
	return start + alpha*(end - start);
}


float randRange(float min, float max)
{
	//random number between 0-1
	//if I roll a 0, I should get min
	//if I roll a 1, I should get max
	float alpha = rand() / (RAND_MAX*1.f);
	
	return min + alpha*(max-min);
}


float dist(vec2 a, vec2 b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;

	return sqrt(dx*dx + dy*dy);
}

bool circleOverlap(vec2 p1, float r1,
				   vec2 p2, float r2)
{
	float d = dist(p1, p2);
	float r = r1 + r2;
	return d < r;
}

vec2 operator+(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x + b.x;
	retval.y = a.y + b.y;
	return retval;
}
vec2 operator-(vec2 a, vec2 b) 
		{ return a + b*-1; }

vec2 operator*(vec2 a, float b)
		{ return {a.x * b, a.y * b}; }

vec2 operator/(vec2 a, float b)
		{ return a * (1 / b); }

bool operator==(vec2 a, vec2 b)
{
	return a.x == b.x && a.y == b.y;
}

vec2 integrate(vec2 pos, vec2 vel, float dt)
{
	return pos + vel * dt;
}