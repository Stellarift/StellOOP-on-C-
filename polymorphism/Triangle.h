#pragma once

#include "Shape.h"
#include <cmath>

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double s1, double s2, double s3);
    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};