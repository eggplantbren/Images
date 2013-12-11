#ifndef _PSF_
#define _PSF_

#include <ostream>

/*
* Define the interface for any model of a PSF or a pixel-convolved PSF
*/

class PSF
{
	private:


	public:
		PSF() { }
		virtual ~PSF() { }

		virtual void fromPrior() = 0;
		virtual double perturb() = 0;
		virtual double evaluate(double x, double y) const = 0;
		virtual void print(std::ostream& out) const = 0;
};

#endif

