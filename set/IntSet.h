#ifndef INTSET_H
#define INTSET_H

#include <iostream>
using namespace std;

class IntSet {
private:
    int* elements;
    int size;
    int capacity;
    
    void resize();
    bool contains(int value) const;

public:
    IntSet();
    IntSet(int initialCapacity);
    IntSet(const IntSet& other);
    
    ~IntSet();
    
    //Методы
    void add(int value);
    void remove(int value);
    void print() const;
    int getSize() const;
    
    //Перегрузка операторов
    IntSet& operator+=(int value);
    IntSet& operator-=(int value);
    
    IntSet operator+(const IntSet& other) const;
    IntSet operator-(const IntSet& other) const;
    IntSet operator*(const IntSet& other) const;
    
    IntSet& operator+=(const IntSet& other);
    IntSet& operator-=(const IntSet& other);
    IntSet& operator*=(const IntSet& other);
    
    IntSet& operator=(const IntSet& other);
    
    bool operator==(const IntSet& other) const;
    bool operator!=(const IntSet& other) const;
    
    //Дружественные функции для ввода/вывода
    friend ostream& operator<<(ostream& os, const IntSet& set);
    friend istream& operator>>(istream& is, IntSet& set);
};

#endif