#ifndef HOUSECAT_H
#define HOUSECAT_H

#include "Cat.h"

class HouseCat : public Cat {
private:
    string ownerName;

public:
    HouseCat(const string& name, int age, const string& color, const string& owner);
    ~HouseCat();
    
    void sound() const;
    void printInfo() const;
    
    void play() const;
};

#endif