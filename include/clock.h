// Name: clock.h
// Author: Khedesh
// Date: 02/08/2012, 4:57 PM
// Description: This file contains clock class for handling time in our engine.

#ifndef CLOCK_H
#define CLOCK_H

namespace khagine
{
	class Clock
	{
		float time;

		public:

		Clock();
		Clock(float m_time);

		float get_time();
		void set_time(float m_time);

		float increase();
		float decrease();

	}; // end class Clock

} // end namespace khagine

#endif // CLOCK_H
