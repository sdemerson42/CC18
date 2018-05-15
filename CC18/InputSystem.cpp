#include "InputSystem.h"
#include "CloseAppEvent.h"
#include "ConnectionClickEvent.h"
#include "Bubble.h"
#include <iostream>

void InputSystem::update()
{
	auto mPos = sf::Mouse::getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		CloseAppEvent e{ this };
		broadcastEvent(&e);
	}

	
}