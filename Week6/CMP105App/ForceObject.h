#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class ForceObject :
	public GameObject
{
public:
	ForceObject();
	~ForceObject();

	float scale;
	sf::Vector2f stepVelocity;
	sf::Vector2f gravity;
	sf::RenderWindow* window;

	void update(float dt);
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
};

