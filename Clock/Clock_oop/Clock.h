#pragma once
#include "stdafx.h"
#include "ClockFace.h"

class Clock
{
public:
	Clock();
	void Run();
private:
	void ProcessEvents();
	void Update();
	void Render();
	void InitializeHand(sf::RectangleShape& hand, const sf::Vector2f& windowCenter, const sf::Color& color);

	sf::RenderWindow m_window;
	sf::RectangleShape m_hourHand;
	sf::RectangleShape m_minuteHand;
	sf::RectangleShape m_secondHand;
	std::unique_ptr<ClockFace> m_clockFace;

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
};