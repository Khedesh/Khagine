#ifndef SERVER_H
#define SERVER_H

#include <Khagine.hpp>
using namespace khagine;

class Server : public Entity
{
	bool busy;

	public:

	Server(bool b = false);

	bool get_busy();
	void set_busy(bool b);

}; // end class Server

// methods

#endif // SERVER_H
