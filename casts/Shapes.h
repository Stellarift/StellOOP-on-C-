#pragma once

#include <iostream>
using namespace std;

// Базовый класс
class Shape {
public:
    virtual void draw() const {
        cout << "Drawing shape" << endl;
    }
    virtual ~Shape() = default;
};

// Производный класс Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override {
        cout << "Drawing circle (radius = " << radius << ")" << endl;
    }
};

// Производный класс Rectangle
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() const override {
        cout << "Drawing rectangle (width = " << width << ", height = " << height << ")" << endl;
    }
};