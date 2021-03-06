#include "stdafx.h"
#include "World.h"
#include "Snake.h"

World::World(sf::Vector2u windSize)
{
	m_blockSize = 16;
	m_windowSize = windSize;
	RespawnApple();
	m_appleShape.setFillColor(sf::Color::Red);
	m_appleShape.setRadius(m_blockSize / 2);

	for (int i = 0; i < 4; ++i)
	{
		m_bounds[i].setFillColor(sf::Color(150, 0, 0));
		if (!((i + 1) % 2))
		{
			m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
		}
		else
		{
			m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
		}
		if (i < 2)
		{
			m_bounds[i].setPosition(0, 0);
		}
		else
		{
			m_bounds[i].setOrigin(m_bounds[i].getSize());
			m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
		}
	}
}

int World::GetBlockSize()
{
	return m_blockSize;
}

void World::RespawnApple()
{
	int maxX = (m_windowSize.x / m_blockSize) - 2;
	int maxY = (m_windowSize.y / m_blockSize) - 2;
	m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}

void World::Update(Snake & player)
{
	if (player.GetPosition() == m_item)
	{
		player.Extend();
		player.IncreaseScore();
		RespawnApple();
	}

	int gridSizeX = m_windowSize.x / m_blockSize;
	int gridSizeY = m_windowSize.y / m_blockSize;

	if (player.GetPosition().x <= 0
		|| player.GetPosition().y <= 0
		|| player.GetPosition().x >= gridSizeX - 1
		|| player.GetPosition().x >= gridSizeY - 1)
	{
		player.Lose();
	}
}

void World::Render(sf::RenderWindow & window)
{
	for (auto& bound : m_bounds)
	{
		window.draw(bound);
	}
	window.draw(m_appleShape);
}
