#ifndef VAR_H
#define VAR_H
#include "String.h"

enum VarType { VAR_INT, VAR_DOUBLE, VAR_STRING };

class Var {
private:
    VarType type;
    union {
        int intValue;
        double doubleValue;
        String* stringValue;
    };

public:
    Var();
    Var(int value);
    Var(double value);
    Var(const char* value);
    Var(const Var& other);
    ~Var();
    
    Var& operator=(const Var& other);
    
    Var operator+(const Var& other) const;
    Var operator-(const Var& other) const;
    Var operator*(const Var& other) const;
    Var operator/(const Var& other) const;
    
    Var& operator+=(const Var& other);
    Var& operator-=(const Var& other);
    Var& operator*=(const Var& other);
    Var& operator/=(const Var& other);
    
    bool operator==(const Var& other) const;
    bool operator!=(const Var& other) const;
    bool operator<(const Var& other) const;
    bool operator>(const Var& other) const;
    bool operator<=(const Var& other) const;
    bool operator>=(const Var& other) const;
    
    void print() const;
    VarType getType() const;
};

#endif