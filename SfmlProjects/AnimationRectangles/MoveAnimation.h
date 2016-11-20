#pragma once
#include "IAnimation.h"
class MoveAnimation :
	public IAnimation
{
public:
	MoveAnimation();
	~MoveAnimation();
	MoveAnimation(int ticksForAnimation, sf::Vector2i destination);
	void UpdateRectangles(RecVector&) override;
	void Initialize() override;
private:
	const sf::Vector2f m_destination;
	const sf::Time m_timeForAnimation;
	sf::Time m_timeUntilExpired;
	bool m_isInitialized;
	sf::Vector2i distancePerTick;
};

