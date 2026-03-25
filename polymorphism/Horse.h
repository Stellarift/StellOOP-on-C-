#pragma once

#include "Animal.h"

class Horse : public Animal {
public:
    void speak() const override {
        cout << "Neigh!" << endl;
    }
};