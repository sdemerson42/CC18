#pragma once

#include "EventHandler.h"

class CCState;

class ISystem : public EventHandler
{
public:
	ISystem(CCState *state) :
		m_state{ state }
	{}
	virtual ~ISystem()
	{}
	virtual void update() = 0;
protected:
	CCState *m_state;
};