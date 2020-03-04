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

	handTexture.loadFromFile("gfx/icon.png");
	hand.setTexture(&handTexture);
	hand.setSize(sf::Vector2f(10, 10));
	hand.setPosition(200, 50);
	hand.setWindow(window);
	hand.setInput(input);

	proTexture.loadFromFile("gfx/Beach_Ball.png");
	projectile.setTexture(&proTexture);
	projectile.setSize(sf::Vector2f(75, 75));
	projectile.setPosition(100, 200);
	projectile.setWindow(window);
	projectile.setInput(input);
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
	projectile.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	hand.update(dt);
	projectile.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(hand);
	window->draw(projectile);
	projectile.Draw();

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