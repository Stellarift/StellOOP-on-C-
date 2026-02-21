#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    static int objectCount;  // счетчик созданных объектов
    
    void reduce();
    int gcd(int a, int b) const;

public:
    // Конструкторы с делегированием
    Fraction();                                  // делегирует Fraction(0,1)
    Fraction(int num);                           // делегирует Fraction(num,1)
    Fraction(int num, int denom);                 // основной конструктор
    Fraction(const Fraction& other);              // копирования
    
    ~Fraction();
    
    static int getObjectCount();
    
    inline int getNumerator() const { return numerator; }
    inline int getDenominator() const { return denominator; }
    
    void display() const;
};

#endif