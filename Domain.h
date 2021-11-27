#pragma once
#include "Curves.h"

class Domain
{
    public:
        Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4);
        void generate_grid(int m, int n);
        string print_grid(const char& axis);
        void save_as_csv(const string file_name);
        ~Domain();

    private:
        Curvebase* _sides[4];
        double * _x, * _y; //arrays of length (_m+1)*(_n+1)
        int _m, _n;
        
        double phi0(double s); //interpolation between two points
        double phi1(double s);

        void check_consistency();
};

