#include "Airplane.h"
#include <iostream>
using namespace std;

Airplane::Airplane() : type("Unknown"), maxPassengers(100), currentPassengers(0) {
    cout << "Конструктор Airplane по умолчанию" << endl;
}

Airplane::Airplane(const string& t, int max) : type(t), maxPassengers(max), currentPassengers(0) {
    cout << "Конструктор Airplane: " << type << ", макс. пассажиров=" << maxPassengers << endl;
}

Airplane::Airplane(const Airplane& other) 
    : type(other.type), maxPassengers(other.maxPassengers), currentPassengers(other.currentPassengers) {
    cout << "Конструктор копирования Airplane" << endl;
}

string Airplane::getType() const {
    return type;
}

int Airplane::getMaxPassengers() const {
    return maxPassengers;
}

int Airplane::getCurrentPassengers() const {
    return currentPassengers;
}

void Airplane::setType(const string& t) {
    type = t;
}

void Airplane::setMaxPassengers(int max) {
    maxPassengers = max;
}

void Airplane::print() const {
    cout << "Самолёт " << type << ": пассажиров " << currentPassengers 
         << "/" << maxPassengers << endl;
}

bool Airplane::operator==(const Airplane& other) const {
    return type == other.type;
}

bool Airplane::operator>=(const Airplane& other) const {
    return maxPassengers >= other.maxPassengers;
}

// Префиксный ++ 
Airplane& Airplane::operator++() {
    if (currentPassengers < maxPassengers) {
        currentPassengers++;
        cout << "Префиксный ++: добавлен пассажир. Теперь: " << currentPassengers << endl;
    } else {
        cout << "Нет мест! Максимум " << maxPassengers << " пассажиров" << endl;
    }
    return *this;
}

// Префиксный -- 
Airplane& Airplane::operator--() {
    if (currentPassengers > 0) {
        currentPassengers--;
        cout << "Префиксный --: вышел пассажир. Осталось: " << currentPassengers << endl;
    } else {
        cout << "В самолёте нет пассажиров" << endl;
    }
    return *this;
}

// Постфиксный ++ 
Airplane Airplane::operator++(int) {
    Airplane temp = *this;
    if (currentPassengers < maxPassengers) {
        currentPassengers++;
        cout << "Постфиксный ++: добавлен пассажир. Теперь: " << currentPassengers << endl;
    } else {
        cout << "Нет мест! Максимум " << maxPassengers << " пассажиров" << endl;
    }
    return temp;
}

// Постфиксный -- 
Airplane Airplane::operator--(int) {
    Airplane temp = *this;
    if (currentPassengers > 0) {
        currentPassengers--;
        cout << "Постфиксный --: вышел пассажир. Осталось: " << currentPassengers << endl;
    } else {
        cout << "В самолёте нет пассажиров" << endl;
    }
    return temp;
}