#pragma once

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};