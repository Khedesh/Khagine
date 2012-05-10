#include "khagine.h"
using namespace khagine;

Khagine::Khagine()
{
	event_queue = new EventQueue;
	clock = new Clock;

	entities.clear();
}

Khagine::Khagine(int argc, char* argv[])
{
	event_queue = new EventQueue;
	clock = new Clock;

	entities.clear();

	init(argc, argv);
}

void Khagine::init(int argc, char* argv[])
{
	// we enter this part of code later.
}

void Khagine::step(bool& running)
{
	// test is there any event in the queue!
	// if not go out.
	if(event_queue->is_empty() == true)
	{
		Logger::inst()->log(KLT_ERROR) << "Khagine: There isn't any events in the queue." << std::endl;
		Logger::inst()->log(KLT_ERROR) << "Khagine: Quit!" << std::endl;
		running = false;
		return;
	}

	// getting an event from the queue
	Event* evt = event_queue->pop_event();

	// advance the clock.
	clock->set_time(evt->get_time());

	// applying the event
	evt->operate();

	// deleting the events.
	delete evt;
}

void Khagine::push_event(Event* evt)
{
	event_queue->push_event(evt);
}

void Khagine::add_entity(std::string name, Entity* m_entity)
{
	entities[name] = m_entity;

	m_entity->set_event_queue(event_queue);
	m_entity->set_clock(clock);
	m_entity->set_entity_map(&entities);
}

void Khagine::delete_entity(std::string name)
{
	delete entities[name];
	entities.erase(name);
}

float Khagine::get_time()
{
	return clock->get_time();
}

Khagine::~Khagine()
{
	for(EntityMap::const_iterator it = entities.begin() ; it != entities.end() ; ++ it)
	{
		delete it->second;
	}
}
