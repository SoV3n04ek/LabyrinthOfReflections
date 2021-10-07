#pragma once
#include "Block.hpp"

class Wall : public Block
{
	int id;
public:
	enum WALL_IDS {STANDARD, WALL_FOR_WIN};
	Wall()
		:
		Block(sf::Vector2f(50.f,50.f), sf::Vector2f(0.f, 0.f), sf::Color::White),
		id(0)
	{}
	Wall(sf::Vector2f size, sf::Vector2f position, sf::Color color, int id)
	:
		Block(size, position, color),
		id(id)
	{ }

	void setId(int id)
	{
		this->id = id;
	}

	int getId() const { return id; }
};