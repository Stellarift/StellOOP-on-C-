#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double r, double i);
    Complex(const Complex& other);
    
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);
    
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    
    friend bool operator==(const Complex& a, const Complex& b);
    friend bool operator!=(const Complex& a, const Complex& b);
    
    // Перегрузка оператора
    double operator()() const;
    
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
};

#endif