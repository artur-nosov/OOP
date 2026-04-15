#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

#include <cmath>
#include <iostream>

using namespace std;

double f(double x);

class Newton_class
{
public:
    Newton_class(void);
    ~Newton_class(void);

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    int count(double &x);

private:
    double a;
    double b;
    double eps;
    double derivative(double x);
};

#endif
