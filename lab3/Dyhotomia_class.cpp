#include "Dyhotomia_class.h"

double f(double x) {
    return cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x;
}

Dyhotomia_class::Dyhotomia_class(void) {
    a = 0;
    b = 0;
    eps = 0.0001;
}

Dyhotomia_class::~Dyhotomia_class(void) {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

int Dyhotomia_class::count(double &x) {
    if (f(a) * f(b) > 0) {
        cout << "Немає розвязку на промiжку" << endl;
        return -1;
    }

    double left = a;
    double right = b;
    double c;

    while (fabs(right - left) > eps) {
        c = (left + right) / 2.0;

        if (f(left) * f(c) < 0)
            right = c;
        else
            left = c;
    }

    x = (left + right) / 2.0;
    return 0;
}
