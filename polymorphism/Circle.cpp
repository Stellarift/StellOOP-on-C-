#include "Circle.h"
#include <iostream>
using namespace std;

const double Circle::PI = 3.141592653589793;

Circle::Circle(double r) : radius(r) {}

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::printInfo() const {
    cout << "Circle (radius = " << radius << ")" << endl;
}