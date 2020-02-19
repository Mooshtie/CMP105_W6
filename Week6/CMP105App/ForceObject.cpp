#include "ForceObject.h"
ForceObject::ForceObject()
{
	//initilising the physics of the ball
	scale = 200.0f; //scale as numbers are in pixels
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

void ForceObject::handleInput(float dt)
{
	//jump!
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping && getPosition().y + 50 >= window->getSize().y)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	//teleport
	if (input->isMouseLDown())
	{
		input->setMouseLDown(false);
		setPosition(input->getMouseX(), input->getMouseY());
	}
}

void ForceObject::update(float dt)
{
	//applying force of gravity
	//move shape by adding new velocity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; //v = u + at
	setPosition(getPosition() + pos);

	// check for collision with bottom of window
	if (getPosition().y + 50 >= window->getSize().y)
	{
		isJumping = false;
		setPosition(getPosition().x, window->getSize().y - 50);
		stepVelocity = (-stepVelocity)/1.2f;
	}
}

ForceObject::~ForceObject()
{
}