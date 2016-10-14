#include <SFML/Graphics.hpp>
#include "Packman.h"

void initializePackman(Packman& shape);
void render(sf::RenderWindow& window, sf::CircleShape & shape);
void handleEvents(sf::RenderWindow & window, Packman& packman);
void update(sf::Clock &clock, Packman &packman);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Title");
	Packman packman;
	initializePackman(packman);

	sf::Clock clock;

	while (window.isOpen())
	{
		handleEvents(window, packman);
		update(clock, packman);
		render(window, packman.shape);
	}
	return 0;
}

void update(sf::Clock &clock, Packman &packman)
{
	const float elapsedTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	updatePackman(packman, elapsedTime);
}

void render(sf::RenderWindow & window, sf::CircleShape & shape)
{
	window.clear();
	window.draw(shape);
	window.display();
}

void handleEvents(sf::RenderWindow& window, Packman& packman)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			handlePackmanKeyPress(event.key, packman);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			handlePackmanKeyRelease(event.key, packman);
		}
	}
}