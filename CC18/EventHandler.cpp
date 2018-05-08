#include "EventHandler.h"

void EventHandler::handleEvent(const EventBase *event)
{
	auto wrapper = m_wrapperMap.find(std::type_index{ typeid(*event) });
	if (wrapper != end(m_wrapperMap))
	{
		wrapper->second->call(event);
	}
}