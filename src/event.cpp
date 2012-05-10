#include "event.h"
using namespace khagine;

int Event::event_count = 0;

Event::Event()
{
	time = 0;
	id = event_count ++;

	owner = NULL;
	method_index = 0;
}

Event::Event(int m_time, Entity* m_owner, int mthd_index)
{
	time = m_time;
	id = event_count ++;

	owner = m_owner;
	method_index = mthd_index;
}

int Event::get_time()
{
	return time;
}

void Event::set_time(int val)
{
	time = val;
}

int Event::get_id()
{
	return id;
}

Entity* Event::get_owner()
{
	return owner;
}

void Event::set_owner(Entity* m_owner)
{
	owner = m_owner;
}

int Event::get_method_index()
{
	return method_index;
}

void Event::set_method_index(int val)
{
	method_index = val;
}

void Event::operate()
{
	// emitting the function.
	owner->get_method(method_index)(owner);
}
