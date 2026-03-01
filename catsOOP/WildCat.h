#ifndef WILDCAT_H
#define WILDCAT_H

#include "Cat.h"

class WildCat : public Cat {
private:
    string habitat;

public:
    WildCat(const string& name, int age, const string& color, const string& habitat);
    ~WildCat();
    
    void sound() const;
    void printInfo() const;
    
    void hunt() const;
};

#endif