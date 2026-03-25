#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::printInfo() const {
    cout << "Rectangle (width = " << width << ", height = " << height << ")" << endl;
}