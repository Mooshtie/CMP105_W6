#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball.setTexture(&ballTexture);
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(200, 50);
	ball.setWindow(window);
	ball.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	ball.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}