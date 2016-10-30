#include "ClockFace.h"

using namespace sf;

ClockFace::ClockFace() 
	: m_centerCircle(CircleShape(10)), m_clockCircle(CircleShape(CLOCK_CIRCLE_SIZE))
{ }

void ClockFace::Initialize(const RenderWindow& window)
{
	InitializeCenterCircle(window);
	InitializeClockCircle(window);
	InitializeDots(window);
	InitializeHours(window);
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
	for (auto& hour : m_hours)
	{
		target.draw(hour);
	}
}

void ClockFace::InitializeDots(const RenderWindow& window)
{
	int x, y;
	float angle = 0.0;
	for (int i = 0; i < DOT_COUNT; ++i)
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

		angle = angle + ((2 * M_PI) / DOT_COUNT);
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

void ClockFace::InitializeHours(const RenderWindow& window)
{
	InitializeHourFont();

	float angle = -M_PI / 3;

	Text text("", m_hours_font, 50);
	text.setFillColor(sf::Color::Black);
	Vector2f position(0, 0);

	for (int i = 0; i < HOUR_COUNT; i++)
	{
		text.setString(std::to_string(i + 1));
		m_hours[i] = text;

		position.x = POLAR_COORDINATE * cos(angle);
		position.y = POLAR_COORDINATE * sin(angle);
		sf::Vector2f absolutePosition(position.x + window.getSize().x / 2, position.y + window.getSize().y / 2);

		sf::FloatRect rect = m_hours[i].getGlobalBounds();
		m_hours[i].setOrigin(rect.width / 2.f, rect.height / 2.f);
		m_hours[i].setPosition(absolutePosition.x, absolutePosition.y - rect.height / 2.f);

		angle += (2 * M_PI) / HOUR_COUNT;
	}
}

void ClockFace::InitializeHourFont()
{
	if (!m_hours_font.loadFromFile("resources/arial.ttf"))
	{
		throw std::runtime_error("wrong font path");
	}
}