#pragma once
#include <cmath>
#include <iostream>
using namespace std;

class Curvebase
{
    public:
        Curvebase(double a, double b); // [a,b] span of p of the parameterized curve
        double x(double s); //x-coord from arclength param s
        double y(double s); //y-coord -||-
        virtual ~Curvebase();

    protected:
        double a_, b_; //range for p
        double length_;
        double guess_;
        double rev_;

        virtual double xp(double p) = 0; //User parametrization, description of curve
        virtual double yp(double p) = 0;
        virtual double dxp(double p) = 0; //Derivatives
        virtual double dyp(double p) = 0;
        double arclen_integrand(double p); 
        double integrate(double p); // arc length integral
        double simpsons_rule(double a, double b); //used by adaptiveIntegration
        double adaptiveIntegration(double a, double b, double tol = 1e-12, int counter = 0, const int &maxDepth = 1000);
        double newton(double s, double guess, const double &tol=1e-12); //estimate p and return X(p) = x(s) given s

        void reverese();
};

class TestCurve: public Curvebase
{
public:
    TestCurve(double a0, double a1, double a, double b);
    ~TestCurve();
protected:
    double a0_, a1_;
    double xp(double p)  override;
    double yp(double p)  override;
    double dxp(double p) override;
    double dyp(double p) override;
};

class ExpCurve : public Curvebase
{
public:
    ExpCurve(double a, double b);
    ~ExpCurve();
protected:
    double xp(double p)  override;
    double yp(double p)  override;
    double dxp(double p) override;
    double dyp(double p) override;
};

class VerticalLine : public Curvebase
{
public:
    VerticalLine(double x_pos, double a, double b);
    ~VerticalLine();
protected:
    double _x_pos;
    double xp(double p)  override;
    double yp(double p)  override;
    double dxp(double p) override;
    double dyp(double p) override;
};

class HorizontalLine : public Curvebase
{
public:
    HorizontalLine(double y_pos, double a, double b);
    ~HorizontalLine();
protected:
    double _y_pos;
    double xp(double p)  override;
    double yp(double p)  override;
    double dxp(double p) override;
    double dyp(double p) override;
};
