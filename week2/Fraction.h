#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    
    void reduce();
    int gcd(int a, int b) const;

public:
    Fraction();
    Fraction(int num, int denom);
    Fraction(const Fraction& other);
    
    ~Fraction();
    
    inline int getNumerator() const { return numerator; }
    inline int getDenominator() const { return denominator; }
    
    inline void setNumerator(int num) { 
        numerator = num; 
        reduce();
    }
    
    inline void setDenominator(int denom) { 
        if (denom != 0) {
            denominator = denom; 
            reduce();
        }
    }
    
    Fraction* add(const Fraction& other);
    Fraction* subtract(const Fraction& other);
    Fraction* multiply(const Fraction& other);
    
    Fraction* add(int number);
    Fraction* subtract(int number);
    Fraction* multiply(int number);
    
    void print() const;
};

#endif