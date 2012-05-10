#include <Khagine.h>
using namespace khagine;

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	NormalDistribution nd(20.12, 3.1244);

	for(int i = 0 ; i < 1000 ; i ++)
	{
		cout << nd.generate() << endl;
	}
	
	return 0;
}
