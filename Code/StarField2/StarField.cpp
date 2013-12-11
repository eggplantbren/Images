#include "StarField.h"
#include "RandomNumberGenerator.h"
#include "Utils.h"
#include <cmath>

using namespace std;
using namespace DNest3;

StarField::StarField()
{

}

void StarField::fromPrior()
{

}

double StarField::perturb()
{
	return 0.;
}

double StarField::logLikelihood() const
{
	return 0.;
}

void StarField::print(std::ostream& out) const
{

}

string StarField::description() const
{
	return string("");
}

