#include "normal_distribution.h"
using namespace khagine;

NormalDistribution::NormalDistribution()
{
	mean = 0;
	variance = 0;
}

NormalDistribution::NormalDistribution(double _mean, double _variance)
{
	mean = _mean;
	variance = _variance;
}

double NormalDistribution::generate()
{
	float u = (float)(rand()) / RAND_MAX;
	float v = (float)(rand()) / RAND_MAX;

	static bool flag = false;
	static float second_num = 0;
	float random_num = 0;

	if(flag == false)
	{
		random_num = pow(-2 * log(u), 0.5) * cos(8 * asin(1) * v) * pow(variance, 0.5) + mean;
		second_num = pow(-2 * log(u), 0.5) * sin(8 * asin(1) * v) * pow(variance, 0.5) + mean;

		flag = true;
	}
	else
	{
		random_num = second_num;
		flag = false;
	}

	if(random_num < 0)
		return 0;
	else 
		return random_num;

}
