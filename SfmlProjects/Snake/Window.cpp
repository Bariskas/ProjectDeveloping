#include "stdafx.h"
#include "Window.h"

Window::Window()
{
	Setup("MiniGame title", sf::Vector2u(800, 600));
}

Window::Window(const std::string title, const sf::Vector2u& size)
{
	Setup(title, size);
}

Window::~Window()
{
	Destroy();
}

void Window::BeginDraw()
{
	m_window.clear(sf::Color::White);
}

void Window::EndDraw()
{
	m_window.display();
}

void Window::Update()
{
	sf::Event event;
	while(m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_isDone = true;
		} 
		else if (event.type == sf::Event::KeyPressed 
			&& event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
		else if (event.type == sf::Event::MouseMoved)
		{
			m_mousePosition.x = event.mouseMove.x;
			m_mousePosition.y = event.mouseMove.y;
		}
	}
}

bool Window::IsDone() const
{
	return m_isDone;
}

bool Window::IsFullscreen() const
{
	return m_isFullscreen;
}

sf::Vector2u Window::GetWindowSize() const
{
	return m_windowSize;
}

sf::Vector2f Window::GetMousePosition() const
{
	return m_mousePosition;
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void Window::Draw(sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

void Window::Setup(const std::string& title, const sf::Vector2u size)
{
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Create()
{
	auto style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}

