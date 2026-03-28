#pragma once

#include <iostream>
using namespace std;

namespace Geometry {
    const double PI = 3.14159;
    
    double circleArea(double radius) {
        return PI * radius * radius;
    }
    
    double rectangleArea(double width, double height) {
        return width * height;
    }
    
    namespace Shapes {
        class Circle {
        private:
            double radius;
        public:
            Circle(double r) : radius(r) {}
            double area() const {
                return Geometry::circleArea(radius);
            }
            void print() const {
                cout << "Circle with radius " << radius << ", area: " << area() << endl;
            }
        };
    }
}