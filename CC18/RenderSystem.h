#pragma once

#include "ISystem.h"
#include "SFML\Graphics.hpp"
#include "ConnectionClickEvent.h"

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
	sf::Vector2i m_connectionStartPoint;
	bool m_isConnecting{ false };

	void onConnectionClick(const ConnectionClickEvent *event);
};