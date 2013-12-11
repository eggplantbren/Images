#include <iostream>
#include "Start.h"
#include "StarField.h"
#include "Data.h"

using namespace std;
using namespace DNest3;

int main(int argc, char** argv)
{
	// Load a data file
	Data::load_data("Data/100.txt");

	// Setup and run the sampler
	MTSampler<StarField> sampler = setup_mt<StarField>(argc, argv);
	sampler.run();

	return 0;
}

