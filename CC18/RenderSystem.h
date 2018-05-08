#pragma once

#include "ISystem.h"
#include "SFML\Graphics.hpp"

class CCState;

class RenderSystem : public ISystem
{
public:
	RenderSystem(CCState *state, sf::RenderWindow *window) :
		ISystem{ state }, m_window{ window }
	{}
	void update() override;
private:
	sf::RenderWindow *m_window;
};