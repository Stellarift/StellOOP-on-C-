#ifndef HOUSE_H
#define HOUSE_H
#include "Apartment.h"

class House {
private:
    Apartment** apartments;
    int apartmentCount;
    char* address;

public:
    House(const char* addr, int count);
    House(const House& other);
    House(House&& other) noexcept;
    ~House();
    
    void addApartment(const Apartment& apt);
    void display() const;
};

#endif