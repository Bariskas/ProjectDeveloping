#pragma once
#include "IAnimation.h"

class MoveAnimation :
	public IAnimation
{
public:
	MoveAnimation(int ticksForAnimation, sf::Vector2f destination, CRectangles& objectToMove);
	~MoveAnimation() {};
	virtual bool IsExpired() const;
	virtual void UpdateRectangles() override;
	virtual void Initialize() override;
private:
	const sf::Vector2f m_destination;
	CRectangles& m_objectToMove;
	int m_ticksForAnimation;
	int m_ticksUntilExpired;
	bool m_isInitialized = false;
	sf::Vector2f m_distancePerTick;
};

