#include "server.h"

Server::Server(bool b)
{
	set_busy(b);
}

bool Server::get_busy()
{
	return busy;
}

void Server::set_busy(bool b)
{
	busy = b;
}

/*
// methods
void OnServerBusy(Entity* srv)
{
	((Server*)srv)->set_busy(true);
}

void OnServerIdle(Entity* srv)
{
	((Server*)srv)->set_busy(false);
}*/
