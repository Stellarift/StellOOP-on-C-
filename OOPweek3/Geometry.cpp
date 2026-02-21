#include "Geometry.h"
#include <cmath>

int Geometry::calculationCount = 0;

// Площадь треугольника по трем сторонам (формула Герона)
double Geometry::triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    calculationCount++;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Площадь треугольника по основанию и высоте
double Geometry::triangleArea(double base, double height) {
    calculationCount++;
    return 0.5 * base * height;
}

// Площадь прямоугольника
double Geometry::rectangleArea(double width, double height) {
    calculationCount++;
    return width * height;
}

// Площадь квадрата
double Geometry::squareArea(double side) {
    calculationCount++;
    return side * side;
}

// Площадь ромба по диагоналям
double Geometry::rhombusAreaByDiagonals(double d1, double d2) {
    calculationCount++;
    return (d1 * d2) / 2;
}

// Площадь ромба по стороне и углу
double Geometry::rhombusAreaBySideAndAngle(double side, double angle) {
    calculationCount++;
    return side * side * sin(angle * M_PI / 180);
}

int Geometry::getCalculationCount() {
    return calculationCount;
}