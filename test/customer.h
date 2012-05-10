#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <Khagine.hpp>
using namespace khagine;

#include "customer_queue.h"
#include "server.h"

class Customer : public Entity
{
	int service_time;
	int arrive_time;

	public:

	Customer(int srv_time = 0, int arr_time = 0);

	int get_service_time();
	int get_arrive_time();
};

// methods

void OnCustomerArrival(Entity* cus);
void OnCustomerDeparture(Entity* cus);

#endif // CUSTOMER_H
