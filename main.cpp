#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Player.h"
#include "MyWindow.hpp"
#include "Wall.hpp"
#include "Menu.hpp"
#include "winconio.h"

int main()
{
	srand(time(0));

	const std::string gameName = "Labyrinth of Reflecitons";
	const std::string gameMenu = "Game Menu | Labyrinth of Reflecitons";

	Menu menu(DEFAULT_WIDTH, DEFAULT_HEIGHT, 0);

	sf::RenderWindow window(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), gameName.c_str(), sf::Style::Close);
	window.setFramerateLimit(120);

	/*while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		menu.draw(window);
		window.display();
	}
	*/ 

	// ======Player======
	const float gridSize = 50.0f;

	Player player(260.0f, sf::Vector2f(gridSize, gridSize), sf::Vector2f(202.0f, 250.0f), sf::Color(255, 198, 0));
	
	// ======Walls======
	std::vector<Wall> walls;
		
	Wall wall;
	wall.setFillColor(sf::Color::Red);
	wall.setSize(sf::Vector2f(gridSize, gridSize));
	
	wall.setPosition(gridSize * 5, gridSize * 2);
	walls.push_back(wall);

	// RANDOM fill walls positions

	for (int i = 0; i < 40; i++)
	{
		wall.setPosition(gridSize * (rand() % 30), gridSize * (rand() % 9));
		walls.push_back(wall);
	}

	for (int i = 0, k = 15, p = 4; i < 10; i++, p++)
	{
		wall.setPosition(gridSize * k, gridSize * p);
		walls.push_back(wall);
		if (k == 15 + 9)
		{
			i = 2;
			k = 1;
			p = 3;
		}
	}

	for (int i = 5, j = 3, k = 0; k < 14;k++, i++, j++)
	{
		wall.setPosition(gridSize * i, gridSize * j);
		if (i == 7)
			j--;
		if (i == 8)
			j += 2;
		if (j == 9)
			i = 4;
		if (j == 10)
			i = 11;
		walls.push_back(wall);
	}

	// wall for win
	wall.setFillColor(sf::Color::Green);
	wall.setId(Wall::WALL_FOR_WIN);
	wall.setPosition(gridSize * (10 + rand() % 5) , gridSize * (rand() % 9));
	walls.push_back(wall);

	// Collision
	sf::FloatRect nextPos;
	
	// ==============FOR DEBUG==============
	sf::RectangleShape nextBox;
	nextBox.setSize(sf::Vector2f(gridSize, gridSize));
	nextBox.setFillColor(sf::Color::Transparent);
	nextBox.setOutlineColor(sf::Color::White);
	nextBox.setOutlineThickness(1.0f);     

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		if (player.getHealth() <= 0)
		{
			ClearConsole();
			GotoXY(100 / 2, 5);
			
			TextColor(RED);
			std::cout << "YOU LOSE";
			window.close();
			for (int i = 0; i <= 10000; i++)
				std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			system("status\\you_lose.txt");
			
			break;
		}
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case  sf::Event::Resized:
					break;
				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128)
						printf("Key pressed: %c\n", evnt.text.unicode);
			}
		}
		
		// Collision with objects

		sf::Vector2f lastPosition = player.getPosition();

		for (auto& wall : walls)
		{
			sf::FloatRect playerBounds = player.getGlobalBounds();
			sf::FloatRect wallBounds = wall.getGlobalBounds();

			sf::Vector2f velocity = player.getLastVelicity();

			nextPos = playerBounds;

			nextPos.left += velocity.x * 1.2f;
			nextPos.top += velocity.y * 1.2f;

			nextBox.setPosition(nextPos.left, nextPos.top);

			if (wallBounds.intersects(nextPos))
			{
				std::cout << "\nCOLLISION WITH WALL";


				velocity.y = velocity.x = 0.f;

				player.setVelocity(velocity);
				player.setPosition(lastPosition.x, lastPosition.y);
				
				if (wall.getId() == Wall::WALL_FOR_WIN)
				{
					ClearConsole();
					//TODO: Win
					GotoXY(100 / 2, 5);

					TextColor(GREEN);
					std::cout << "You win! \n"; 
					TextColor(LIGHTGRAY);
					for (int i = 0; i <= 10000; i++)
						std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					system("status\\win.txt");
					window.close();
					break;
				}
				else
				{
					int wallDamage = 1;
					player.setHealth(player.getHealth() - wallDamage);
					std::cout << "Player health = " << player.getHealth() << "\n";
				}

				// https://prnt.sc/1v0hjrh

				// Bottom Collision 
				if (playerBounds.top < wallBounds.top
					&& playerBounds.top + playerBounds.height / 2.f < wallBounds.top + wallBounds.height / 2.f
					&& playerBounds.left < wallBounds.left + wallBounds.width / 2.f
					&& playerBounds.left + playerBounds.width / 2.f > wallBounds.left
					)
				{
					player.setVelocity(sf::Vector2f(player.getLastVelicity().x, 0.f));
					player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
				}

				// Right Collision
				if (playerBounds.left < wallBounds.left
					&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height 
					&& playerBounds.top + playerBounds.height  > wallBounds.top
					)
				{
					player.setVelocity(sf::Vector2f(0.f, player.getLastVelicity().y));
					player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
				}
				
				// Top Collision
				if (playerBounds.top < wallBounds.top
					&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left  + wallBounds.width 
					&& playerBounds.top + playerBounds.width > wallBounds.left
					)
				{
					player.setVelocity(sf::Vector2f(player.getLastVelicity().x, 0.f));
					player.setPosition(wallBounds.left, wallBounds.top + playerBounds.top);
				}
				
			}
		}

		// movement
		player.update(deltaTime);
		
		float halfOfPlayerSize = (player.getSize() / 2.0f).x;
	// Collision by WINDOW 
		
		// Left window border colision
		if (player.getPosition().x <= 0 + halfOfPlayerSize)
			player.setPosition(halfOfPlayerSize, player.getPosition().y);
		
		// Top window border colision
		if (player.getPosition().y <= 0 + halfOfPlayerSize)
			player.setPosition(player.getPosition().x, halfOfPlayerSize);
				
		// Right window border colision
		if (player.getPosition().x >= DEFAULT_WIDTH - halfOfPlayerSize)
			player.setPosition(DEFAULT_WIDTH - halfOfPlayerSize, player.getPosition().y);
				
		// Bottom window border colision
		if (player.getPosition().y >= DEFAULT_HEIGHT - halfOfPlayerSize)
			player.setPosition(player.getPosition().x, DEFAULT_HEIGHT - halfOfPlayerSize);
		
		window.clear(sf::Color(150, 150, 150));
		player.draw(window);

		// Collision by objects
		for (auto& i : walls)
			i.drawOnWindow(window);
			
		window.draw(nextBox);

		window.display();
	}

	GotoXY(100 / 2, 8);


	TextColor(WHITE);
	std::cout << "Game over";

	system("pause");

	return 0;
}