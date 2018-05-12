#include "RenderSystem.h"
#include "CCState.h"

void RenderSystem::update()
{

	m_window->clear(sf::Color::Blue);

	sf::VertexArray va;
	va.setPrimitiveType(sf::PrimitiveType::Quads);

	sf::VertexArray va2;
	va2.setPrimitiveType(sf::PrimitiveType::Lines);

	for (const auto &con : m_state->connection())
	{
		va2.append(sf::Vertex{ sf::Vector2f{ con->bubble()[0]->position().x + 50.0f, con->bubble()[0]->position().y + 50.0f} });
		va2.append(sf::Vertex{ sf::Vector2f{ con->bubble()[1]->position().x + 50.0f, con->bubble()[1]->position().y + 50.0f } });
	}

	for (const auto &bb : m_state->bubble())
	{
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x, bb->position().y } });
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x + bb->size().x, bb->position().y } });
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x + bb->size().x, bb->position().y + bb->size().y } });
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x, bb->position().y + bb->size().y } });
	}
	
	if (m_isConnecting)
	{
		sf::VertexArray curCon;
		curCon.setPrimitiveType(sf::PrimitiveType::Lines);
		curCon.append(sf::Vertex{ sf::Vector2f{(float)m_connectionStartPoint.x, (float)m_connectionStartPoint.y } });
		curCon.append(sf::Vertex{ sf::Vector2f{(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y} });
		m_window->draw(curCon);
	}

	
	m_window->draw(va2);
	m_window->draw(va);
	m_window->display();
}

void RenderSystem::onConnectionClick(const ConnectionClickEvent *event)
{
	if (!m_isConnecting)
	{
		m_connectionStartPoint = event->startPos;
		m_isConnecting = true;
	}
	else
	{
		m_isConnecting = false;
	}
}