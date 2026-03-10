#include "Apartment.h"
#include <iostream>
using namespace std;

Apartment::Apartment(int num) : number(num), residentCount(0) {
    residents = new Person*[10];
    for (int i = 0; i < 10; i++) residents[i] = nullptr;
    cout << "Apartment constructor: #" << number << endl;
}

Apartment::Apartment(const Apartment& other) : number(other.number), residentCount(other.residentCount) {
    residents = new Person*[10];
    for (int i = 0; i < residentCount; i++) {
        residents[i] = new Person(*other.residents[i]);
    }
    for (int i = residentCount; i < 10; i++) residents[i] = nullptr;
    cout << "Apartment copy constructor: #" << number << endl;
}

Apartment::Apartment(Apartment&& other) noexcept 
    : residents(other.residents), residentCount(other.residentCount), number(other.number) {
    other.residents = nullptr;
    other.residentCount = 0;
    cout << "Apartment move constructor: #" << number << endl;
}

Apartment::~Apartment() {
    cout << "Apartment destructor: #" << number << endl;
    if (residents) {
        for (int i = 0; i < residentCount; i++) {
            delete residents[i];
        }
        delete[] residents;
    }
}

void Apartment::addResident(const Person& p) {
    if (residentCount < 10) {
        residents[residentCount] = new Person(p);
        residentCount++;
    }
}

void Apartment::display() const {
    cout << "Apartment #" << number << " (" << residentCount << " residents)" << endl;
    for (int i = 0; i < residentCount; i++) {
        cout << "  ";
        residents[i]->display();
    }
}