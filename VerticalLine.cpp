#include "Curves.h"

VerticalLine::VerticalLine(double x_pos, double a, double b) : Curvebase(a, b), _x_pos(x_pos)
{
	this->reverese();
	//cout << length_ << endl;
}

VerticalLine::~VerticalLine()
{
}

double VerticalLine::xp(double p)
{
	return _x_pos;
}

double VerticalLine::yp(double p)
{
	return p;
}

double VerticalLine::dxp(double p)
{
	return 0.0;
}

double VerticalLine::dyp(double p)
{
	return 1.0;
}
