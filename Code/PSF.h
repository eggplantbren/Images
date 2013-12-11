#ifndef _PSF_
#define _PSF_

/*
* Define the interface for any model of a PSF or a pixel-convolved PSF
*/

class PSF
{
	private:


	public:
		PSF() { }
		virtual ~PSF() { }

		virtual void fromPrior();
		virtual double perturb() = 0;
		virtual double evaluate(double x, double y) const = 0;
};

#endif

