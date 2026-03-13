#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using namespace std;

class IntArray {
private:
    int* data;
    size_t size;

public:
    IntArray();
    explicit IntArray(size_t n);
    IntArray(const IntArray& other);
    IntArray(IntArray&& other) noexcept;
    ~IntArray();
    
    IntArray& operator=(const IntArray& other);
    IntArray& operator=(IntArray&& other) noexcept;
    
    void print() const;
    size_t getSize() const;
};

#endif