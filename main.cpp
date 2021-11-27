// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

int main()
{
    //double s = 0.3;

    /*TestCurve a = TestCurve(1, -1, 0, 1);
    double xs = a.x(s);
    cout << "x(s) = " << xs << endl;
    double ys = a.y(s);
    cout << "y(s) = " << ys << endl;*/

    //ExpCurve c = ExpCurve(5, -10);
    //ExpCurve c = ExpCurve(-10, 5);
    //double ys = c.y(s);
    //VerticalLine v = VerticalLine(0, 3);
    //VerticalLine v = VerticalLine(3, 0);
    //double ys = v.y(s);

    //cout << "y(s) = " << ys << endl;
    //HorizontalLine h = HorizontalLine(-10, 5);

    ExpCurve c = ExpCurve(-10, 5);
    VerticalLine v1 = VerticalLine(5, 0, 3);
    HorizontalLine h = HorizontalLine(3, 5, -10);
    VerticalLine v2 = VerticalLine(-10, 3, 0);

    Domain dom = Domain(c, v1, h, v2);
    //dom.generate_grid_naive(3, 4);
    dom.generate_grid(7, 7);
    //string str = dom.print_grid('y');
    //cout << str << endl;
    dom.save_as_csv("Grids/grid_mn_7");

    return EXIT_SUCCESS;    
}
