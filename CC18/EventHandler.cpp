#include "EventHandler.h"

void EventHandler::handleEvent(const EventBase *event)
{
	auto wrapper = m_wrapperMap.find(std::type_index{ typeid(*event) });
	if (wrapper != end(m_wrapperMap))
	{
		wrapper->second->call(event);
	}
}

void EventHandler::broadcastEvent(const EventBase *event)
{
	for (auto i = 0; i < AutoList<EventHandler>::size(); ++i)
	{
		EventHandler *handler = AutoList<EventHandler>::get(i);
		if (handler != this)
			handler->handleEvent(event);
	}
}