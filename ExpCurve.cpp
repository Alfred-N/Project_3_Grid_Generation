#include "Curves.h"
ExpCurve::ExpCurve(double a, double b) : Curvebase(a, b)
{
	this->reverese();
}

double ExpCurve::xp(double p)
{
	return p;
}

double ExpCurve::yp(double p)
{
	double f;
	if (p >= -10 && p < -3)
	{
		f = (1.0 / 2.0) * 1 / (1 + exp(-3 * (p + 6)));
	}
	else if (p>=-3 && p <= 5)
	{
		f = (1.0 / 2.0) * 1 / (1 + exp(3 * p));
	}
	else if (p < -10 || p > 5)
	{
		f = 0.0;
	}
	else 
	{
		throw std::length_error("Incorrect value of p: ");
		cout << p << endl;
		exit(EXIT_FAILURE);
	}
	return f;
}

double ExpCurve::dxp(double p)
{
	return 1.0;
}

double ExpCurve::dyp(double p)
{
	double f;
	double exp_f;
	if (p >= -10 && p < -3)
	{
		exp_f = exp(-3 * (p + 6));
		f = (3.0 / 2.0) * exp_f / ((1+exp_f)*(1+exp_f));
	}
	else if (p >= -3 && p <= 5)
	{
		exp_f = exp(3 * p);
		f = -(3.0 / 2.0) * exp_f / ((1 + exp_f) * (1 + exp_f));
	}
	else if (p < -10 || p > 5)
	{
		f = 0.0;
	}
	else
	{
		cout << "Incorrect value of p: " << p << endl;
		throw std::length_error("");
		exit(EXIT_FAILURE);
	}
	return f;
}
