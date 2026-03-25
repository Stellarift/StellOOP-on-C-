#pragma once

#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;
    
    virtual ~Shape() = default;
};