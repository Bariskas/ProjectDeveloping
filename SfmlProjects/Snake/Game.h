#pragma once

#include "Window.h"
#include "World.h"

class Game
{
public:
	Game();
	~Game() {};

	void HandleInput();
	void Update();
	void Render();
	Window& GetWindow();

	float GetElapsed();
	void RestartClock();
private:
private:
	Window m_window;
	World m_world;
	Snake m_snake;
	sf::Vector2i m_velocity;
	sf::Clock m_clock;
	float m_elapsed;
};
