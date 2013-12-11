#ifndef _StarField_
#define _StarField_

#include "Model.h"
#include "../PSFs/Gaussian.h"
#include <RJObject.h>
#include <Distributions/ClassicMassInf.h>
#include <vector>

class StarField:public DNest3::Model
{
	private:
		static const int max_num_stars;

	private:
		/* VARIABLES */
		RJObject<ClassicMassInf> stars;
		Gaussian psf;

		// Predicted (noise-free) image
		std::vector< std::vector<double> > mock_image;


		/* METHODS */
		// Compute the mock image from scratch
		void compute_mock_image();

	public:
		StarField();

		// Generate the point from the prior
		void fromPrior();

		// Metropolis-Hastings proposals
		double perturb();

		// Likelihood function
		double logLikelihood() const;

		// Print to stream
		void print(std::ostream& out) const;

		// Return string with column information
		std::string description() const;
};

#endif

