#include "Chaser.h"
Chaser::Chaser()
{
	acceleration = 10.f;
}

void Chaser::update(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());

	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}

Chaser::~Chaser()
{
}