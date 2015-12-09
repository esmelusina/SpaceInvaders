#include "gameObject.h"
#include "sfwdraw.h"

GameState *GameObject::gs;

void GameObject::update()
{
	if (!active) return;
	position = integrate(position, velocity, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	if (!active) return;
	sfw::drawCircle(position.x, position.y,
						radius, 12, color);

	onDraw();
}

void collides(GameObject &a, GameObject &b)
{
	if(a.active && b.active)
		if (circleOverlap(a.position, a.radius,
						  b.position, b.radius))
		{
			a.onCollision(b);
			b.onCollision(a);
		}
}

// Create a Game Object and...
// Call these in the game loop!