#include <iostream>
#include "Start.h"
#include "StarField.h"

using namespace std;
using namespace DNest3;

int main(int argc, char** argv)
{
	#ifndef DNest3_No_Boost
	MTSampler<StarField> sampler = setup_mt<StarField>(argc, argv);
	#else
	Sampler<> sampler = setup<StarField>(argc, argv);
	#endif

	sampler.run();
	return 0;
}

