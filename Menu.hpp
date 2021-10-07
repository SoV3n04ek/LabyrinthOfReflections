#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#define MAX_COUNT_ITEMS (3)

struct Text
{
	std::string str;
	int x, y;
	Text()
		:
		str(""),
		x(0),
		y(x)
	{ }
	Text(const std::string& str, int x, int y)
		:
		str(str),
		x(x),
		y(y)
	{ }
	Text(const char* cstr, int x, int y)
		:
		str(std::string(cstr)),
		x(x),
		y(y)
	{ }

	void setString(const char* cstr)
	{
		str = std::string(cstr);
	}
	void setString(const std::string &str)
	{
		this->str = str;
	}
};

class Menu
{
private:
	size_t indexselectedItem;
	sf::Font font;
public:
	sf::Text text[MAX_COUNT_ITEMS];
	Menu(float width, float height, size_t choozedOption = 0)
	:
		indexselectedItem(choozedOption)
	{ 	
		//if (!font.loadFromFile("arial.ttf"))
		//{
		//	// ошибка...
		//}
		/*if (!font.loadFromFile("fonts\\arial.ttf"))
		{ }*/
		const char* cstrs[MAX_COUNT_ITEMS] = {
			"Play", "Options", "Exit"
		};

		sf::Color red = sf::Color::Red;
		sf::Color white = sf::Color::White;

		for (int i = 0; i < MAX_COUNT_ITEMS; i++)
		{
			text[i].setFont(font);
			if (i == indexselectedItem)
				text[i].setFillColor(red);
			else
				text[i].setFillColor(white);
			text[i].setCharacterSize(24); 
			text[i].setString(cstrs[i]);
			text[i].setPosition(sf::Vector2f(width / 2, height / (MAX_COUNT_ITEMS + 1) * (i+1)));
			text[i].setStyle(sf::Text::Bold | sf::Text::Underlined);
		}		

	}
	~Menu() { 	}

	Menu& voidSetOption(size_t option)
	{
		indexselectedItem = option;
		return *this;
	}

	/*void addOption(Text option)
	{
		options.push_back(option);
	}
	void addOption(const std::string& str, int x, int y)
	{
		Text option(str, x, y);
		options.push_back(option);
	}*/

	void draw(sf::RenderWindow &window)
	{
		for (int i = 0; i < MAX_COUNT_ITEMS; i++)
			window.draw(text[i]);
	}

	void printMenu() const
	{
	/*	size_t option = 0;
		for (auto it = options.begin(); it != options.end(); it++, option++) {
			GotoXY(it->x, it->y);
			if (option == choozedOption)
			{
				TextColor(YELLOW);
			}

			std::cout << it->str << std::endl;

			TextColor(LIGHTGRAY);
		}*/
	}
};