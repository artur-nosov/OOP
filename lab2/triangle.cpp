#include "triangle.h"

// Відстань між двома точками
double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Площа за формулою Герона
double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Векторний добуток AB x AC
double crossProduct(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Перевірка чи точка P лежить на відрізку AB
bool isOnSegment(const Point &A, const Point &B, const Point &P) {
    // Перевіряємо що векторний добуток ~0 і точка між A та B
    double cross = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    if (fabs(cross) > 1e-9) return false;

    // Точка має бути між A і B
    double minX = min(A.x, B.x), maxX = max(A.x, B.x);
    double minY = min(A.y, B.y), maxY = max(A.y, B.y);
    return P.x >= minX - 1e-9 && P.x <= maxX + 1e-9 &&
           P.y >= minY - 1e-9 && P.y <= maxY + 1e-9;
}

// Площа трикутника
double Triangle::area() const {
    return heronArea(*this);
}

// Перевірка на виродженість
bool Triangle::isDegenerate() const {
    return area() < 1e-9;
}

// Метод 1: через порівняння площ
int Triangle::containsByArea(const Point &P) const {
    // Перевіряємо чи точка на межі
    if (isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P)) {
        return 0; // на межі
    }

    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    if (fabs(S_main - S_sum) < 1e-9) {
        return 1; // всередині
    }
    return -1; // зовні
}

// Метод 2: через векторний добуток
int Triangle::containsByCross(const Point &P) const {
    // Перевіряємо чи точка на межі
    if (isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P)) {
        return 0; // на межі
    }

    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if (!(hasNeg && hasPos)) {
        return 1; // всередині
    }
    return -1; // зовні
}
