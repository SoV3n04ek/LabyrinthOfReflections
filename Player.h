#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player 
{
private:
	sf::RectangleShape body;
	float speed;
	sf::Vector2f lastVelocity;
	bool faceRight;
	int health;
public:
	Player(float speed, sf::Vector2f size, sf::Vector2f position, sf::Color color = sf::Color::White, int health = 100);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window) { window.draw(body); }

	sf::Vector2f getPosition() { return body.getPosition(); }
	//Collider getColider() { return Collider(body); }
	Player& setPosition(float x, float y)
	{
		body.setPosition(sf::Vector2f(x, y));
		return *this;
	}

	Player& setSpeed(float speed)
	{
		this->speed = speed;
		return *this;
	}

	Player& setVelocity(sf::Vector2f velocity)
	{
		this->lastVelocity = velocity;
		return *this;
	}

	Player& setVelocity(int health)
	{
		this->health = health;
		return *this;
	}

	void setHealth(int health)
	{
		this->health = health;
	}

	int getHealth() const { return health; }

	sf::Vector2f getSize() const { return body.getSize();}
	sf::Vector2f getLastVelicity() const { return lastVelocity; }

	sf::FloatRect getGlobalBounds() const { return body.getGlobalBounds(); }


};