#include "Player.h"

Player::Player(float speed, sf::Vector2f size, sf::Vector2f position, sf::Color color, int health)
	:
	speed(speed), 
	faceRight(true),
	lastVelocity(sf::Vector2f()),
	health(health)
{ 
	body.setSize(size);
	body.setFillColor(color);
	body.setPosition(position);
	body.setOrigin(body.getSize() / 2.0f);
} 

Player::~Player() { }



void Player::update(float deltaTime)
{
	//sf::Vector2f movement(0.0f, 0.0f);
	lastVelocity.x = lastVelocity.y = 0; 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		lastVelocity.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		lastVelocity.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		lastVelocity.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		lastVelocity.y += speed * deltaTime;
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		if (speed < 100)
			speed = 100;
		else
			speed -= 50;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		if (speed > 750)
			speed = 750;
		else
			speed += 50.f;
	
	/*else
	{		
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	*/
	body.move(lastVelocity);
}