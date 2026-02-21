#include "Fraction.h"
#include <iostream>
#include <cmath>
using namespace std;

int Fraction::objectCount = 0;

int Fraction::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator == 0) {
        cout << "Знаменатель не может быть 0!" << endl;
        denominator = 1;
        return;
    }
    
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Основной конструктор
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    reduce();
    objectCount++;
    cout << "Дробь создана. Всего объектов: " << objectCount << endl;
}

// Делегирующие конструкторы
Fraction::Fraction() : Fraction(0, 1) {}
Fraction::Fraction(int num) : Fraction(num, 1) {}

// Конструктор копирования
Fraction::Fraction(const Fraction& other) 
    : numerator(other.numerator), denominator(other.denominator) {
    objectCount++;
    cout << "Дробь скопирована. Всего объектов: " << objectCount << endl;
}

Fraction::~Fraction() {
    objectCount--;
    cout << "Дробь удалена. Осталось: " << objectCount << endl;
}

int Fraction::getObjectCount() {
    return objectCount;
}

void Fraction::display() const {
    cout << numerator << "/" << denominator;
}