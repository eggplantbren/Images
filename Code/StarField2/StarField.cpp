#include "StarField.h"
#include "RandomNumberGenerator.h"
#include "Utils.h"
#include <cmath>

using namespace std;
using namespace DNest3;

const int StarField::max_num_stars = 200;

StarField::StarField()
:stars(3, max_num_stars, false, ClassicMassInf(-50., 50., -50., 50., 1E-3, 1E3))
,psf(0.1, 10.)
{

}

void StarField::fromPrior()
{
	stars.fromPrior();
	psf.fromPrior();
}

double StarField::perturb()
{
	double logH = 0.;

	int which = randInt(2);
	if(which == 0)
		logH += stars.perturb();
	else
		logH += psf.perturb();

	return logH;
}

double StarField::logLikelihood() const
{
	return 0.;
}

void StarField::print(std::ostream& out) const
{
	stars.print(out);
	psf.print(out);
}

string StarField::description() const
{
	return string("");
}

