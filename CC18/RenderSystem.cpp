#include "RenderSystem.h"
#include "CCState.h"

void RenderSystem::update()
{
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
	

	m_window->clear(sf::Color::Blue);
	m_window->draw(va2);
	m_window->draw(va);
	m_window->display();
}