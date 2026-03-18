#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex() : real(0.0), imag(0.0) {
    cout << "Complex default constructor" << endl;
}

Complex::Complex(double r, double i) : real(r), imag(i) {
    cout << "Complex constructor: " << real << " + " << imag << "i" << endl;
}

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {
    cout << "Complex copy constructor" << endl;
}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// Дружественные функции
Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

bool operator==(const Complex& a, const Complex& b) {
    return (a.real == b.real && a.imag == b.imag);
}

bool operator!=(const Complex& a, const Complex& b) {
    return !(a == b);
}

double Complex::operator()() const {
    return sqrt(real * real + imag * imag);
}

// Оператор вывода
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
    return os;
}

// Оператор ввода
istream& operator>>(istream& is, Complex& c) {
    cout << "Введите действительную часть: ";
    is >> c.real;
    cout << "Введите мнимую часть: ";
    is >> c.imag;
    return is;
}