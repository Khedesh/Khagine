#ifndef CUSTOMER_QUEUE_H
#define CUSTOMER_QUEUE_H

#include <Khagine.hpp>
using namespace khagine;

#include <queue>
using namespace std;

#include "customer.h"

class Customer;

class CustomerQueue : public Entity
{
	queue<Customer*> customers;

	public:

	CustomerQueue();

	void push_customer(Customer* cus);
	Customer* pop_customer();
	bool is_empty();

	~CustomerQueue();
};

// methods

#endif // CUSTOMER_QUEUE_H
