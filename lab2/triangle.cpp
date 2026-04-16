#include "triangle.h"

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double exactArea(const Triangle &t) {
    return 0.5 * fabs(crossProduct(t.A, t.B, t.C));
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double crossProduct(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

bool isOnSegment(const Point &A, const Point &B, const Point &P) {
    double cross = crossProduct(A, B, P);
    if (fabs(cross) > 1e-9) return false;

    double minX = min(A.x, B.x);
    double maxX = max(A.x, B.x);
    double minY = min(A.y, B.y);
    double maxY = max(A.y, B.y);
    
    return P.x >= minX - 1e-9 && P.x <= maxX + 1e-9 &&
           P.y >= minY - 1e-9 && P.y <= maxY + 1e-9;
}

double Triangle::area() const {
    return exactArea(*this);
}

bool Triangle::isDegenerate() const {
    return area() < 1e-9;
}

int Triangle::containsByArea(const Point &P) const {
    if (isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P)) {
        return 0;
    }

    if (isDegenerate()) {
        return -1;
    }

    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double sMain = area();
    double sSum = T1.area() + T2.area() + T3.area();

    if (fabs(sMain - sSum) < 1e-9) {
        return 1;
    }
    return -1;
}

int Triangle::containsByCross(const Point &P) const {
    if (isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P)) {
        return 0;
    }

    if (isDegenerate()) {
        return -1;
    }

    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if (!(hasNeg && hasPos)) {
        return 1;
    }
    return -1;
}
