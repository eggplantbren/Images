#include "StarField.h"
#include "Data.h"

#include "RandomNumberGenerator.h"
#include "Utils.h"

#include <cmath>

using namespace std;
using namespace DNest3;

const int StarField::max_num_stars = 200;

// This looks messy because the limits on the star positions
// are set based on the extent of the data
StarField::StarField()
:stars(3, max_num_stars, false,
	ClassicMassInf( Data::get_instance().get_xMin()
			- 0.1*Data::get_instance().get_xRange(),
			Data::get_instance().get_xMax()
			+ 0.1*Data::get_instance().get_xRange(),
			Data::get_instance().get_yMin()
			- 0.1*Data::get_instance().get_yRange(),
			Data::get_instance().get_yMax()
			+ 0.1*Data::get_instance().get_yRange(),
			1E-3, 1E3))
,psf(0.5*sqrt(Data::get_instance().get_dA()),
	20.*sqrt(Data::get_instance().get_dA()))
,mock_image(Data::get_instance().get_ni(),
		vector<double>(Data::get_instance().get_nj()))
{

}

void StarField::fromPrior()
{
	stars.fromPrior();
	psf.fromPrior();
	compute_mock_image();
}

void StarField::compute_mock_image()
{
	mock_image.assign(Data::get_instance().get_ni(),
				vector<double>(Data::get_instance().get_nj(), 0.));
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

