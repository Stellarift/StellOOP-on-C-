#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* data;
    int size;

public:
    Array();
    explicit Array(int n);
    Array(const Array& other);
    ~Array();
    
    void fillRandom();
    void display() const;
    
    int& operator[](int index);
    void operator()(int value);
    
    operator int() const;
    operator char*() const;
    
    int getSize() const;
};

#endif