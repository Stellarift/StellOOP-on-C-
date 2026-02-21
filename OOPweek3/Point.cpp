#include "Point.h"
#include <iostream>
using namespace std;

int Point::objectCount = 0;

// Основной конструктор
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {
    objectCount++;
    cout << "Point создана. Всего объектов: " << objectCount << endl;
}

// Делегирующий конструктор (по умолчанию)
Point::Point() : Point(0.0, 0.0, 0.0) {}

// Конструктор копирования
Point::Point(const Point& other) : x(other.x), y(other.y), z(other.z) {
    objectCount++;
    cout << "Point скопирована. Всего объектов: " << objectCount << endl;
}

Point::~Point() {
    objectCount--;
    cout << "Point удалена. Осталось: " << objectCount << endl;
}

int Point::getObjectCount() {
    return objectCount;
}

void Point::display() const {
    cout << "Точка: (" << x << ", " << y << ", " << z << ")" << endl;
}