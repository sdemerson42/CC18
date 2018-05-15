#pragma once

#include <string>
#include "SFML\Graphics.hpp"
#include "EventHandler.h"
#include "RenderState.h"

class Bubble : public EventHandler, public AutoList<Bubble>
{
public:
	Bubble()
	{
		//m_renderState.textureName = "Test.png";
	}
	sf::Vector2f size() const
	{
		return sf::Vector2f{ 100.0f, 100.0f };
	}
	void setPosition(float x, float y)
	{
		m_renderState.position.x = x;
		m_renderState.position.y = y;
	}
	void setPosition(const sf::Vector2f &v)
	{
		setPosition(v.x, v.y);
	}
	const sf::Vector2f &position() const
	{
		return m_renderState.position;
	}
	RenderState &renderState()
	{
		return m_renderState;
	}
private:
	RenderState m_renderState;
};