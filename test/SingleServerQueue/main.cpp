#include <Khagine.hpp>
using namespace khagine;
using namespace std;

#include "server.h"
#include "customer.h"
#include "customer_queue.h"

void init_simulation(Khagine* khg)
{
	Server* server = new Server;
	CustomerQueue* cq = new CustomerQueue;
	Customer* first_cus = new Customer(10, 0);

	khg->add_entity("server", server);
	khg->add_entity("queue", cq);
	khg->add_entity("customer", first_cus);

	Event* first_arr_evt = new Event(0, first_cus, 0);
	khg->push_event(first_arr_evt);
}

int main(int argc, char* argv[])
{
	// allocating a khagine instance.
	Khagine* khg = new Khagine(argc, argv);

	bool running = true;

	init_simulation(khg);
	srand(time(0));

	while(running)
	{
		Logger::inst()->log(KLT_OUTPUT) << "-------------------------------------------" << endl;
		//Logger::inst()->log(KLT_OUTPUT) << "Time: " << khg->get_time() << endl;

		if(khg->get_time() >= 20000)
		{
			running = false;
		}

		// stepping the khagine...
		khg->step(running);
	}

	// deleting khagine
	delete khg;

	// deleting logger
	delete Logger::inst();

	return 0;
}
