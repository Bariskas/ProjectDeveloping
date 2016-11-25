#include "stdafx.h"
#include "Game.h"

Game::Game()
	: m_window("it's fucking dragon, bitches", sf::Vector2u(800, 600))
{
	m_dragonTexture.loadFromFile("dragon.png");
	m_dragon.setTexture(m_dragonTexture);
	m_dragon.setOrigin(m_dragonTexture.getSize().x / 2, m_dragonTexture.getSize().y / 2);
	m_velocity = sf::Vector2i(50, 50);
}

void Game::HandleInput()
{
}

void Game::Update()
{
	m_window.Update();
	MoveDragon();
	RotateDragon();
}

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_dragon);
	m_window.EndDraw();
}

Window& Game::GetWindow()
{
	return m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}

void Game::MoveDragon()
{
	sf::Vector2u windowSize = m_window.GetWindowSize();
	sf::Vector2u dragonTextureSize = m_dragonTexture.getSize();

	if ((m_dragon.getPosition().x > windowSize.x - dragonTextureSize.x && m_velocity.x > 0)
		|| (m_dragon.getPosition().x < 0 && m_velocity.x < 0))
	{
		m_velocity.x = -m_velocity.x;
	}

	if ((m_dragon.getPosition().y > windowSize.y - dragonTextureSize.y && m_velocity.y > 0)
		|| (m_dragon.getPosition().y < 0 && m_velocity.y < 0))
	{
		m_velocity.y = -m_velocity.y;
	}

	float fElapsed = m_elapsed.asSeconds();
	m_dragon.setPosition(
		m_dragon.getPosition().x + (m_velocity.x * fElapsed),
		m_dragon.getPosition().y + (m_velocity.y * fElapsed)
	);
}

void Game::RotateDragon()
{
	sf::Vector2f mousePosition = m_window.GetMousePosition();
	sf::Vector2f dragonPosition = m_dragon.getPosition();

	float angle = atan2f(mousePosition.x - dragonPosition.x, mousePosition.y - dragonPosition.y);
	m_dragon.setRotation(-angle * 180 / M_PI);
}
