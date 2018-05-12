#include "InputSystem.h"
#include "CloseAppEvent.h"
#include "ConnectionClickEvent.h"
#include "Bubble.h"
#include <iostream>

void InputSystem::update()
{
	auto mPos = sf::Mouse::getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		CloseAppEvent e{ this };
		broadcastEvent(&e);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!m_selectedBubble && !m_isConnecting)
		{
			for (auto i{ 0 }; i < AutoList<Bubble>::size(); ++i)
			{
				Bubble *b = AutoList<Bubble>::get(i);
				int l = b->position().x;
				int t = b->position().y;
				int r = l + b->size().x;
				int bt = t + b->size().y;

				if (mPos.x > l && mPos.x < r && mPos.y > t && mPos.y < bt)
				{
					m_selectedBubble = b;
					m_clock.restart();
					break;
				}
			}
		}
		else
		{
			sf::Vector2i delta = mPos - m_lastMousePosition;
			m_selectedBubble->setPosition(sf::Vector2f{ m_selectedBubble->position().x + delta.x, m_selectedBubble->position().y + delta.y });
		}
	}
	else
	{
		if (m_selectedBubble)
		{
			if (m_clock.getElapsedTime().asMilliseconds() > 400)
			{
				m_selectedBubble = nullptr;
			}
			else
			{
				if (!m_isConnecting)
				{
					// Select first connection Bubble
					m_isConnecting = true;
					ConnectionClickEvent e{ this };
					e.startPos = sf::Vector2i{ int(m_selectedBubble->position().x + m_selectedBubble->size().x / 2),
						int(m_selectedBubble->position().y + m_selectedBubble->size().y / 2) };
					broadcastEvent(&e);
				}
				else
				{
					// select second connection Bubble
					Bubble *secondSelection = nullptr;
					for (auto i{ 0 }; i < AutoList<Bubble>::size(); ++i)
					{
						Bubble *b = AutoList<Bubble>::get(i);
						int l = b->position().x;
						int t = b->position().y;
						int r = l + b->size().x;
						int bt = t + b->size().y;

						if (mPos.x > l && mPos.x < r && mPos.y > t && mPos.y < bt)
						{
							secondSelection = b;
							m_clock.restart();
							break;
						}
					}
					if (secondSelection && secondSelection != m_selectedBubble)
					{
						m_isConnecting = false;
						m_selectedBubble = nullptr;
						ConnectionClickEvent e{ this };
						broadcastEvent(&e);
					}
				}
			}
		}
		
	}
	m_lastMousePosition = mPos;
}