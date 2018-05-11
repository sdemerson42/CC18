#pragma once

#include "EventBase.h"
#include "AutoList.h"
#include <map>
#include <typeindex>
#include <memory>
#include "Events.h"

template<typename T, typename EventT>
using Delegate = void(T::*)(const EventT *);

class IFuncWrapper
{
public:
	virtual void call(const EventBase *) = 0;
};

template<typename T, typename EventT>
class FuncWrapper : public IFuncWrapper
{
public:
	FuncWrapper(T *instance, Delegate<T, EventT> func) :
		m_instance{ instance }, m_delegate{ func }
	{}
	void call(const EventBase *event) override
	{
		(m_instance->*m_delegate)(static_cast<const EventT *>(event));
	}
private:
	T *m_instance;
	Delegate<T, EventT> m_delegate;
};

class EventHandler : public AutoList<EventHandler>
{
public:
	template<typename T, typename EventT>
	void registerFunc(T *instance, Delegate<T, EventT> func)
	{
		m_wrapperMap[std::type_index{ typeid(EventT) }] = std::make_unique<FuncWrapper<T, EventT>>(instance, func);
	}
	void handleEvent(const EventBase *);
	void broadcastEvent(const EventBase *);
private:
	std::map<std::type_index, std::unique_ptr<IFuncWrapper>> m_wrapperMap;
};