#include "Queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
void Queue<T>::resize() {
    size_t newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    
    for (size_t i = 0; i < queueSize; i++) {
        newData[i] = data[(frontIndex + i) % capacity];
    }
    
    delete[] data;
    data = newData;
    frontIndex = 0;
    backIndex = queueSize;
    capacity = newCapacity;
}

template <typename T>
Queue<T>::Queue(size_t initialCapacity) 
    : capacity(initialCapacity), frontIndex(0), backIndex(0), queueSize(0) {
    data = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue& other) 
    : capacity(other.capacity), frontIndex(other.frontIndex), 
      backIndex(other.backIndex), queueSize(other.queueSize) {
    data = new T[capacity];
    for (size_t i = 0; i < capacity; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        backIndex = other.backIndex;
        queueSize = other.queueSize;
        data = new T[capacity];
        for (size_t i = 0; i < capacity; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    if (queueSize >= capacity) {
        resize();
    }
    data[backIndex] = value;
    backIndex = (backIndex + 1) % capacity;
    queueSize++;
}

template <typename T>
void Queue<T>::dequeue() {
    if (empty()) {
        throw out_of_range("Очередь пуста");
    }
    frontIndex = (frontIndex + 1) % capacity;
    queueSize--;
}

template <typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw out_of_range("Очередь пуста");
    }
    return data[frontIndex];
}

template <typename T>
bool Queue<T>::empty() const {
    return queueSize == 0;
}

template <typename T>
size_t Queue<T>::size() const {
    return queueSize;
}

template <typename T>
void Queue<T>::print() const {
    cout << "Очередь (с начала): ";
    for (size_t i = 0; i < queueSize; i++) {
        cout << data[(frontIndex + i) % capacity] << " ";
    }
    cout << endl;
}