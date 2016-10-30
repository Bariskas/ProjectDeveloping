#pragma once
#include "stdafx.h"

class ClockFace : public sf::Drawable, public sf::Transformable
{
public:
	ClockFace();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void ClockFace::Initialize(const sf::RenderWindow& window);

private:
	static const int CLOCK_CIRCLE_THICKNESS = 2;
	static const int CLOCK_CIRCLE_SIZE = 250;
	static const int DOT_COUNT = 60;
	static const int HOUR_COUNT = 12;
	static const int HOUR_OFFSET = 55;
	static const int POLAR_COORDINATE = CLOCK_CIRCLE_SIZE - HOUR_OFFSET;

	void InitializeDots(const sf::RenderWindow& window);
	void InitializeClockCircle(const sf::RenderWindow& window);
	void InitializeCenterCircle(const sf::RenderWindow& window);
	void InitializeHours(const sf::RenderWindow& window);
	void InitializeHourFont();

	sf::Text m_hours[HOUR_COUNT];
	sf::Font m_hours_font;
	sf::CircleShape m_dot[DOT_COUNT];
	sf::CircleShape m_clockCircle;
	sf::CircleShape m_centerCircle;
};