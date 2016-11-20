#include "stdafx.h"
#include "MoveAnimation.h"

using namespace std;

MoveAnimation::MoveAnimation()
{
}


MoveAnimation::~MoveAnimation()
{
}

MoveAnimation::MoveAnimation(int timeUntilExpired, sf::Vector2i destination)
	: m_timeForAnimation(timeUntilExpired)
	, m_destination(destination)
	, m_timeUntilExpired(timeUntilExpired)
{
}

void MoveAnimation::UpdateRectangles(RecVector &)
{
	if (!m_isInitialized)
	{
		throw runtime_error ("Cant run uninitialized animation");
	}
	for ()
	{

	}
}

void MoveAnimation::Initialize()
{

}
