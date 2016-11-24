#include "stdafx.h"
#include "Rectangles.h"
#include "Parameters.h"

using namespace sf;
using namespace std;

CRectangles::CRectangles()
{
}


CRectangles::~CRectangles()
{
}

void CRectangles::Init()
{
	m_rectangles.resize(RECTANGLES_NUMBER);

	Vector2f size = Vector2f(RECTANGLES_SIDE_LONG, RECTANGLES_SIDE_LONG);
	generate_n(m_rectangles.begin(), RECTANGLES_NUMBER, [&]() {
		return new RectangleShape(size);
	});

	int i = 0;
	m_currentPosition = {0 , INITIAL_MARGIN_TOP };
	transform(m_rectangles.begin(), m_rectangles.end(), m_rectangles.begin(), [&](RectangleShape* rectangle) {
		rectangle->setPosition(i * RECTANGLES_SIDE_LONG + i * DISTANCE_BETWEEN, INITIAL_MARGIN_TOP);
		rectangle->setOrigin(size / 2.f);
		rectangle->setFillColor(RECTANGLE_COLOR);
		++i;
		return rectangle;
	});

}

void CRectangles::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/*for (size_t i = 0; i < m_rectangles.size(); i++)
	{
		target.draw(*(m_rectangles[i]), states);
	}*/
	
	for (sf::RectangleShape* rec : m_rectangles)
	{
		target.draw(*rec, states);
	}
}

void CRectangles::rotate(const float angle)
{
	for (size_t i = 0; i < m_rectangles.size(); i++)
	{
		m_rectangles[i]->rotate(angle);
	}
	/*for (auto rec : m_rectangles)
	{
	(*rec).move(Vector2f(10, 0));
	}*/
}

void CRectangles::move(const sf::Vector2f& offset)
{
	for (size_t i = 0; i < m_rectangles.size(); i++)
	{
		m_rectangles[i]->move(offset);
	}
	m_currentPosition += offset;
	/*for (auto rec : m_rectangles)
	{
		(*rec).move(Vector2f(10, 0));
	}*/
}

void CRectangles::setOrigin(const sf::Vector2f &origin)
{
}

sf::Vector2f CRectangles::getPosition()
{
	return m_currentPosition;
}