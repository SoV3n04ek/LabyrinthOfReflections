#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#define STANDARD_COUNT_ITEMS (3)
enum MENU_OPTIONS {PLAY, OPTIONS, EXIT };
/*
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
};*/

const std::string gameMenu = "Game Menu | Labyrinth of Reflecitons";

class Menu
{
private:
	size_t countItems;
	size_t indexSelectedItem;
	sf::Font font;
	std::vector<sf::Text> menuTexts;
public:
	Menu(float width = 1280, float height = 720, size_t choozedOption = 0)
	:
		indexSelectedItem(choozedOption),
		countItems(STANDARD_COUNT_ITEMS)
	{ 	
		if (!font.loadFromFile("fonts\\arial.ttf\0"))
		{ }
		const char* cstrs[STANDARD_COUNT_ITEMS] = {
			"Play", "Options", "Exit"
		};

		sf::Color red = sf::Color::Red;
		sf::Color white = sf::Color::White;
		sf::Text text;

		text.setFont(font);
		text.setCharacterSize(24);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		for (int i = 0; i < countItems; i++)
		{
			if (i == indexSelectedItem)
				text.setFillColor(red);
			else
				text.setFillColor(white);
		
			text.setString(cstrs[i]);
			text.setPosition(sf::Vector2f(width / 2, height / (STANDARD_COUNT_ITEMS + 1) * (i + 1)));
			menuTexts.push_back(text);
		}		
	}
	~Menu() { 	}

	Menu& setTextColor(size_t optionIndex, sf::Color color)
	{
		size_t i = 0;
		
		for (auto& text : menuTexts)
		{
			if (i == indexSelectedItem)
			{
				text.setFillColor(color);
				break;
			}
			++i;
		}

		return *this;
	}

	void down()
	{
		if (indexSelectedItem + 1 >= countItems)
			return;
		setTextColor(indexSelectedItem, sf::Color::White);
		++indexSelectedItem;
		setTextColor(indexSelectedItem, sf::Color::Red);
	}

	void up()
	{
		if (indexSelectedItem == 0)
			return;
		setTextColor(indexSelectedItem, sf::Color::White);
		--indexSelectedItem;
		setTextColor(indexSelectedItem, sf::Color::Red);
	}

	void addOption(sf::Text option) { menuTexts.push_back(option); }

	void addOption(const std::string& str, int x, int y)
	{
		countItems++;
		sf::Text option(str, font, 24);
		sf::Color color(sf::Color::White);
		option.setFillColor(color);
		menuTexts.push_back(option);
	}

	void draw(sf::RenderWindow &window)
	{
		for (auto &text : menuTexts)
			window.draw(text);
	}

	size_t getIndexSelectedItem() const { return indexSelectedItem;	}

	void setFillColor(size_t index, sf::Color color)
	{
		size_t i = 0;
		for (auto& text : menuTexts)
		{
			text.setFillColor(color);
			break;
		}		
	}

	Menu operator++(int)
	{
		Menu temp = *this;
		++*this;
		return temp;
	}

	Menu& operator++()
	{
		indexSelectedItem++;
		return *this;
	}

	Menu operator--(int)
	{
		Menu temp = *this;
		--*this;
		return temp;
	}

	Menu& operator--()
	{
		indexSelectedItem--;
		return *this;
	}
};