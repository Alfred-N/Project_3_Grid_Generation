#include "Curves.h"

Curvebase::Curvebase(double a, double b) : a_(a), b_(b), length_(0.0), guess_((a+b/2)), rev_(false)
{
}

double Curvebase::x(double s)
{
	double p;
	if (rev_)
	{
		p = this->newton(1.0 - s, guess_);
	}
	else p = this->newton(s, guess_);

	return this->xp(p);
}

double Curvebase::y(double s)
{
	double p;
	if (rev_)
	{
		p = this->newton(1.0 - s, guess_);
	}
	else p = this->newton(s, guess_);

	return this->yp(p);
}

double Curvebase::newton(double s, double guess, const double &tol)
{
	double p = guess;
	double p_next = guess;
	double err = HUGE_VAL;
	const int maxIt = 100;
	int i = 0;
	const double C = length_ * s;
	while (i<maxIt && err>tol)
	{
		p_next = p - (this->integrate(p) - C) / (this->arclen_integrand(p));
		err = abs(p_next - p);
		p = p_next;
		i++;
	}
	if (err > tol) {cout << "Warning: Max iter reach, tol not guaranteed" << endl; }
	return p_next;
}

Curvebase::~Curvebase()
{
	//TODO
}

double Curvebase::arclen_integrand(double p)
{
	double f = pow(this->dxp(p),2) + pow(this->dyp(p),2);
	return sqrt(f);
}

double Curvebase::integrate(double p)
{
	double I = this->adaptiveIntegration(a_, p);
	return I;
}

double Curvebase::adaptiveIntegration(double a, double b, double tol, int counter, const int &maxDepth)
{
	counter++;
	//I2 splits the interval once for convergence checking purposes
	double I1 = this->simpsons_rule(a, b);
	double I2 = this->simpsons_rule(a, (a + b) / 2.0) + this->simpsons_rule((a + b) / 2.0, b);

	if (counter == maxDepth)
	{
		printf("%s%d%s", "Warning, maximum recursion depth of ", maxDepth, " reached. Specified tolerance not guaranteed. \n");
		return I2;
	}

	// if the error is within tolerance, return I2
	double errest = abs(I1 - I2);
	if (errest < 15 * tol) return I2;

	// if the error is too large, split the interval further
	else return adaptiveIntegration(a, (a + b) / 2.0, tol, counter) + adaptiveIntegration((a + b) / 2.0, b, tol, counter);
}

double Curvebase::simpsons_rule(double a, double b)
{
	return (b - a) / 6.0 * (this->arclen_integrand(a) + 4 * this->arclen_integrand((a + b) / 2.0) + this->arclen_integrand(b));
}

void Curvebase::reverese()
{
	length_ = this->integrate(b_);
	if (length_ < 0)
	{
		rev_ = true;
	}
	else rev_ = false;
}
