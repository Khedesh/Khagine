#include "entity.h"
using namespace khagine;

int Entity::entity_count = 0;

Entity::Entity(EventQueue* evt_queue, Clock* m_clock, EntityMap* em)
{
	event_queue = evt_queue;
	clock = m_clock;
	main_entities = em;

	id = entity_count ++;
}

void Entity::connect(std::string name)
{
	relatives.push_back(name);
}

void Entity::disconnect(std::string name)
{
	for(unsigned i = 0 ; i < relatives.size() ; i ++)
	{
		if(relatives[i] == name)
		{
			relatives.erase(relatives.begin() + i);
		}
	}
}

bool Entity::is_connected(std::string name)
{
	for(unsigned i = 0 ; i < relatives.size() ; i ++)
	{
		if(relatives[i] == name)
		{
			return true;
		}
	}

	return false;
}

int Entity::add_method(Method mthd)
{
	methods.push_back(mthd);
	return methods.size() - 1;
}

Method Entity::get_method(int index)
{
	if(methods[index] > 0)
		return methods[index];
	else
	{
		Logger::inst()->log(KLT_ERROR) << "Khagine: The Entity (ID=" << id << ") doesn't have such method (index=" << index << ").\n";
		return 0;
	}
}

EventQueue* Entity::get_event_queue()
{
	return event_queue;
}

void Entity::set_event_queue(EventQueue* evt_queue)
{
	event_queue = evt_queue;
}

Clock* Entity::get_clock()
{
	return clock;
}

void Entity::set_clock(Clock* m_clock)
{
	clock = m_clock;
}

Entity* Entity::get_entity(std::string name)
{
	if(is_connected(name))
		return main_entities->operator[](name);
	else
		return NULL;
}

EntityMap* Entity::get_entity_map()
{
	return main_entities;
}

void Entity::set_entity_map(EntityMap* map)
{
	main_entities = map;
}

int Entity::get_id()
{
	return id;
}
