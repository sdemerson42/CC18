#pragma once

#include <string>
#include "SFML\Graphics.hpp"

class Bubble
{
public:

	sf::Vector2f size() const
	{
		return sf::Vector2f{ 64.0f, 64.0f };
	}
private:
	std::string m_name;
	sf::Vector2f m_position;
	sf::Vector2f m_texturePosition;
};