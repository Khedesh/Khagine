// Name: logger.h
// Author: Khedesh
// At: 01/28/2012, 6:38 PM
// Description: This file contains Logger class of the Engine and singleton.

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

enum KLogType
{
	KLT_OUTPUT = 0,
	KLT_ERROR = 1
};

class Logger
{
	// this is the singleton
	static Logger* logger_singleton;

	public:

	Logger();

	std::ostream& log(KLogType type);

	// singleton getter
	static Logger* inst();

};

#endif // LOGGER_H
