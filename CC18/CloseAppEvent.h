#pragma once

#include "EventBase.h"

class CloseAppEvent : public EventBase
{
public:
	CloseAppEvent(EventHandler *sender) :
		EventBase{ sender }
	{}

};