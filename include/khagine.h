// Name: khagine.h
// Author: Khedesh
// Date: 02/06/2012, 5:19 PM

#ifndef KHAGINE_H
#define KHAGINE_H

#include "logger.h"
#include "clock.h"
#include "event.h"
#include "event_queue.h"
#include "entity.h"

namespace khagine
{
	class Khagine
	{
		EventQueue* event_queue;
		EntityMap entities;
		Clock* clock;

		public:

		Khagine();
		Khagine(int argc, char* argv[]);

		void init(int argc, char* argv[]);

		void step(bool& running);

		void push_event(Event* evt);

		void add_entity(std::string name, Entity* m_entity);

		void delete_entity(std::string name);

		float get_time();

		~Khagine();

	}; // end class Khagine

} // end namespace khagine

#endif // KHAGINE_H
