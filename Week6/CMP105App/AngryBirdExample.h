#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include "Line.h"

class AngryBirdExample :
	public GameObject
{
public:
	AngryBirdExample();
	~AngryBirdExample();

	float scale;
	float mass;
	float acceleration;
	bool drag;
	sf::Vector2f direction;
	sf::Vector2f newforceVector;
	sf::Vector2f gravity;
	sf::Vector2i startPos, endPos;
	sf::RenderWindow* window;
	sf::Vector2f stepVelocity;

	void handleInput(float dt);
	void update(float dt);
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	void Draw();

	Line line;
};

