#pragma once

#include "SFML\Graphics.hpp"
#include "CCState.h"
#include <memory>
#include <vector>

#include "RenderSystem.h"

class CCMachine
{
public:
	CCMachine() :
		m_window{ sf::VideoMode{1920, 1200}, "CCMachine", sf::Style::Fullscreen },
		m_state{ std::make_unique<CCState>() }
	{
		m_system.push_back(std::make_unique<RenderSystem>(m_state.get(), &m_window));
	}
	void execute();

private:
	sf::RenderWindow m_window;
	std::unique_ptr<CCState> m_state;
	std::vector<std::unique_ptr<ISystem>> m_system;
};