// Name: event.h
// Author: Khedesh
// Date: 02/04/2012, 5:35 PM

#ifndef EVENT_H
#define EVENT_H

#include <stdlib.h>
#include "entity.h"

namespace khagine
{
	class Event
	{
		static int event_count;

		int time;
		int id;

		Entity* owner;
		int method_index;

		public:

		Event();
		Event(int m_time, Entity* m_owner, int mthd_index);

		int get_time();
		void set_time(int val);

		int get_id();

		Entity* get_owner();
		void set_owner(Entity* m_owner);

		int get_method_index();
		void set_method_index(int val);

		void operate();
	}; // end class Event

} // end namespace Khagine

#endif // EVENT_H
