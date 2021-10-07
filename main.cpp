#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Game.hpp"

int main()
{
	srand(time(0));
		
	/*
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			menu.down();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			menu.up();	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			if (menu.getIndexSelectedItem() == PLAY)
			{
				return 0;
			}
			if (menu.getIndexSelectedItem() == OPTIONS)
			{
				return 0;
			}
			if (menu.getIndexSelectedItem() == EXIT)
				return 0;
		}
		//sf::sleep(sf::milliseconds(140));
		window.clear(sf::Color::Black);
		menu.draw(window);
		window.display();
	}
	*/
	gm::Game game;
	game.start();
	system("pause");
}