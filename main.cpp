// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

int main()
{
    //// Some tests
    //double s = 0.3;

    //TestCurve a = TestCurve(1, -1, 0, 1);
    //double xs = a.x(s);
    //cout << "x(s) = " << xs << endl;
    //double ys = a.y(s);
    //cout << "y(s) = " << ys << endl;

    //ExpCurve c1 = ExpCurve(5, -10);
    //ExpCurve c2 = ExpCurve(-10, 5);
    //
    ////VerticalLine v = VerticalLine(5, 0, 3);
    ////VerticalLine v = VerticalLine(5, 3, 0);
    ////HorizontalLine h = HorizontalLine(3, -10, 5);

    //double ys1 = c1.y(s);
    //double ys2 = c2.y(s);

    //cout << "y1(s) = " << ys1 << "  y2(s) = " << ys2 << endl;    

    // Grid generation
    ExpCurve c = ExpCurve(-10, 5);
    VerticalLine v1 = VerticalLine(5, 0, 3);
    HorizontalLine h = HorizontalLine(3, 5, -10);
    VerticalLine v2 = VerticalLine(-10, 3, 0);

    Domain dom = Domain(c, v1, h, v2);
    dom.generate_grid(7, 7);
    string str = dom.print_grid('x');
    cout << str << endl;
    //dom.save_as_csv("Grids/grid_mn_7_7");

    return EXIT_SUCCESS;
}
