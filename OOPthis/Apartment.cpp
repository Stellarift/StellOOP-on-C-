#include "Apartment.h"
#include <iostream>
using namespace std;

Apartment::Apartment(int nomer) : nomerKvartiry(nomer), kolZhiltsov(0) {
    for (int i = 0; i < 10; i++) {
        zhiltsy[i] = nullptr;
    }
    cout << "Создаем квартиру " << nomerKvartiry << " для " << this << endl;
}

Apartment::Apartment(const Apartment& other) 
    : nomerKvartiry(other.nomerKvartiry), kolZhiltsov(other.kolZhiltsov) {
    
    for (int i = 0; i < kolZhiltsov; i++) {
        zhiltsy[i] = new Person(*other.zhiltsy[i]);
    }
    for (int i = kolZhiltsov; i < 10; i++) {
        zhiltsy[i] = nullptr;
    }
    cout << "Копируем квартиру для " << this << endl;
}

Apartment::~Apartment() {
    for (int i = 0; i < kolZhiltsov; i++) {
        delete zhiltsy[i];
    }
    cout << "Уничтожаем квартиру " << nomerKvartiry << " для " << this << endl;
}

void Apartment::dobavitZhiltza(const Person& person) {
    if (kolZhiltsov < 10) {
        zhiltsy[kolZhiltsov] = new Person(person);
        kolZhiltsov++;
    }
}

void Apartment::print() {
    cout << "Квартира #" << nomerKvartiry << " (жильцов: " << kolZhiltsov << "):" << endl;
    for (int i = 0; i < kolZhiltsov; i++) {
        cout << "  Жилец " << i + 1 << ":" << endl;
        zhiltsy[i]->print();
    }
}

int Apartment::getNomer() const { return nomerKvartiry; }
int Apartment::getKolZhiltsov() { return kolZhiltsov; }
Person* Apartment::getZhilets(int index) { 
    return (index >= 0 && index < kolZhiltsov) ? zhiltsy[index] : nullptr; 
}