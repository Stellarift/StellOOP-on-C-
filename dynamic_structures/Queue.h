#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    size_t capacity;
    size_t frontIndex;
    size_t backIndex;
    size_t queueSize;
    
    void resize();

public:
    Queue(size_t initialCapacity = 10);
    Queue(const Queue& other);
    ~Queue();
    
    Queue& operator=(const Queue& other);
    
    void enqueue(const T& value);
    void dequeue();
    T& front();
    
    bool empty() const;
    size_t size() const;
    void print() const;
};

#include "Queue.cpp"
#endif