#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}

double Triangle::area() const {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() const {
    return a + b + c;
}

void Triangle::printInfo() const {
    cout << "Triangle (sides = " << a << ", " << b << ", " << c << ")" << endl;
}