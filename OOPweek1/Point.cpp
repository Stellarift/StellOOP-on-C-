#include "Point.h"
#include <iostream>

using namespace std;

Point::Point() : x(0.0), y(0.0), z(0.0) {}

void Point::inputData() {
    cout << "Введите координату X: ";
    cin >> x;
    cout << "Введите координату Y: ";
    cin >> y;
    cout << "Введите координату Z: ";
    cin >> z;
}

void Point::displayData() const {
    cout << "Точка: (" << x << ", " << y << ", " << z << ")" << endl;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

void Point::setX(double newX) { x = newX; }
void Point::setY(double newY) { y = newY; }
void Point::setZ(double newZ) { z = newZ; }