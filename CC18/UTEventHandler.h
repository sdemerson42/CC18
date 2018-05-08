#pragma once

#include "EventBase.h"
#include "EventHandler.h"

#include <cassert>

namespace CCUT
{
	void handlesEventsProperly()
	{
		class IntEvent : public EventBase
		{
		public:
			IntEvent(const EventHandler *sender, int val) :
				EventBase{ sender }, m_val{ val }
			{}
			int val() const
			{
				return m_val;
			}
		private:
			int m_val;
		};

		class Alice : public EventHandler
		{
		public:
			Alice()
			{
				registerFunc(this, &Alice::onInt);
			}
			int val() const
			{
				return m_val;
			}
		private:
			void onInt(const IntEvent *e)
			{
				m_val = e->val();
			}
			int m_val{ 0 };
		};

		IntEvent e{ nullptr, 42 };
		Alice a;
		assert(a.val() != 42);
		a.handleEvent(&e);
		assert(a.val() == 42);
	}
}
