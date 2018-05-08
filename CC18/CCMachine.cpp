#include "CCMachine.h"

void CCMachine::execute()
{

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			// Main execution loop

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				m_window.close();

			for (auto &up : m_system)
				up->update();
		}
	}
}