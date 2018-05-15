#include "RenderSystem.h"
#include "CCState.h"
#include "RenderState.h"

#include <algorithm>

void RenderSystem::update()
{
	package();
	render();
}

void RenderSystem::package()
{

	m_back.clear();
	m_mid.clear();
	m_front.clear();

	for (auto i = 0; i < AutoList<RenderState>::size(); ++i)
	{
		// Load textures

		RenderState *rs = AutoList<RenderState>::get(i);
		std::string fName = rs->textureName;
		auto p = m_textureMap.find(fName);
		if (p == end(m_textureMap))
		{
			m_textureMap[fName] = sf::Texture{};
			m_textureMap[fName].loadFromFile(fName);
		}

		// Update RenderPacks

		if (!rs->active) return;

		std::vector<RenderPack> *vec = [&]()
		{
			if (rs->layer == RenderState::RenderLayer::Back)
				return &m_back;
			if (rs->layer == RenderState::RenderLayer::Mid)
				return &m_mid;
			return &m_front;
		}();

		// Find matching RenderPack, or point to a new one.

		RenderPack temp;
		RenderPack *pack = &temp;
		auto pIter = std::find_if(begin(*vec), end(*vec), [&](RenderPack &rp)
		{
			return rp.states.texture == &m_textureMap.find(rs->textureName)->second
				&& abs(rp.scale - rs->scale) < 0.01f && rp.pType == rs->primitive;
		});
		if (pIter == end(*vec))
		{
			pack->scale = rs->scale;
			if (abs(pack->scale - 1.0f) > .01)
				pack->states.transform.scale(pack->scale, pack->scale);
			pack->states.texture = &m_textureMap.find(rs->textureName)->second;
			pack->pType = rs->primitive;
			pack->va.setPrimitiveType(pack->pType);
			vec->push_back(*pack);
			pack = &(*vec)[vec->size() - 1];
		}
		else
		{
			pack = pIter._Ptr;
		}

		// Fill va;

		sf::VertexArray *v = &pack->va;

		if (pack->pType == sf::PrimitiveType::Lines)
		{
			sf::Vertex vert;
			vert.position = rs->position;
			v->append(vert);
			vert.position = rs->position + rs->size;
			v->append(vert);
		}

		if (pack->pType == sf::PrimitiveType::Quads)
		{
			sf::Vertex vert;
			vert.position = rs->position;
			vert.texCoords = rs->textureCoords;
			v->append(vert);
			vert.position = sf::Vector2f{ rs->position.x + rs->size.x, rs->position.y };
			vert.texCoords = sf::Vector2f{ rs->position.x + rs->size.x, rs->position.y };
			v->append(vert);
			vert.position = sf::Vector2f{ rs->position.x + rs->size.x, rs->position.y + rs->size.y };
			vert.texCoords = sf::Vector2f{ rs->position.x + rs->size.x, rs->position.y + rs->size.y };
			v->append(vert);
			vert.position = sf::Vector2f{ rs->position.x, rs->position.y + rs->size.y };
			vert.texCoords = sf::Vector2f{ rs->position.x, rs->position.y + rs->size.y };
			v->append(vert);
		}

	}
}

void RenderSystem::render()
{
	m_window->clear(sf::Color::Blue);

	for (auto &rp : m_back)
	{
		m_window->draw(rp.va, rp.states);
	}
	for (auto &rp : m_mid)
	{
		m_window->draw(rp.va, rp.states);
	}
	for (auto &rp : m_front)
	{
		m_window->draw(rp.va, rp.states);
	}

	m_window->display();
}

void RenderSystem::onConnectionClick(const ConnectionClickEvent *event)
{
	// Temp?
}