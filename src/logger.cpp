#include "logger.h"

Logger* Logger::logger_singleton = NULL;

Logger::Logger()
{
}

std::ostream& Logger::log(KLogType type)
{
	if(type == KLT_ERROR)
		return std::cerr;
	else
		return std::cout;
}

Logger* Logger::inst()
{
	if(logger_singleton == NULL)
	{
		logger_singleton = new Logger();
	}

	return logger_singleton;
}
