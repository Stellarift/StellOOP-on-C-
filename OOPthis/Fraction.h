#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int chislitel;   // числитель
    int znamenatel;  // знаменатель
    
    void sokrashenie(); 

public:
    Fraction(int ch, int zn);
    Fraction();
    ~Fraction();
    
    void print();
    
    Fraction* slozhenie(const Fraction& other);
    Fraction* vychitanie(const Fraction& other);
    Fraction* umnozhenie(const Fraction& other);
    
    Fraction* slozhenie(int chislo);
    Fraction* vychitanie(int chislo);
    Fraction* umnozhenie(int chislo);
};

#endif