// Name: exp_distribution.h
// Author: Khedesh
// Date: 02/21/2012, 6:51 PM

#ifndef EXP_DISTRIBUTION_H
#define EXP_DISTRIBUTION_H

#include <math.h>
#include <stdlib.h>
#include "distribution.h"

namespace khagine
{
	class ExponentialDistribution : public Distribution
	{
		double lambda;

		public:

		ExponentialDistribution();
		ExponentialDistribution(double _lambda);

		virtual double generate();

	}; // end class ExponentialDistribution

} // end namespace khagine

#endif // EXP_DISTRIBUTION_H
