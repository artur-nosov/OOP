#include "triangle.h"

// Виводить результат перевірки
void printResult(const string &method, int result) {
    if (result == 1) {
        cout << method << ": точка ВСЕРЕДИНІ трикутника" << endl;
    } else if (result == 0) {
        cout << method << ": точка НА МЕЖІ трикутника" << endl;
    } else {
        cout << method << ": точка ЗОВНІ трикутника" << endl;
    }
}

int main() {
    system("chcp 65001>nul 2>nul");

    // Введення координат трикутника
    Triangle t;
    cout << "Введіть координати вершин трикутника:" << endl;

    cout << "A (x y): ";
    cin >> t.A.x >> t.A.y;

    cout << "B (x y): ";
    cin >> t.B.x >> t.B.y;

    cout << "C (x y): ";
    cin >> t.C.x >> t.C.y;

    // Перевірка на виродженість
    if (t.isDegenerate()) {
        cout << "Трикутник вироджений (площа = 0). Завершення." << endl;
        return 0;
    }

    cout << "Площа трикутника: " << t.area() << endl;
    cout << endl;

    // Введення кількості точок
    int n;
    cout << "Скільки точок перевірити? ";
    cin >> n;

    // Перевірка кожної точки
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
