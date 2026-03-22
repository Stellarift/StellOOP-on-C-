#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    size_t capacity;
    size_t topIndex;
    
    void resize();

public:
    Stack(size_t initialCapacity = 10);
    Stack(const Stack& other);
    ~Stack();
    
    Stack& operator=(const Stack& other);
    
    void push(const T& value);
    void pop();
    T& top();
    
    bool empty() const;
    size_t size() const;
    void print() const;
};

#include "Stack.cpp"
#endif