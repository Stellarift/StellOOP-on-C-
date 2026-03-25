#pragma once

#include <iostream>
#include <string>
using namespace std;

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() = default;
};

class Circle : public Drawable, public Serializable {
    int x, y;
    double radius;
public:
    Circle(int x, int y, double r) : x(x), y(y), radius(r) {}
    
    void draw() const override {
        cout << "Drawing circle at (" << x << "," << y << ") with radius " << radius << endl;
    }
    
    string serialize() const override {
        return "Circle " + to_string(x) + " " + to_string(y) + " " + to_string(radius);
    }
};

class Rectangle : public Drawable, public Serializable {
    int x, y;
    double width, height;
public:
    Rectangle(int x, int y, double w, double h) : x(x), y(y), width(w), height(h) {}
    
    void draw() const override {
        cout << "Drawing rectangle at (" << x << "," << y << ") width " << width << " height " << height << endl;
    }
    
    string serialize() const override {
        return "Rectangle " + to_string(x) + " " + to_string(y) + " " + to_string(width) + " " + to_string(height);
    }
};