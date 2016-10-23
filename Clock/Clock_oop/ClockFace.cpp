#include "ClockFace.h"

using namespace sf;

ClockFace::ClockFace(const RenderWindow& window) 
	: m_centerCircle(CircleShape(10)), m_clockCircle(CircleShape(CLOCK_CIRCLE_SIZE))
{
	InitializeCenterCircle(window);
	InitializeClockCircle(window);
	InitializeDots(window);
	Initialize
}

void ClockFace::draw(RenderTarget &target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_centerCircle);
	target.draw(m_clockCircle);
	for (auto& dot : m_dot)
	{
		target.draw(dot);
	}
}

void ClockFace::InitializeDots(const RenderWindow& window)
{
	int x, y;
	float angle = 0.0;
	// Create dots and place them to very right positions
	for (int i = 0; i < 60; ++i)
	{
		x = (CLOCK_CIRCLE_SIZE - 10) * cos(angle);
		y = (CLOCK_CIRCLE_SIZE - 10) * sin(angle);

		if (i % 5 == 0)
		{
			m_dot[i] = sf::CircleShape(3);
		}
		else
		{
			m_dot[i] = sf::CircleShape(1);
		}

		m_dot[i].setFillColor(sf::Color::Black);
		m_dot[i].setOrigin(m_dot[i].getGlobalBounds().width / 2, m_dot[i].getGlobalBounds().height / 2);
		m_dot[i].setPosition(x + window.getSize().x / 2, y + window.getSize().y / 2);

		angle = angle + ((2 * M_PI) / 60);
	}
}

void ClockFace::InitializeClockCircle(const RenderWindow& window)
{
	m_clockCircle.setFillColor(sf::Color::Blue);
	m_clockCircle.setPointCount(100);
	m_clockCircle.setOutlineThickness(CLOCK_CIRCLE_THICKNESS);
	m_clockCircle.setOutlineColor(sf::Color::Black);
	m_clockCircle.setOrigin(m_clockCircle.getGlobalBounds().width / 2, m_clockCircle.getGlobalBounds().height / 2);
	m_clockCircle.setPosition(window.getSize().x / 2 + CLOCK_CIRCLE_THICKNESS, window.getSize().y / 2 + CLOCK_CIRCLE_THICKNESS);
}

void ClockFace::InitializeCenterCircle(const RenderWindow& window)
{
	auto windowCenter = Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	m_centerCircle.setPointCount(100);
	m_centerCircle.setFillColor(sf::Color::Red);
	m_centerCircle.setOrigin(m_centerCircle.getGlobalBounds().width / 2, m_centerCircle.getGlobalBounds().height / 2);
	m_centerCircle.setPosition(windowCenter);
}