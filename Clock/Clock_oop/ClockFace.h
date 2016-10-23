#pragma once
#include "stdafx.h"

class ClockFace : public sf::Drawable, public sf::Transformable
{
public:
	ClockFace(const sf::RenderWindow& window);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	void InitializeDots(const sf::RenderWindow& window);
	void InitializeClockCircle(const sf::RenderWindow& window);
	void InitializeCenterCircle(const sf::RenderWindow& window);

	sf::CircleShape m_dot[60];
	sf::CircleShape m_clockCircle;
	sf::CircleShape m_centerCircle;

	static const int CLOCK_CIRCLE_THICKNESS = 2;
	static const int CLOCK_CIRCLE_SIZE = 250;
};