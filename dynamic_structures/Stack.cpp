#include "Stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
void Stack<T>::resize() {
    size_t newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for (size_t i = 0; i <= topIndex; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
Stack<T>::Stack(size_t initialCapacity) 
    : capacity(initialCapacity), topIndex(0) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack& other) 
    : capacity(other.capacity), topIndex(other.topIndex) {
    data = new T[capacity];
    for (size_t i = 0; i <= topIndex; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        topIndex = other.topIndex;
        data = new T[capacity];
        for (size_t i = 0; i <= topIndex; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (topIndex >= capacity) {
        resize();
    }
    data[topIndex++] = value;
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw out_of_range("Стек пуст");
    }
    topIndex--;
}

template <typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw out_of_range("Стек пуст");
    }
    return data[topIndex - 1];
}

template <typename T>
bool Stack<T>::empty() const {
    return topIndex == 0;
}

template <typename T>
size_t Stack<T>::size() const {
    return topIndex;
}

template <typename T>
void Stack<T>::print() const {
    cout << "Стек (сверху вниз): ";
    for (size_t i = topIndex; i > 0; i--) {
        cout << data[i - 1] << " ";
    }
    cout << endl;
}