#include "AngryBirdExample.h"
AngryBirdExample::AngryBirdExample()
{
	//initilising the physics of the ball
	scale = 200.0f; //scale as numbers are in pixels
	gravity = sf::Vector2f(0, 9.8f) * scale;
	acceleration = 5.f;
	mass = 2;

	drag = false;

	line.pts[0].color = sf::Color::Green;
	line.pts[0].position = sf::Vector2f(0, 0);
	line.pts[1].color = sf::Color::Green;
	line.pts[1].position = sf::Vector2f(0, 0);
}

void AngryBirdExample::handleInput(float dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !drag)
	{
		if (!drag)
		{
			startPos = sf::Mouse::getPosition(*window);
			drag = true;
			line.pts[0].position.x = startPos.x;
			line.pts[0].position.y = startPos.y;
			line.pts[1].position.x = startPos.x;
			line.pts[1].position.y = startPos.y;
		}

	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && drag)
	{
		endPos = sf::Mouse::getPosition(*window);
		drag = false;

		newforceVector = sf::Vector2f(static_cast<float>(endPos.x - startPos.x), static_cast<float>(endPos.y - startPos.y));
		line.pts[1].position.x = sf::Mouse::getPosition(*window).x;
		line.pts[1].position.y = sf::Mouse::getPosition(*window).y;
	}
	else if (drag)

	{
		line.pts[1].position.x = sf::Mouse::getPosition(*window).x;
		line.pts[1].position.y = sf::Mouse::getPosition(*window).y;
	}
}

void AngryBirdExample::update(float dt)
{
	//   FORCE
	//F = ma, sum all forces including input and gravity
	sf::Vector2f totalForce = newforceVector * mass;
	float forceMag = Vector::magnitude(totalForce);
	sf::Vector2f forceDirection = Vector::normalise(totalForce);

	//if F = ma then a = F/m
	acceleration = forceMag / mass;
	direction = forceDirection;

	//v = u + at
	sf::Vector2f u = velocity;
	velocity = velocity + (direction * acceleration) * dt;	
	setPosition(getPosition() + velocity * dt);


	//  GRAVITY
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; //v = u + at
	setPosition(getPosition() + pos);


	//  WINDOW COLLISION
	if (getPosition().y + 75 >= window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - 75);
		stepVelocity = (-stepVelocity) / 1.2f;
	}
	if (getPosition().y <= 0)
	{
		setPosition(getPosition().x, 0);
	}
	if (getPosition().x + 75 >= window->getSize().x)
	{
		setPosition(window->getSize().x - 75, getPosition().y);
		velocity = (-velocity) / 1.2f;
	}
	if (getPosition().x <= 0)
	{
		setPosition(0, getPosition().y);
		velocity = (-velocity) / 1.2f;
	}
}

void AngryBirdExample::Draw()
{
	line.Draw(window);
}


AngryBirdExample::~AngryBirdExample()
{
}