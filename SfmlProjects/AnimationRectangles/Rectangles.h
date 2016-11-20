#pragma once

class CRectangles : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
	CRectangles();
	~CRectangles();
	void Init();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void move(const sf::Vector2f &offset);
	void setOrigin(const sf::Vector2f &origin);
	sf::Vector2f getPosition();
private:
	sf::Vector2f m_origin;
	RecVector m_rectangles;
	sf::Vector2f m_currentPosition;
};

