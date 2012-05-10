// Name: normal_distribution.h
// Author: Khedesh
// Date: 02/21/2012, 6:42 PM

#ifndef NORMAL_DISTRIBUTION_H
#define NORMAL_DISTRIBUTION_H

#include <math.h>
#include <stdlib.h>
#include "distribution.h"

namespace khagine
{
	class NormalDistribution : public Distribution
	{
		double mean;
		double variance;

		public:

		NormalDistribution();
		NormalDistribution(double _mean, double _variance);

		virtual double generate();

	}; // end class NormalDistribution

} // end namespace khagine

#endif // NORMAKL_DISTRIBUTION_H
