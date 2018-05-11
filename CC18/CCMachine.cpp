#include "CCMachine.h"
#include "CloseAppEvent.h"

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

			for (auto &up : m_system)
				up->update();

			if (m_isClosing) m_window.close();
		}
	}
}

void CCMachine::onCloseApp(const CloseAppEvent *event)
{
	m_isClosing = true;
}