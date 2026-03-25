#pragma once

#include "Animal.h"

class Cow : public Animal {
public:
    void speak() const override {
        cout << "Moo!" << endl;
    }
};