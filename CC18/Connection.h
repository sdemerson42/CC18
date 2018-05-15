#pragma once

#include "Bubble.h"
#include <memory>
#include "RenderState.h"

class Connection
{
public:
	Connection(std::shared_ptr<Bubble> &first, std::shared_ptr<Bubble> &second)
	{
		m_bubble[0] = first;
		m_bubble[1] = second;
		m_renderState.layer = RenderState::RenderLayer::Back;
		m_renderState.position = sf::Vector2f{ m_bubble[0]->position().x + m_bubble[0]->size().x / 2, m_bubble[0]->position().y + m_bubble[0]->size().y / 2 };
		m_renderState.primitive = sf::PrimitiveType::Lines;
		m_renderState.size = sf::Vector2f{ m_bubble[1]->position().x + m_bubble[1]->size().x / 2, m_bubble[1]->position().y + m_bubble[1]->size().y / 2 };
	}
	const std::shared_ptr<Bubble> *bubble()
	{
		return m_bubble;
	}
private:
	std::shared_ptr<Bubble> m_bubble[2];
	RenderState m_renderState;
};