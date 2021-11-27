#include "Curves.h"

HorizontalLine::HorizontalLine(double y_pos, double a, double b) : Curvebase(a, b), _y_pos(y_pos)
{
	this->reverese();
	//cout << length_ << endl;
}

double HorizontalLine::xp(double p)
{
	return p;
}

double HorizontalLine::yp(double p)
{
	return _y_pos;
}

double HorizontalLine::dxp(double p)
{
	return 1.0;
}

double HorizontalLine::dyp(double p)
{
	return 0.0;
}
