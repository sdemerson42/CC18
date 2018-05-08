#pragma once

#include "Bubble.h"
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
			m_bubble.push_back(std::make_unique<Bubble>());
			m_bubble[m_bubble.size() - 1]->setPosition(x, y);
		}
	}
	const std::vector<std::unique_ptr<Bubble>> &bubble() const
	{
		return m_bubble;
	}
private:
	std::vector<std::unique_ptr<Bubble>> m_bubble;
};