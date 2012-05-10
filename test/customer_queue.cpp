#include "customer_queue.h"

CustomerQueue::CustomerQueue()
{
}

void CustomerQueue::push_customer(Customer* cus)
{
	customers.push(cus);
}

Customer* CustomerQueue::pop_customer()
{
	Customer* cus = customers.front();
	customers.pop();
	return cus;
}

bool CustomerQueue::is_empty()
{
	return customers.empty();
}

CustomerQueue::~CustomerQueue()
{
	int count = customers.size();
	for(int i = 0 ; i < count ; i ++)
	{
		delete customers.front();
		customers.pop();
	}
}
