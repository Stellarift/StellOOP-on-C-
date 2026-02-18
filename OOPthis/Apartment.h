#ifndef APARTMENT_H
#define APARTMENT_H
#include "Person.h"

class Apartment {
private:
    Person* zhiltsy[10];
    int kolZhiltsov;
    int nomerKvartiry;

public:
    Apartment(int nomer);
    Apartment(const Apartment& other);
    ~Apartment();
    
    void dobavitZhiltza(const Person& person);
    void print();
    
    int getNomer() const;
    int getKolZhiltsov();
    Person* getZhilets(int index);
};

#endif