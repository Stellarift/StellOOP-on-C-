#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
    static const double PI;

public:
    Circle();
    explicit Circle(double r);
    Circle(const Circle& other);
    
    double getRadius() const;
    double getLength() const;
    
    void setRadius(double r);
    void print() const;
    
    bool operator==(const Circle& other) const;
    bool operator>(const Circle& other) const;
    
    Circle& operator+=(double value);
    Circle& operator-=(double value);
};

#endif