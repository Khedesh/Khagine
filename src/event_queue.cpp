#include "event_queue.h"
using namespace khagine;

EventQueue::EventQueue()
{
}

void EventQueue::push_event(Event* evt)
{
	evt_queue.push(evt);
}

Event* EventQueue::pop_event()
{
	Event* m_evt = evt_queue.top();
	evt_queue.pop();
	return m_evt;
}

bool EventQueue::is_empty()
{
	return evt_queue.empty();
}
