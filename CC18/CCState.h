#pragma once

#include "Bubble.h"
#include "Connection.h"
#include <memory>
#include <vector>

class CCState
{
public:
	CCState()
	{
		// Temporary test data construction

		float y = 5.0f;
		for (int i = 0; i < 40; ++i)
		{
			float x;
			x = float(i % 10 * 100 + 80 * (i % 10) + 40);
			if (i % 10 == 0) y += 180;
			m_bubble.push_back(std::make_shared<Bubble>());
			x += rand() % 40 - 20;
			y += rand() % 40 - 20;
			Bubble *ref = m_bubble[m_bubble.size() - 1].get();
			ref->setPosition(x, y);
			ref->renderState().layer = RenderState::RenderLayer::Mid;
			ref->renderState().size = ref->size();
		}
	}
	const std::vector<std::shared_ptr<Bubble>> &bubble() const
	{
		//temp
		return m_bubble;
	}
	const std::vector<std::unique_ptr<Connection>> &connection() const
	{
		//temp
		return m_connection;
	}
private:
	std::vector<std::shared_ptr<Bubble>> m_bubble;
	std::vector<std::unique_ptr<Connection>> m_connection;
};