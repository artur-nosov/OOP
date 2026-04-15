#include "Dyhotomia_class.h"
#include "Newton_class.h"

int main() {
    system("chcp 65001>nul 2>nul");

    double a, b, eps;

    cout << "Введiть a: ";
    cin >> a;
    cout << "Введiть b: ";
    cin >> b;
    cout << "Введiть eps: ";
    cin >> eps;

    double x1, x2;

    Dyhotomia_class *dyh = new Dyhotomia_class();
    dyh->setVolumes(a, b);
    dyh->setTolerance(eps);

    if (dyh->count(x1) == 0) {
        cout << "Дихотомiя: x = " << x1 << endl;
        cout << "f(x) = " << f(x1) << endl;
    }

    delete dyh;

    Newton_class *newt = new Newton_class();
    newt->setVolumes(a, b);
    newt->setTolerance(eps);

    if (newt->count(x2) == 0) {
        cout << "Ньютон: x = " << x2 << endl;
        cout << "f(x) = " << f(x2) << endl;
    }

    delete newt;

    return 0;
}
