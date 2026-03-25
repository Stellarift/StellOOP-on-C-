#pragma once

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    double radius;
    static const double PI;

public:
    Circle(double r);
    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};