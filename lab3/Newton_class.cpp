#include "Newton_class.h"

Newton_class::Newton_class(void) {
    a = 0;
    b = 0;
    eps = 0.0001;
}

Newton_class::~Newton_class(void) {}

void Newton_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Newton_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Newton_class::derivative(double x) {
    double dx = 1e-8;
    return (f(x + dx) - f(x)) / dx;
}

int Newton_class::count(double &x) {
    if (f(a) * f(b) > 0) {
        cout << "Немає розвязку на промiжку" << endl;
        return -1;
    }

    double xn = (a + b) / 2.0;
    double xn1;

    for (int i = 0; i < 1000; i++) {
        double dfx = derivative(xn);

        if (fabs(dfx) < 1e-12)
            return -1;

        xn1 = xn - f(xn) / dfx;

        if (fabs(xn1 - xn) <= eps) {
            x = xn1;
            return 0;
        }

        xn = xn1;
    }

    return -1;
}
