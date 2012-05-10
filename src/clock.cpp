#include "clock.h"
using namespace khagine;

Clock::Clock()
{
	time = 0;
}

Clock::Clock(float m_time)
{
	time = m_time;
}

float Clock::get_time()
{
	return time;
}

void Clock::set_time(float m_time)
{
	time = m_time;
}

float Clock::increase()
{
	return ++ time;
}

float Clock::decrease()
{
	return -- time;
}
