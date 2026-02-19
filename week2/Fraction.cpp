#include "Fraction.h"
#include <iostream>
using namespace std;

int Fraction::gcd(int a, int b) const {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator == 0) {
        cout << "Знаменатель не может быть равен нулю!" << endl;
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

Fraction::Fraction() : numerator(0), denominator(1) {
    cout << "Конструктор дроби (по умолчанию) для " << this << endl;
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    cout << "Конструктор дроби (с параметрами) для " << this << endl;
    reduce();
}

Fraction::Fraction(const Fraction& other) 
    : numerator(other.numerator), denominator(other.denominator) {
    cout << "Конструктор копирования дроби для " << this << endl;
}

Fraction::~Fraction() {
    cout << "Деструктор дроби для " << this << endl;
}

void Fraction::print() const {
    cout << numerator << "/" << denominator;
}

Fraction* Fraction::add(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator = denominator * other.denominator;
    reduce();
    cout << "Выполнено сложение дробей" << endl;
    return this;
}

Fraction* Fraction::subtract(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator = denominator * other.denominator;
    reduce();
    cout << "Выполнено вычитание дробей" << endl;
    return this;
}

Fraction* Fraction::multiply(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    reduce();
    cout << "Выполнено умножение дробей" << endl;
    return this;
}

Fraction* Fraction::add(int number) {
    numerator += number * denominator;
    reduce();
    cout << "Выполнено сложение с целым числом" << endl;
    return this;
}

Fraction* Fraction::subtract(int number) {
    numerator -= number * denominator;
    reduce();
    cout << "Выполнено вычитание целого числа" << endl;
    return this;
}

Fraction* Fraction::multiply(int number) {
    numerator *= number;
    reduce();
    cout << "Выполнено умножение на целое число" << endl;
    return this;
}