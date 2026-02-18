#ifndef HOUSE_H
#define HOUSE_H
#include "Apartment.h"

class House {
private:
    Apartment* kvartiry[20];
    int kolKvartir;
    char* adres;

public:
    House(const char* adr, int count);
    House(const House& other);
    ~House();
    
    void dobavitKvartiru(const Apartment& apt);
    void print();
    
    const char* getAdres();
    int getKolKvartir();
    Apartment* getKvartira(int index);
};

#endif