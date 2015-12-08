#include "vec2.h"
#include <cmath>

//sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))
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