#pragma once

class Window
{
public:
	Window();
	Window(const std::string title, const sf::Vector2u& size);
	~Window();

	void BeginDraw();
	void EndDraw();
	void Update();

	bool IsDone() const;
	bool IsFullscreen() const;
	sf::Vector2u GetWindowSize() const;
	sf::Vector2f GetMousePosition() const;
	sf::RenderWindow& GetRenderWindow();
	void ToggleFullscreen();

	void Draw(sf::Drawable& drawable);
private:
	void Setup(const std::string& title, const sf::Vector2u size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	sf::Vector2f m_mousePosition;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};
