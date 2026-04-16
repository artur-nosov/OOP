#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;
    bool isDegenerate() const;
    int containsByArea(const Point &P) const;
    int containsByCross(const Point &P) const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
double crossProduct(const Point &A, const Point &B, const Point &C);
bool isOnSegment(const Point &A, const Point &B, const Point &P);

#endif
