#pragma once

class EventHandler;

class EventBase
{
public:
	EventBase(const EventHandler *sender) :
		m_sender{ sender }
	{}
	virtual ~EventBase()
	{}
private:
	const EventHandler *m_sender;
};
