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

			m_window.clear(sf::Color::Blue);
			m_window.display();
		}
	}
}