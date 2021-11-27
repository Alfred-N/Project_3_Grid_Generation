#include "Curves.h"

TestCurve::TestCurve(double a0, double a1, double a, double b) :
	Curvebase(a, b), a0_(a0), a1_(a1)
{
	this->reverese();
}

TestCurve::~TestCurve()
{
}

double TestCurve::xp(double p)
{
	return p;
}

double TestCurve::yp(double p)
{
	return a0_ * sqrt(p) + a1_ * p;
}

double TestCurve::dxp(double p)
{
	return 1.0;
}

double TestCurve::dyp(double p)
{
	if (p< 1e-13)
	{
		p = 1e-13;
	}
	return a0_ / (2 * sqrt(p)) + a1_;
}
