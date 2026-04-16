#include "triangle.h"

void printResult(const string &method, int result) {
    if (result == 1) {
        cout << method << ": точка ВСЕРЕДИНІ трикутника\n";
    } else if (result == 0) {
        cout << method << ": точка НА МЕЖІ трикутника\n";
    } else {
        cout << method << ": точка ЗОВНІ трикутника\n";
    }
}

int main() {
    system("chcp 65001 > nul 2>&1");

    Triangle t;
    cout << "Введіть координати вершин трикутника:\n";

    cout << "A (x y): ";
    cin >> t.A.x >> t.A.y;

    cout << "B (x y): ";
    cin >> t.B.x >> t.B.y;

    cout << "C (x y): ";
    cin >> t.C.x >> t.C.y;

    if (t.isDegenerate()) {
        cout << "Трикутник вироджений (площа = 0).\n";
    }

    cout << "Площа трикутника: " << t.area() << "\n\n";

    int n;
    cout << "Скільки точок перевірити? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cout << "\nТочка " << (i + 1) << " (x y): ";
        cin >> p.x >> p.y;

        int res1 = t.containsByArea(p);
        int res2 = t.containsByCross(p);

        printResult("  Метод площ", res1);
        printResult("  Векторний добуток", res2);
    }

    return 0;
}
