#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;

int Person::count = 0;

Person::Person(int id, const char* fam, const char* im, 
               const char* otch, int d, int m, int y)
    : id(id), dataRozhdeniya(d, m, y) {
    
    familiya = new char[strlen(fam) + 1];
    strcpy(familiya, fam);
    
    imya = new char[strlen(im) + 1];
    strcpy(imya, im);
    
    if (otch) {
        otchestvo = new char[strlen(otch) + 1];
        strcpy(otchestvo, otch);
    } else {
        otchestvo = nullptr;
    }
    
    count++;
    cout << "Создаем человека для " << this << endl;
}

Person::Person() : Person(0, "Неизвестно", "Неизвестно", nullptr, 1, 1, 2000) {}

Person::Person(const Person& other) 
    : id(other.id), dataRozhdeniya(other.dataRozhdeniya) {
    
    familiya = new char[strlen(other.familiya) + 1];
    strcpy(familiya, other.familiya);
    
    imya = new char[strlen(other.imya) + 1];
    strcpy(imya, other.imya);
    
    if (other.otchestvo) {
        otchestvo = new char[strlen(other.otchestvo) + 1];
        strcpy(otchestvo, other.otchestvo);
    } else {
        otchestvo = nullptr;
    }
    
    count++;
    cout << "Копируем человека для " << this << endl;
}

Person::~Person() {
    delete[] familiya;
    delete[] imya;
    delete[] otchestvo;
    count--;
    cout << "Уничтожаем человека для " << this << endl;
}

int Person::getCount() {
    return count;
}

void Person::print() {
    cout << "ID: " << id << endl;
    cout << "Фамилия: " << (familiya ? familiya : "нет") << endl;
    cout << "Имя: " << (imya ? imya : "нет") << endl;
    cout << "Отчество: " << (otchestvo ? otchestvo : "нет") << endl;
    cout << "Дата рождения: ";
    dataRozhdeniya.print();
    cout << endl;
}

int Person::getId() { return id; }
const char* Person::getFamiliya() { return familiya; }
const char* Person::getImya() { return imya; }
const char* Person::getOtchestvo() { return otchestvo; }
Date Person::getDataRozhdeniya() { return dataRozhdeniya; }

void Person::setId(int newId) { id = newId; }

void Person::setFamiliya(const char* newFam) {
    delete[] familiya;
    familiya = new char[strlen(newFam) + 1];
    strcpy(familiya, newFam);
}

void Person::setImya(const char* newIm) {
    delete[] imya;
    imya = new char[strlen(newIm) + 1];
    strcpy(imya, newIm);
}

void Person::setOtchestvo(const char* newOtch) {
    delete[] otchestvo;
    if (newOtch) {
        otchestvo = new char[strlen(newOtch) + 1];
        strcpy(otchestvo, newOtch);
    } else {
        otchestvo = nullptr;
    }
}

void Person::setDataRozhdeniya(int d, int m, int y) {
    dataRozhdeniya = Date(d, m, y);
}