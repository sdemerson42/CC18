#pragma once

#include "ISystem.h"
#include "SFML\Graphics.hpp"

class Bubble;

class InputSystem : public ISystem
{
public:
	InputSystem(CCState *state) :
		ISystem{ state }
	{}
	void update() override;
private:
	sf::Vector2i m_lastMousePosition;
	Bubble *m_selectedBubble{ nullptr };
	sf::Clock m_clock;
	sf::Int32 m_clickTime;
	bool m_isConnecting{ false };
};