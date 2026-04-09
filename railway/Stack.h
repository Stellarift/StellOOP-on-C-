#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(const T& item) {
        data.push_back(item);
    }
    
    void pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        data.pop_back();
    }
    
    T& top() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return data.back();
    }
    
    const T& top() const {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return data.back();
    }
    
    bool empty() const {
        return data.empty();
    }
    
    size_t size() const {
        return data.size();
    }
    
    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
};