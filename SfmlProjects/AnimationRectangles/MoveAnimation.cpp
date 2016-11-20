#include "stdafx.h"
#include "MoveAnimation.h"

using namespace std;

MoveAnimation::MoveAnimation(int ticksForAnimation, sf::Vector2f destination, CRectangles& objectToMove)
	: m_ticksForAnimation(ticksForAnimation)
	, m_destination(destination)
	, m_objectToMove(objectToMove)
{
}

bool MoveAnimation::IsExpired() const
{
	return m_ticksUntilExpired == 0;
}

void MoveAnimation::UpdateRectangles()
{
	if (!m_isInitialized)
	{
		throw runtime_error ("Cant run uninitialized animation");
	}
	m_objectToMove.move(m_distancePerTick);
	m_ticksUntilExpired--;
}

void MoveAnimation::Initialize()
{
	m_ticksUntilExpired = m_ticksForAnimation;
	m_distancePerTick = (m_destination - m_objectToMove.getPosition());
	m_distancePerTick /= (float)m_ticksForAnimation;
	m_isInitialized = true;
}
