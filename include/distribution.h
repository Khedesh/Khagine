// Name: distribution.h
// Author: Khedesh
// Date: 02/21/2012, 6:34 PM
// Description: This file contains the Distribution class for generating the random number.

#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

namespace khagine
{
	class Distribution
	{
		public:

		virtual double generate() = 0;

	}; // end class Distribution

} // end namespace khagine

#endif // DISTRIBUTION_H
