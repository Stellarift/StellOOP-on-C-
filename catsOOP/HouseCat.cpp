#include "HouseCat.h"
#include <iostream>
using namespace std;

HouseCat::HouseCat(const string& name, int age, const string& color, const string& owner)
    : Cat(name, age, color), ownerName(owner) {
    cout << "HouseCat constructor: " << name << endl;
}

HouseCat::~HouseCat() {
    cout << "HouseCat destructor: " << name << endl;
}

void HouseCat::sound() const {
    cout << name << " мурлычет: Mrrr-mrrr" << endl;
}

void HouseCat::printInfo() const {
    Cat::printInfo();
    cout << ", Хозяин: " << ownerName << endl;
}

void HouseCat::play() const {
    cout << name << " играет с мячиком" << endl;
}