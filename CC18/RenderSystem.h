#pragma once

#include "ISystem.h"
#include "SFML\Graphics.hpp"
#include "ConnectionClickEvent.h"

#include <vector>
#include <map>
#include <string>

class CCState;

class RenderSystem : public ISystem
{
public:
	RenderSystem(CCState *state, sf::RenderWindow *window) :
		ISystem{ state }, m_window{ window }
	{
		registerFunc(this, &RenderSystem::onConnectionClick);
	}
	void update() override;
private:
	sf::RenderWindow *m_window;
	void onConnectionClick(const ConnectionClickEvent *event);
	std::map<std::string, sf::Texture> m_textureMap;

	struct RenderPack
	{
		sf::VertexArray va;
		sf::RenderStates states;
		float scale = 1.0f;
		sf::PrimitiveType pType;
	};

	std::vector<RenderPack> m_back;
	std::vector<RenderPack> m_mid;
	std::vector<RenderPack> m_front;

	void package();
	void render();
};