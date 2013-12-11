#ifndef _Gaussian_
#define _Gaussian_

#include "../PSF.h"

/*
* A simple Gaussian PSF with a log-uniform prior on the width.
*/

class Gaussian:public PSF
{
	private:
		double min_width, max_width;
		double width;

	public:
		Gaussian(double min_width, double max_width);

		void fromPrior();
		double perturb();
		double evaluate(double x, double y) const;
		void print(std::ostream& out) const;

		// Beyond this radius, treat as zero, so you don't have
		// to evaluate the function so much
		double get_max_radius() const { return 5.*width; }

};

#endif

