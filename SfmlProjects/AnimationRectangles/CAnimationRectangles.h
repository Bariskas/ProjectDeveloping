#pragma once
#include "Rectangles.h"
#include "MoveAnimation.h"

class CAnimationRectangles
{
public:
	CAnimationRectangles();
	~CAnimationRectangles();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Render();

private:
	sf::RenderWindow m_window;
	CRectangles m_rectangles;
	int m_currentAnimationIndex;
	std::vector<IAnimation*> m_animationPool;
};

