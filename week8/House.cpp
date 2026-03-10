#include "House.h"
#include <iostream>
#include <cstring>
using namespace std;

House::House(const char* addr, int count) : apartmentCount(count) {
    address = new char[strlen(addr) + 1];
    strcpy(address, addr);
    apartments = new Apartment*[count];
    for (int i = 0; i < count; i++) apartments[i] = nullptr;
    cout << "House constructor: " << address << endl;
}

House::House(const House& other) : apartmentCount(other.apartmentCount) {
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);
    apartments = new Apartment*[apartmentCount];
    for (int i = 0; i < apartmentCount; i++) {
        if (other.apartments[i]) {
            apartments[i] = new Apartment(*other.apartments[i]);
        } else {
            apartments[i] = nullptr;
        }
    }
    cout << "House copy constructor: " << address << endl;
}

House::House(House&& other) noexcept 
    : apartments(other.apartments), apartmentCount(other.apartmentCount), address(other.address) {
    other.apartments = nullptr;
    other.address = nullptr;
    cout << "House move constructor: " << address << endl;
}

House::~House() {
    cout << "House destructor: " << (address ? address : "nullptr") << endl;
    delete[] address;
    if (apartments) {
        for (int i = 0; i < apartmentCount; i++) {
            delete apartments[i];
        }
        delete[] apartments;
    }
}

void House::addApartment(const Apartment& apt) {
    for (int i = 0; i < apartmentCount; i++) {
        if (!apartments[i]) {
            apartments[i] = new Apartment(apt);
            break;
        }
    }
}

void House::display() const {
    cout << "House at " << address << " (" << apartmentCount << " apartments)" << endl;
    for (int i = 0; i < apartmentCount; i++) {
        if (apartments[i]) {
            apartments[i]->display();
        }
    }
}