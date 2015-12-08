#include "gameObject.h"
#include "sfwdraw.h"

void GameObject::update()
{
	position = integrate(position, velocity, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	sfw::drawCircle(position.x, position.y, radius);

	onDraw();
}

void collides(GameObject &a, GameObject &b)
{
	if (circleOverlap(a.position, a.radius,
					  b.position, b.radius))
	{
		a.onCollision(b);
		b.onCollision(a);
	}
}

// Create a Game Object and...
// Call these in the game loop!