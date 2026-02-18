#include "House.h"
#include <iostream>
#include <cstring>
using namespace std;

House::House(const char* adr, int count) : kolKvartir(count) {
    adres = new char[strlen(adr) + 1];
    strcpy(adres, adr);
    
    for (int i = 0; i < count; i++) {
        kvartiry[i] = nullptr;
    }
    cout << "Создаем дом по адресу " << adres << " для " << this << endl;
}

House::House(const House& other) : kolKvartir(other.kolKvartir) {
    adres = new char[strlen(other.adres) + 1];
    strcpy(adres, other.adres);
    
    for (int i = 0; i < kolKvartir; i++) {
        if (other.kvartiry[i]) {
            kvartiry[i] = new Apartment(*other.kvartiry[i]);
        } else {
            kvartiry[i] = nullptr;
        }
    }
    cout << "Копируем дом для " << this << endl;
}

House::~House() {
    delete[] adres;
    for (int i = 0; i < kolKvartir; i++) {
        delete kvartiry[i];
    }
    cout << "Уничтожаем дом для " << this << endl;
}

void House::dobavitKvartiru(const Apartment& apt) {
    int nomer = apt.getNomer();
    if (nomer >= 0 && nomer < kolKvartir) {
        if (kvartiry[nomer]) {
            delete kvartiry[nomer];
        }
        kvartiry[nomer] = new Apartment(apt);
    }
}

void House::print() {
    cout << "\nДОМ ПО АДРЕСУ " << adres << " --" << endl;
    cout << "Всего квартир: " << kolKvartir << endl;
    for (int i = 0; i < kolKvartir; i++) {
        if (kvartiry[i]) {
            kvartiry[i]->print();
            cout << endl;
        }
    }
}

const char* House::getAdres() { return adres; }
int House::getKolKvartir() { return kolKvartir; }
Apartment* House::getKvartira(int index) { 
    return (index >= 0 && index < kolKvartir) ? kvartiry[index] : nullptr; 
}