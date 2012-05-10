#include "exp_distribution.h"
using namespace khagine;

ExponentialDistribution::ExponentialDistribution()
{
	lambda = 0;
}

ExponentialDistribution::ExponentialDistribution(double _lambda)
{
	lambda = _lambda;
}

double ExponentialDistribution::generate()
{
	float u = float(rand()) / RAND_MAX;

	float random_num = - (1 / lambda) * log(u);

	return random_num;
}
