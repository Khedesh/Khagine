// Name: entity.h
// Author: Khedesh
// Date: 02/08/2012, 5:47 PM
// Description: This file conatains class Entity.

#ifndef ENTITY_H
#define ENTITY_H

#include "logger.h"
#include <map>
#include <vector>
#include <string>

namespace khagine
{
	class EventQueue;
	class Clock;
	class Entity;

	typedef void(*Method)(Entity*);
	typedef std::map<std::string, Entity*> EntityMap;

	class Entity
	{
		std::vector<std::string> relatives;

		std::vector<Method> methods;

		EventQueue* event_queue;
		Clock* clock;
		EntityMap* main_entities;

		int id;
		static int entity_count;

		public:

		Entity(EventQueue* evt_queue = 0, Clock* m_clock = 0, EntityMap* em = 0);

		void connect(std::string name);
		void disconnect(std::string name);
		bool is_connected(std::string name);

		int add_method(Method mthd);
		Method get_method(int index);

		EventQueue* get_event_queue();
		void set_event_queue(EventQueue* eq);

		Clock* get_clock();
		void set_clock(Clock* m_clock);

		Entity* get_entity(std::string name);
		EntityMap* get_entity_map();
		void set_entity_map(EntityMap* map);

		int get_id();

	}; // end class Entity

} // end namespace khagine

#endif // ENTITY_H
