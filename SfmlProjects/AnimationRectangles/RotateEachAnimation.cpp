#include "stdafx.h"
#include "RotateEachAnimation.h"

using namespace std;

RotateEachAnimation::RotateEachAnimation(int ticksForAnimation, float rotateAngle, CRectangles& objectToRotate)
	: m_ticksForAnimation(ticksForAnimation)
	, m_rotateAngle(rotateAngle)
	, m_objectToRotate(objectToRotate)
{
}

bool RotateEachAnimation::IsExpired() const
{
	return m_ticksUntilExpired == 0;
}

void RotateEachAnimation::UpdateRectangles()
{
	if (!m_isInitialized)
	{
		throw runtime_error("Cant run uninitialized animation");
	}
	m_objectToRotate.rotate(m_rotateAnglePerTick);
	m_ticksUntilExpired--;
}

void RotateEachAnimation::Initialize()
{
	m_ticksUntilExpired = m_ticksForAnimation;
	m_rotateAnglePerTick = (m_rotateAngle / m_ticksForAnimation);
	m_isInitialized = true;
}
