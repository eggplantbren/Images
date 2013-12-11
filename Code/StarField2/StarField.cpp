#include "StarField.h"
#include "RandomNumberGenerator.h"
#include "Utils.h"
#include <cmath>

using namespace std;
using namespace DNest3;

StarField::StarField()
:psf(0.1, 10.)
{

}

void StarField::fromPrior()
{
	psf.fromPrior();
}

double StarField::perturb()
{
	double logH = 0.;

	logH += psf.perturb();

	return logH;
}

double StarField::logLikelihood() const
{
	return 0.;
}

void StarField::print(std::ostream& out) const
{
	psf.print(out);
}

string StarField::description() const
{
	return string("");
}

