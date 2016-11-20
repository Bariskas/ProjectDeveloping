#include "stdafx.h"
#include "CAnimationRectangles.h"
#include "Parameters.h"

using namespace std;
using namespace sf;

CAnimationRectangles::CAnimationRectangles()
{
	m_rectangles.resize(RECTANGLES_NUMBER);

	Vector2f size = Vector2f(RECTANGLES_SIDE_LONG, RECTANGLES_SIDE_LONG);
	generate_n(m_rectangles, RECTANGLES_NUMBER, [&]() {
		return new RectangleShape(size);
	});

	int i = 0;
	transform(m_rectangles.begin(), m_rectangles.end(), m_rectangles.begin(), 
		[&](RectangleShape& rectangle){
			rectangle.setPosition(i * RECTANGLES_SIDE_LONG + i * DISTANCE_BETWEEN, 0);
			rectangle.setOrigin(size / 2.f);
			rectangle.setFillColor(RECTANGLE_COLOR);
		}
	)
}


CAnimationRectangles::~CAnimationRectangles()
{
}

void CAnimationRectangles::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TICK)
		{
			timeSinceLastUpdate -= TICK;
			ProcessEvents();
			Update(TICK);
		}
		Render();
	}
}

void CAnimationRectangles::ProcessEvents()
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

void CAnimationRectangles::Update(sf::Time deltaTime)
{

}

void CAnimationRectangles::Render()
{
}
