#ifndef APARTMENT_H
#define APARTMENT_H
#include "Person.h"

class Apartment {
private:
    Person** residents;
    int residentCount;
    int number;

public:
    Apartment(int num);
    Apartment(const Apartment& other);
    Apartment(Apartment&& other) noexcept;
    ~Apartment();
    
    void addResident(const Person& p);
    void display() const;
};

#endif