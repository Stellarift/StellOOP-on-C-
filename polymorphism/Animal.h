#pragma once

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const {
        cout << "I am an animal" << endl;
    }
    
    virtual ~Animal() = default;
};