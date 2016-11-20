#pragma once
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
	RecVector m_rectangles;
};

