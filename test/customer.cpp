#include "customer.h"

Customer::Customer(int srv_time, int arr_time)
{
	service_time = srv_time;
	arrive_time = arr_time;

	int method = add_method(OnCustomerArrival);
	method = add_method(OnCustomerDeparture);
	//Logger::inst()->log(KLT_OUTPUT) << "Method of Departure: " << method << "." << endl;

	// it is not standard...
	connect("server");
	connect("queue");
}

int Customer::get_service_time()
{
	return service_time;
}

int Customer::get_arrive_time()
{
	return arrive_time;
}

void OnCustomerArrival(Entity* cus) // ----> 0
{
	// variables
	Server* server = (Server*)(cus->get_entity("server"));
	CustomerQueue* cq = (CustomerQueue*)(cus->get_entity("queue"));
	Customer* this_cus = (Customer*)cus;

	Logger::inst()->log(KLT_OUTPUT) << "Customer time: " << this_cus->get_clock()->get_time() << endl;
	
	// the next customer...
	NormalDistribution nd(50, 10);
	int inter_arr_time = rand() % 50 + 5;
	int next_srv_time = int(nd.generate());
	
	Logger::inst()->log(KLT_OUTPUT) << "Customer arrived! , ID: " << this_cus->get_id() << "." << endl;
	Logger::inst()->log(KLT_OUTPUT) << "Service Time: " << this_cus->get_service_time() << endl;

	// initializing next_cus
	Customer* next_cus = new Customer(next_srv_time, this_cus->get_clock()->get_time() + inter_arr_time);
	next_cus->set_event_queue(this_cus->get_event_queue());
	next_cus->set_clock(this_cus->get_clock());
	next_cus->set_entity_map(this_cus->get_entity_map());
	
	// next_evt
	Event* next_arr_evt = new Event(this_cus->get_clock()->get_time() + inter_arr_time, next_cus, 0); 
	this_cus->get_event_queue()->push_event(next_arr_evt);

	//Logger::inst()->log(KLT_OUTPUT) << "Inter Arrival Time: " << inter_arr_time << endl;
	Logger::inst()->log(KLT_OUTPUT) << "Next Event Arriving Time: " << this_cus->get_clock()->get_time() + inter_arr_time << endl;

	// if server was busy...
	if(server->get_busy() == true)
	{
		cq->push_customer(this_cus);
		Logger::inst()->log(KLT_OUTPUT) << "The Customer added to queue." << endl;
	}
	// server is not busy...
	else
	{
		Event* dep_evt = new Event(this_cus->get_clock()->get_time() + this_cus->get_service_time(), this_cus, 1);
		
		Logger::inst()->log(KLT_OUTPUT) << "Departure time: " << cus->get_clock()->get_time() + this_cus->get_service_time() << endl;

		this_cus->get_event_queue()->push_event(dep_evt);
		server->set_busy(true);
		Logger::inst()->log(KLT_OUTPUT) << "The customer added to server." << endl;
	}
}

void OnCustomerDeparture(Entity* cus)
{
	// variables
	Server* server = (Server*)(cus->get_entity("server"));
	CustomerQueue* cq = (CustomerQueue*)(cus->get_entity("queue"));
	Customer* this_cus = (Customer*)cus;

	Logger::inst()->log(KLT_OUTPUT) << "Customer time: " << this_cus->get_clock()->get_time() << endl;
	Logger::inst()->log(KLT_OUTPUT) << "Customer wants to go, ID: " << this_cus->get_id() << "." << endl;

	// testing event_queue
	if(cq->is_empty() == true)
	{
		server->set_busy(false);
		Logger::inst()->log(KLT_OUTPUT) << "Oh, Server is idle, now." << endl;
	}
	else
	{
		Logger::inst()->log(KLT_OUTPUT) << "Phew, Server is still busy!" << endl;
		Customer* front_cus = cq->pop_customer();
		Event* dep_evt = new Event(this_cus->get_clock()->get_time() + front_cus->get_service_time(), front_cus, 1);
		this_cus->get_event_queue()->push_event(dep_evt);
		Logger::inst()->log(KLT_OUTPUT) << "Front Customer ID: " << front_cus->get_id() << endl;
		Logger::inst()->log(KLT_OUTPUT) << "Departure time: " << cus->get_clock()->get_time() + front_cus->get_service_time() << endl;
	}

	// deleting cus
	delete cus;
}
