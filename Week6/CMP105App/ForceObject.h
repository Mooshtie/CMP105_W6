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
	bool isJumping;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	sf::Vector2f gravity;
	sf::RenderWindow* window;

	void handleInput(float dt);
	void update(float dt);
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
};

