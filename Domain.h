#pragma once
#include "Curves.h"

class Domain
{
    public:
        Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4);
        void generate_grid_naive(int m, int n);
        void generate_grid(int m, int n);
        string print_grid(const char& axis);
        void save_as_csv(const string file_name);

    private:
        Curvebase* _sides[4];
        double * _x, * _y; //dimensions (_m+1)(_n+1)
        int _m, _n;
        //possibility 1
        double phi0(double s); //could also be provided by user in constructor
        double phi1(double s);

        bool check_consistency();
};

