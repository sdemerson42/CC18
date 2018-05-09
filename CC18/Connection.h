#pragma once

#include "Bubble.h"
#include <memory>

class Connection
{
public:
	Connection(std::shared_ptr<Bubble> &first, std::shared_ptr<Bubble> &second)
	{
		m_bubble[0] = first;
		m_bubble[1] = second;
	}
	const std::shared_ptr<Bubble> *bubble()
	{
		return m_bubble;
	}
private:
	std::shared_ptr<Bubble> m_bubble[2];
};