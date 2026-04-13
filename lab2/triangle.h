#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <iostream>

using namespace std;

// Структура точки
struct Point {
    double x, y;
};

// Структура трикутника
struct Triangle {
    Point A, B, C;

    // Площа трикутника (формула Герона)
    double area() const;

    // Перевірка чи трикутник вироджений (площа == 0)
    bool isDegenerate() const;

    // Метод 1: перевірка належності точки через площі
    // Повертає: 1 - всередині, 0 - на межі, -1 - зовні
    int containsByArea(const Point &P) const;

    // Метод 2: перевірка належності точки через векторний добуток
    // Повертає: 1 - всередині, 0 - на межі, -1 - зовні
    int containsByCross(const Point &P) const;
};

// Відстань між двома точками
double distance(const Point &p1, const Point &p2);

// Площа трикутника за формулою Герона
double heronArea(const Triangle &t);

// Векторний добуток двох векторів (AB x AC)
double crossProduct(const Point &A, const Point &B, const Point &C);

// Перевірка чи точка лежить на відрізку
bool isOnSegment(const Point &A, const Point &B, const Point &P);

#endif
