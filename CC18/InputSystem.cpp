#include "InputSystem.h"
#include "SFML\Graphics.hpp"
#include "CloseAppEvent.h"

void InputSystem::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		CloseAppEvent e{ this };
		broadcastEvent(&e);
	}
}