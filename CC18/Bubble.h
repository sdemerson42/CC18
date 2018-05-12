#pragma once

#include <string>
#include "SFML\Graphics.hpp"
#include "EventHandler.h"

class Bubble : public EventHandler, public AutoList<Bubble>
{
public:
	sf::Vector2f size() const
	{
		return sf::Vector2f{ 100.0f, 100.0f };
	}
	void setPosition(float x, float y)
	{
		m_position.x = x;
		m_position.y = y;
	}
	void setPosition(const sf::Vector2f &v)
	{
		setPosition(v.x, v.y);
	}
	const sf::Vector2f &position() const
	{
		return m_position;
	}
private:
	std::string m_name;
	sf::Vector2f m_position;
	sf::Vector2f m_texturePosition;
};