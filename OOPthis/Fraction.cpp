#include "Fraction.h"
#include <iostream>
using namespace std;

//НОД
int naimenshiyDelitel(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

void Fraction::sokrashenie() {
    if (znamenatel == 0) {
        cout << "Ошибка: знаменатель не может быть 0!" << endl;
        znamenatel = 1;
        return;
    }
    
    int del = naimenshiyDelitel(chislitel, znamenatel);
    chislitel /= del;
    znamenatel /= del;
    
    if (znamenatel < 0) {
        chislitel = -chislitel;
        znamenatel = -znamenatel;
    }
}

Fraction::Fraction(int ch, int zn) {
    cout << "Создаем дробь для " << this << endl;
    chislitel = ch;
    znamenatel = zn;
    sokrashenie();
}

Fraction::Fraction() : Fraction(0, 1) {}

Fraction::~Fraction() {
    cout << "Уничтожаем дробь для " << this << endl;
}

void Fraction::print() {
    cout << chislitel << "/" << znamenatel;
}

Fraction* Fraction::slozhenie(const Fraction& other) {
    chislitel = chislitel * other.znamenatel + other.chislitel * znamenatel;
    znamenatel = znamenatel * other.znamenatel;
    sokrashenie();
    return this;
}

Fraction* Fraction::vychitanie(const Fraction& other) {
    chislitel = chislitel * other.znamenatel - other.chislitel * znamenatel;
    znamenatel = znamenatel * other.znamenatel;
    sokrashenie();
    return this;
}

Fraction* Fraction::umnozhenie(const Fraction& other) {
    chislitel *= other.chislitel;
    znamenatel *= other.znamenatel;
    sokrashenie();
    return this;
}

Fraction* Fraction::slozhenie(int chislo) {
    chislitel += chislo * znamenatel;
    sokrashenie();
    return this;
}

Fraction* Fraction::vychitanie(int chislo) {
    chislitel -= chislo * znamenatel;
    sokrashenie();
    return this;
}

Fraction* Fraction::umnozhenie(int chislo) {
    chislitel *= chislo;
    sokrashenie();
    return this;
}