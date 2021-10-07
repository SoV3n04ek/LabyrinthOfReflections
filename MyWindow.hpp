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
	void clear(sf::Color color)
	{
		window.clear(color);
	}

	sf::RenderWindow& getRenderWindow() { return window; }

	void close() { window.close(); }
	

	bool pollEvent(sf::Event& evnt) { return window.pollEvent(evnt); }
	void display() { window.display(); }
	void setFramerateLimit(unsigned int limit) { window.setFramerateLimit(limit); }
	
	template <class T>
	void draw(T& item) { window.draw(item); }
	bool isOpen() const { return window.isOpen();  }
	
	void setIcon(unsigned int width, unsigned int height, const sf::Uint8 *pixels) { window.setIcon(width, height, pixels); }

	Config* getConfig() const { return config; }
};