#pragma once
#include <SFML/Graphics.hpp>

static const sf::Color PACKMAN_COLOR = sf::Color::Yellow;
static const float PACKMAN_SPEED = 20.f; // pixels per second.
static const sf::Vector2f PACKMAN_INITIAL_POSITION = { 100, 0 };

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Packman
{
	sf::CircleShape shape;
	Direction direction;
};

bool handlePackmanKeyPress(const sf::Event::KeyEvent &event, Packman &packman);
bool handlePackmanKeyRelease(const sf::Event::KeyEvent &event, Packman &packman);
void updatePackman(Packman &packman, float elapsedTime);
void initializePackman(Packman& packman);