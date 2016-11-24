#pragma once
#include "IAnimation.h"

class RotateEachAnimation :
	public IAnimation
{
public:
	RotateEachAnimation(int ticksForAnimation, float rotateAngle, CRectangles& objectToRotate);
	~RotateEachAnimation() {};
	virtual bool IsExpired() const;
	virtual void UpdateRectangles() override;
	virtual void Initialize() override;
private:
	const float m_rotateAngle;
	float m_rotateAnglePerTick;
	CRectangles& m_objectToRotate;
	int m_ticksForAnimation;
	int m_ticksUntilExpired;
	bool m_isInitialized = false;
};

