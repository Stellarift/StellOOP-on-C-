#include "PersianCat.h"
#include <iostream>
using namespace std;

PersianCat::PersianCat(const string& name, int age, const string& color, int woolLength)
    : Cat(name, age, color), woolLength(woolLength) {
    cout << "PersianCat constructor: " << name << endl;
}

PersianCat::~PersianCat() {
    cout << "PersianCat destructor: " << name << endl;
}

void PersianCat::sound() const {
    cout << name << " мягко говорит: Meow" << endl;
}

void PersianCat::printInfo() const {
    Cat::printInfo();
    cout << ", Длина шерсти: " << woolLength << " см" << endl;
}

void PersianCat::groom() const {
    cout << name << " нуждается в груминге" << endl;
}