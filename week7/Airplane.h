#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <string>
using namespace std;

class Airplane {
private:
    string type;
    int maxPassengers;
    int currentPassengers;

public:
    Airplane();
    Airplane(const string& t, int max);
    Airplane(const Airplane& other);
    
    string getType() const;
    int getMaxPassengers() const;
    int getCurrentPassengers() const;
    
    void setType(const string& t);
    void setMaxPassengers(int max);
    void print() const;
    
    bool operator==(const Airplane& other) const;
    bool operator>=(const Airplane& other) const;
    
    Airplane& operator++();      // префиксный ++
    Airplane& operator--();      // префиксный --
    
    Airplane operator++(int);    // постфиксный ++
    Airplane operator--(int);    // постфиксный --
};

#endif