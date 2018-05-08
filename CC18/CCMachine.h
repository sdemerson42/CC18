#pragma once

#include "SFML\Graphics.hpp"

class CCMachine
{
public:
	CCMachine() :
		m_window{ sf::VideoMode{800, 600}, "CCMachine" }
	{
	}
	void execute();

private:
	sf::RenderWindow m_window;
};