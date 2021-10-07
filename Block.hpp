#pragma once
#include <SFML/Graphics.hpp>

class Block
{
private:
	sf::RectangleShape shape;	
public:
	Block()
	{
		shape.setFillColor(sf::Color::White);
		sf::Vector2f size = sf::Vector2f(50.f, 50.f);
		shape.setSize(size);
		shape.setPosition(0, 0);
	}
	Block(const sf::RectangleShape& shape)
		:
		shape(shape)
	{ }
	Block(sf::Vector2f size, sf::Vector2f position, sf::Color color)
	{
		shape.setSize(size);
		shape.setFillColor(color);
		shape.setPosition(position);
	}

	void drawOnWindow(sf::RenderWindow& window)
	{
		window.draw(shape);
	}
	void setSize(sf::Vector2f size)
	{
		shape.setSize(size);
	}
	void setPosition(sf::Vector2f pos)
	{
		shape.setPosition(pos);
	}
	void setPosition(float posx, float posy)
	{
		shape.setPosition(sf::Vector2f(posx, posy));
	}

	sf::FloatRect getGlobalBounds() const { return shape.getGlobalBounds(); }

	void setFillColor(sf::Color color)
	{
		shape.setFillColor(color);
	}

	sf::Vector2f getSize() const { return shape.getSize(); }
	sf::Vector2f getPosition() const { return shape.getPosition(); }

};