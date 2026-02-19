#include "Point.h"
#include <iostream>
#include <fstream>
using namespace std;

Point::Point() : x(0.0), y(0.0), z(0.0) {
    cout << "Конструктор точки (по умолчанию) для " << this << endl;
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {
    cout << "Конструктор точки (с параметрами) для " << this << endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y), z(other.z) {
    cout << "Конструктор копирования точки для " << this << endl;
}

Point::~Point() {
    cout << "Деструктор точки для " << this << endl;
}

void Point::inputData() {
    cout << "Введите координату X: ";
    cin >> x;
    cout << "Введите координату Y: ";
    cin >> y;
    cout << "Введите координату Z: ";
    cin >> z;
}

void Point::displayData() const {
    cout << "Точка: (" << x << ", " << y << ", " << z << ")" << endl;
}

void Point::saveToFile(const char* filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << x << " " << y << " " << z;
        file.close();
        cout << "Данные сохранены в файл " << filename << endl;
    } else {
        cout << "Ошибка: не удалось открыть файл для записи!" << endl;
    }
}

void Point::loadFromFile(const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> x >> y >> z;
        file.close();
        cout << "Данные загружены из файла " << filename << endl;
    } else {
        cout << "Ошибка: не удалось открыть файл для чтения!" << endl;
    }
}