#include "Circle.h"
#include <iostream>
#include <cmath>
using namespace std;

const double Circle::PI = 3.14159265358979323846;

Circle::Circle() : radius(1.0) {
    cout << "Конструктор Circle по умолчанию (радиус=1)" << endl;
}

Circle::Circle(double r) : radius(r) {
    cout << "Конструктор Circle с радиусом " << r << endl;
}

Circle::Circle(const Circle& other) : radius(other.radius) {
    cout << "Конструктор копирования Circle" << endl;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getLength() const {
    return 2 * PI * radius;
}

void Circle::setRadius(double r) {
    radius = r;
}

void Circle::print() const {
    cout << "Окружность: радиус=" << radius 
         << ", длина=" << getLength() << endl;
}

bool Circle::operator==(const Circle& other) const {
    return radius == other.radius;
}

bool Circle::operator>(const Circle& other) const {
    return getLength() > other.getLength();
}

Circle& Circle::operator+=(double value) {
    if (radius + value > 0) {
        radius += value;
        cout << "Радиус увеличен на " << value << ". Новый радиус: " << radius << endl;
    } else {
        cout << "Ошибка: радиус не может стать <= 0" << endl;
    }
    return *this;
}

Circle& Circle::operator-=(double value) {
    if (radius - value > 0) {
        radius -= value;
        cout << "Радиус уменьшен на " << value << ". Новый радиус: " << radius << endl;
    } else {
        cout << "Ошибка: радиус не может стать <= 0" << endl;
    }
    return *this;
}