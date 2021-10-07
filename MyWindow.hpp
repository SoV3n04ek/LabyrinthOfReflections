#pragma once
#include <SFML/Graphics.hpp>
#include "Config.hpp"

class MyWindow
{
	sf::RenderWindow window;
	Config* config;
	
public:
	MyWindow(sf::VideoMode vmode, std::string windowTitle, int style) 
	: 
		window(vmode, windowTitle, style)
	{
		config = new Config();
	}
	~MyWindow() { delete config; }

	/*
	* Get the current config
	*/
	Config* getConfig() const { return config; }


};