#ifndef PERSIANCAT_H
#define PERSIANCAT_H

#include "Cat.h"

class PersianCat : public Cat {
private:
    int woolLength;

public:
    PersianCat(const string& name, int age, const string& color, int woolLength);
    ~PersianCat();
    
    void sound() const;
    void printInfo() const;
    
    void groom() const;
};

#endif