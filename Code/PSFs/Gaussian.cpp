#include <cmath>

#include "Gaussian.h"
#include "RandomNumberGenerator.h"
#include "Utils.h"

using namespace std;
using namespace DNest3;

Gaussian::Gaussian(double min_width, double max_width)
:min_width(min_width)
,max_width(max_width)
{

}

void Gaussian::fromPrior()
{
	width = exp(log(min_width) + log(max_width/min_width)*randomU());
}

double Gaussian::perturb()
{
	double logH = 0.;

	width = log(width);
	width += log(max_width/min_width)*pow(10., 1.5 - 6.*randomU())*randn();
	width = mod(width - log(min_width), log(max_width/min_width))
			+ log(min_width);
	width = exp(width);

	return logH;
}

double Gaussian::evaluate(double x, double y) const
{
	return 1./(2.*M_PI*width*width)*exp(-0.5*(x*x + y*y)/(width*width));
}

void Gaussian::print(ostream& out) const
{
	out<<width<<' ';
}

