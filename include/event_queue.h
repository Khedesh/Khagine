// Name: event_queue.h
// Author: Khedesh
// Date: 02/08/2012, 5:06 PM

#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <queue>
#include "event.h"

namespace khagine
{
	class CompareEvent
	{
		public:

		bool operator()(Event* e1, Event* e2)
		{
			return e1->get_time() > e2->get_time();
		}
	};

	class EventQueue
	{
		std::priority_queue<Event*, std::vector<Event*>, CompareEvent> evt_queue;

		public:

		EventQueue();

		void push_event(Event* evt);
		Event* pop_event();

		bool is_empty();
	};

} // end namespace khagine

#endif // EVENT_QUEUE_H
