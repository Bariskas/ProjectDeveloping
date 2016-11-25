#pragma once

#include "Window.h"

class Game
{
public:
	Game();
	~Game() {};

	void HandleInput();
	void Update();
	void Render();
	Window& GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
private:
	void MoveDragon();
private:
	Window m_window;
	sf::Texture m_dragonTexture;
	sf::Sprite m_dragon;
	sf::Vector2i m_velocity;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};
