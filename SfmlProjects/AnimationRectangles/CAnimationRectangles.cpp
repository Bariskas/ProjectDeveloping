#include "stdafx.h"
#include "Parameters.h"
#include "Rectangles.h"
#include "CAnimationRectangles.h"
#include "RotateEachAnimation.h"

using namespace std;
using namespace sf;

CAnimationRectangles::CAnimationRectangles() :
	m_window(sf::VideoMode(1280, 600), "SFML Animation")
{
}


CAnimationRectangles::~CAnimationRectangles()
{
}

void CAnimationRectangles::Run()
{
	m_rectangles.Init();
	m_animationPool.push_back(new MoveAnimation(60, { 100, 100 }, m_rectangles));
	m_animationPool.push_back(new MoveAnimation(60, { 200, 200 }, m_rectangles));
	m_animationPool.push_back(new MoveAnimation(60, { 100, 200 }, m_rectangles));
	m_animationPool.push_back(new MoveAnimation(60, { 200, 100 }, m_rectangles));
	m_animationPool.push_back(new RotateEachAnimation(60, 360, m_rectangles));

	m_animationPool[0]->Initialize();
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(30);
	while (m_window.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		//while (timeSinceLastUpdate > TICK)
		//{
		//	timeSinceLastUpdate -= TICK;
			ProcessEvents();
		//}
		Update();
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

void CAnimationRectangles::Update()
{
	if (m_animationPool[m_currentAnimationIndex]->IsExpired())
	{
		m_currentAnimationIndex = (++m_currentAnimationIndex) % m_animationPool.size();
		m_animationPool[m_currentAnimationIndex]->Initialize();
	}
	m_animationPool[m_currentAnimationIndex]->UpdateRectangles();
}

void CAnimationRectangles::Render()
{
	m_window.clear();
	m_window.draw(m_rectangles);
	m_window.display();
}
