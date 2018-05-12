#pragma once

#include "EventBase.h"
#include "SFML\Graphics.hpp"

class Bubble;

class ConnectionClickEvent : public EventBase
{
public:
	ConnectionClickEvent(EventHandler *sender) :
		EventBase{ sender }
	{}
	sf::Vector2i startPos;
	Bubble *startBubble;
};
