#pragma once

struct vec2 { float x, y; };

float dist(vec2 a, vec2 b);
bool circleOverlap(vec2 p1, float r1,
				   vec2 p2, float r2);

vec2 operator+(vec2 a, vec2 b);
vec2 operator-(vec2 a, vec2 b);

vec2 operator*(vec2 a, float b);
vec2 operator/(vec2 a, float b);

bool operator==(vec2 a, vec2 b);

vec2 integrate(vec2 pos, vec2 vel, float dt);

float randRange(float min, float max);

//alpha is value between 0 and 1
float lerp(float start, float end, float alpha);