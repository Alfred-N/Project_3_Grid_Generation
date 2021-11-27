#include "Domain.h"
#include <iostream>
#include <fstream>
#include <string>

Domain::Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4) : 
	_m(0.0), _n(0.0)

{
	_sides[0] = &s1;
	_sides[1] = &s2;
	_sides[2] = &s3;
	_sides[3] = &s4;

	if (!this->check_consistency())
	{
		_sides[0] = _sides[1] = _sides[2] = _sides[3] = nullptr;
	}
	_x = _y = nullptr;
}

void Domain::generate_grid_naive(int m, int n)
{
	//TODO check existance of grid
	if (m < 1 || n < 1)
	{
		throw std::length_error("Disallowed value of m or n: ");
		exit(EXIT_FAILURE);
	}

	_m = m; _n = n;
	double h1 = 1.0 / _m; double h2 = 1.0 / _n; //step sizes
	_x = new double[(m + 1) * (n + 1)]; _y = new double[(m + 1) * (n + 1)];

	for (int i = 0; i <= _m; i++)
	{
		for (int j = 0; j <= _n; j++)
		{
			//big formula from the slides
			//before starting, must be sure that the sides describe the domain
			// point(0,0) must be identical regardless of which axis which we are on
			//consistency check
			// sides 0,1,2,3; contains Curvebase objects
			// m<->eta=i*h1
			// n<->ny=j*h2
			// x0(ny)=sides[3].x(j*h2)
			// x1(ny)=sides[1].x(j*h2)
			// y0(eta)=sides[0].y(i*h1)
			// y1(eta)=sides[2].y(i*h1)
			_x[j + i * (_n + 1)] = this->phi0(i * h1) * _sides[3]->x(j * h2) + this->phi1(i * h1) * _sides[1]->x(j * h2);

			_y[j + i * (_n + 1)] = this->phi0(j * h2) * _sides[0]->y(i * h1) + this->phi1(j * h2) * _sides[2]->y(i * h1);
			double a = 0;
						
		}
	}


}

// ----------------------- REAL IMPLEMENTATION -------------------------
void Domain::generate_grid(int m, int n)
{
	//TODO check existance of grid
	if (m < 1 || n < 1)
	{
		throw std::length_error("Disallowed value of m or n: ");
		exit(EXIT_FAILURE);
	}

	_m = m; _n = n;
	double h1 = 1.0 / _m; double h2 = 1.0 / _n; //step sizes
	_x = new double[(m + 1) * (n + 1)]; _y = new double[(m + 1) * (n + 1)];

	for (int i = 0; i <= _m; i++)
	{
		for (int j = 0; j <= _n; j++)
		{
			//big formula from the slides
			//before starting, must be sure that the sides describe the domain
			// point(0,0) must be identical regardless of which axis which we are on
			//consistency check
			// sides 0,1,2,3; contains Curvebase objects
			// m<->eps=i*h1
			// n<->ny=j*h2
			// x0(ny)=sides[3].x(j*h2)
			// x1(ny)=sides[1].x(j*h2)
			// y0(eps)=sides[0].y(i*h1)
			// y1(eps)=sides[2].y(i*h1)
			_x[j + i * (_n + 1)] = 
					this->phi0(i * h1) * _sides[3]->x(j * h2) + this->phi1(i * h1) * _sides[1]->x(j * h2)
				+	this->phi0(j * h2) * _sides[0]->x(i * h1) + this->phi1(j * h2) * _sides[2]->x(i * h1)

				-	this->phi0(i * h1) * this->phi0(j * h2) * _sides[0]->x(0)
				-	this->phi1(i * h1) * this->phi0(j * h2) * _sides[1]->x(0)
				-	this->phi0(i * h1) * this->phi1(j * h2) * _sides[2]->x(0)
				-	this->phi1(i * h1) * this->phi1(j * h2) * _sides[2]->x(1);

			_y[j + i * (_n + 1)] = 
					this->phi0(i * h1) * _sides[3]->y(j * h2) + this->phi1(i * h1) * _sides[1]->y(j * h2)
				+	this->phi0(j * h2) * _sides[0]->y(i * h1) + this->phi1(j * h2) * _sides[2]->y(i * h1)

				-	this->phi0(i * h1) * this->phi0(j * h2) * _sides[0]->y(0)
				-	this->phi1(i * h1) * this->phi0(j * h2) * _sides[1]->y(0)
				-	this->phi0(i * h1) * this->phi1(j * h2) * _sides[2]->y(0)
				-	this->phi1(i * h1) * this->phi1(j * h2) * _sides[2]->y(1);
			double a = 0;

		}
	}
}

string Domain::print_grid(const char &axis)
{
	double* arr;
	string str = "";
	if (axis == 'x') { arr = _x; }
	else if (axis == 'y') { arr = _y; }
	else {
		throw std::length_error("Disallowed axis: ");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i <= _m; i++)
	{
		for (int j = 0; j <= _n; j++)
		{
			str += std::to_string(arr[j + i * (_n + 1)]);
			str += ",";
			if (j==_n)
			{
				str += "\n";
			}
		}
	}
	return str;
}

void Domain::save_as_csv(const string file_name)
{
	ofstream csv_x;
	csv_x.open(file_name + "_x.csv");
	ofstream csv_y;
	csv_y.open(file_name + "_y.csv");

	string x_str = this->print_grid('x');
	string y_str = this->print_grid('y');

	csv_x << x_str << endl;
	csv_y << y_str << endl;

	csv_x.close();
	csv_y.close();

}

double Domain::phi0(double s)
{
	if (s < 0 or s>1 + 1e-12)
	{
		throw std::length_error("Disallowed value of s: ");
		exit(EXIT_FAILURE);
	}
	return 1.0 - s;
}

double Domain::phi1(double s)
{
	if (s < 0 or s>1 + 1e-12)
	{
		throw std::length_error("Disallowed value of s: ");
		exit(EXIT_FAILURE);
	}
	return s;
}

bool Domain::check_consistency()
{
	//TODO
	return true;
}
