#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Chaser :
	public GameObject
{
public:
	Chaser();
	~Chaser();

	float acceleration;

	sf::Vector2f target;
	sf::Vector2f direction;
	sf::RenderWindow* window;

	void update(float dt);
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
};

