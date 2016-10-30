#include "stdafx.h"
#include "Clock.h"

Clock::Clock() :
	m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Analog Clock", sf::Style::Close),
	m_hourHand(sf::RectangleShape(sf::Vector2f(5, 180))),
	m_minuteHand(sf::RectangleShape(sf::Vector2f(3, 240))),
	m_secondHand(sf::RectangleShape(sf::Vector2f(2, 250))),
	m_clockFace(new ClockFace())
{

}

void Clock::Run()
{
	auto windowCenter = sf::Vector2f(m_window.getSize().x / 2.0f, m_window.getSize().y / 2.0f);
	InitializeHand(m_hourHand, windowCenter, sf::Color::Black);
	InitializeHand(m_minuteHand, windowCenter, sf::Color::Black);
	InitializeHand(m_secondHand, windowCenter, sf::Color::Red);
	m_clockFace->Initialize(m_window);

	while (m_window.isOpen())
	{
		ProcessEvents();
		Update();
		Render();
	}
}

void Clock::ProcessEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Clock::Render()
{
	m_window.clear();

	sf::RenderStates states;
	m_clockFace->draw(m_window, states);
	m_window.draw(m_hourHand);
	m_window.draw(m_minuteHand);
	m_window.draw(m_secondHand);

	m_window.display();
}

void Clock::Update()
{
	std::time_t currentTime = std::time(NULL);

	struct tm * ptm = localtime(&currentTime);

	m_hourHand.setRotation(ptm->tm_hour * 30 + (ptm->tm_min / 2));
	m_minuteHand.setRotation(ptm->tm_min * 6 + (ptm->tm_sec / 12));
	m_secondHand.setRotation(ptm->tm_sec * 6);
}

void Clock::InitializeHand(sf::RectangleShape& hand, const sf::Vector2f& windowCenter, const sf::Color& color)
{
	hand.setFillColor(color);
	hand.setOrigin(hand.getGlobalBounds().width / 2, hand.getGlobalBounds().height - 25);
	hand.setPosition(windowCenter);
}