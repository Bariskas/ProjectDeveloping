#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cmath>

using namespace std;

static const int screenWidth = 800;
static const int screenHeight = 600;
static const int clockCircleSize = 250;
static const int clockCircleThickness = 2;

void initializeClock();
void initializeDots(sf::CircleShape(&dots)[60], const sf::RenderWindow& window);
void initializeClockCircle(sf::CircleShape& clockCircle, const sf::RenderWindow& window);
void initializeCenterCircle(sf::CircleShape& centerCircle, const sf::Vector2f& windowCenter);
void initializeHand(sf::RectangleShape& hand, const sf::Vector2f& windowCenter, const sf::Color& color);
void initializeClockBrandSprite(sf::Sprite& clockBrandSprite, const sf::RenderWindow& window);

int main()
{
	int x, y;
	initializeClock();
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Analog Clock", sf::Style::Close, settings);

	sf::Vector2f windowCenter = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	sf::CircleShape dot[60];
	initializeDots(dot, window);

	sf::CircleShape clockCircle(clockCircleSize);
	initializeClockCircle(clockCircle, window);

	sf::CircleShape centerCircle(10);
	initializeCenterCircle(centerCircle, windowCenter);

	sf::RectangleShape hourHand(sf::Vector2f(5, 180));
	sf::RectangleShape minuteHand(sf::Vector2f(3, 240));
	sf::RectangleShape secondsHand(sf::Vector2f(2, 250));

	initializeHand(hourHand, windowCenter, sf::Color::Black);
	initializeHand(minuteHand, windowCenter, sf::Color::Black);
	initializeHand(secondsHand, windowCenter, sf::Color::Red);

	sf::Music clockTick;
	if (!clockTick.openFromFile("resources/clock-1.wav"))
		return EXIT_FAILURE;
	clockTick.setLoop(true);
	clockTick.play();

	sf::Sprite clockBrandSprite;
	try
	{
		initializeClockBrandSprite(clockBrandSprite, window);
	}
	catch(const exception& e)
	{
		return EXIT_FAILURE;
	}
	// Create clock background
	sf::Texture clockImage;
	if (!clockImage.loadFromFile("resources/clock-image.jpg"))
	{
		return EXIT_FAILURE;
	}

	clockCircle.setTexture(&clockImage);
	clockCircle.setTextureRect(sf::IntRect(40, 0, 500, 500));

	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Window closed: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Get system time
		std::time_t currentTime = std::time(NULL);

		struct tm * ptm = localtime(&currentTime);

		hourHand.setRotation(ptm->tm_hour * 30 + (ptm->tm_min / 2));
		minuteHand.setRotation(ptm->tm_min * 6 + (ptm->tm_sec / 12));
		secondsHand.setRotation(ptm->tm_sec * 6);

		// Clear the window
		window.clear(sf::Color::White);

		// Draw all parts of clock
		window.draw(clockCircle);

		for (int i = 0; i<60; i++)
		{
			window.draw(dot[i]);
		}

		window.draw(clockBrandSprite);
		window.draw(hourHand);
		window.draw(minuteHand);
		window.draw(secondsHand);
		window.draw(centerCircle);

		// Display things on screen
		window.display();
	}

	return EXIT_SUCCESS;
}

void initializeClock()
{

}

void initializeDots(sf::CircleShape(&dot)[60], const sf::RenderWindow& window)
{
	int x, y;
	float angle = 0.0;
	// Create dots and place them to very right positions
	for (int i = 0; i < 60; ++i)
	{
		x = (clockCircleSize - 10) * cos(angle);
		y = (clockCircleSize - 10) * sin(angle);

		if (i % 5 == 0)
		{
			dot[i] = sf::CircleShape(3);
		}
		else
		{
			dot[i] = sf::CircleShape(1);
		}

		dot[i].setFillColor(sf::Color::Black);
		dot[i].setOrigin(dot[i].getGlobalBounds().width / 2, dot[i].getGlobalBounds().height / 2);
		dot[i].setPosition(x + window.getSize().x / 2, y + window.getSize().y / 2);

		angle = angle + ((2 * M_PI) / 60);
	}
}

void initializeClockCircle(sf::CircleShape& clockCircle, const sf::RenderWindow& window)
{
	clockCircle.setPointCount(100);
	clockCircle.setOutlineThickness(clockCircleThickness);
	clockCircle.setOutlineColor(sf::Color::Black);
	clockCircle.setOrigin(clockCircle.getGlobalBounds().width / 2, clockCircle.getGlobalBounds().height / 2);
	clockCircle.setPosition(window.getSize().x / 2 + clockCircleThickness, window.getSize().y / 2 + clockCircleThickness);
}

void initializeCenterCircle(sf::CircleShape & centerCircle, const sf::Vector2f& windowCenter)
{
	centerCircle.setPointCount(100);
	centerCircle.setFillColor(sf::Color::Red);
	centerCircle.setOrigin(centerCircle.getGlobalBounds().width / 2, centerCircle.getGlobalBounds().height / 2);
	centerCircle.setPosition(windowCenter);
}

void initializeHand(sf::RectangleShape& hand, const sf::Vector2f& windowCenter, const sf::Color& color)
{
	hand.setFillColor(color);
	hand.setOrigin(hand.getGlobalBounds().width / 2, hand.getGlobalBounds().height - 25);
	hand.setPosition(windowCenter);
}

void initializeClockBrandSprite(sf::Sprite& clockBrandSprite, const sf::RenderWindow& window)
{
	sf::Texture clockBrand;
	if (!clockBrand.loadFromFile("resources/clock-brand.png"))
	{
		throw invalid_argument("Wrong path to picture");
	}

	clockBrandSprite.setTexture(clockBrand);
	clockBrandSprite.setOrigin(
		clockBrandSprite.getTextureRect().left + clockBrandSprite.getTextureRect().width / 2.0f,
		clockBrandSprite.getTextureRect().top + clockBrandSprite.getTextureRect().height / 2.0f
	);
	clockBrandSprite.setPosition(window.getSize().x / 2, window.getSize().y - 100);
}