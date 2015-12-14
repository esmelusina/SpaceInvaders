#pragma once

// An interface

class BaseState
{
public:
	// Abstract Function
	virtual void update() = 0;
	virtual void draw()   = 0;
};