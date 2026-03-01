#include "WildCat.h"
#include <iostream>
using namespace std;

WildCat::WildCat(const string& name, int age, const string& color, const string& habitat)
    : Cat(name, age, color), habitat(habitat) {
    cout << "WildCat constructor: " << name << endl;
}

WildCat::~WildCat() {
    cout << "WildCat destructor: " << name << endl;
}

void WildCat::sound() const {
    cout << name << " рычит: Rrrr!" << endl;
}

void WildCat::printInfo() const {
    Cat::printInfo();
    cout << ", Среда обитания: " << habitat << endl;
}

void WildCat::hunt() const {
    cout << name << " охотится" << endl;
}