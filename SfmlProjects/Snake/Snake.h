#pragma once

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {};
	sf::Vector2i position;
};

enum class Direction { None, Up, Down, Left, Right };

using SnakeBody = std::vector<SnakeSegment>;

class Snake
{
public:
	Snake(int blockSize);
	~Snake(){};

	void SetDirection(Direction dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose();
	void ToggleLost();

	void Extend();
	void Reset();

	void Move();
	void Tick();
	void Cut(int segments);
	void Render(sf::RenderWindow& window);
private:
	void CheckCollisions();

private:
	SnakeBody m_snakeBody;
	int m_size;
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	bool m_isLost;
	sf::RectangleShape m_bodyRect;
};
