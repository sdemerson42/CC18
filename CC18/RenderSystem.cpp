#include "RenderSystem.h"
#include "CCState.h"

void RenderSystem::update()
{
	sf::VertexArray va;
	va.setPrimitiveType(sf::PrimitiveType::Quads);

	for (const auto &bb : m_state->bubble())
	{
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x, bb->position().y } });
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x + bb->size().x, bb->position().y } });
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x + bb->size().x, bb->position().y + bb->size().y } });
		va.append(sf::Vertex{ sf::Vector2f{ bb->position().x, bb->position().y + bb->size().y } });
	}
	

	m_window->clear(sf::Color::Blue);
	m_window->draw(va);
	m_window->display();
}