#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Garage {
private:
    T* data;
    int capacity;
    int count;
    static int garageCount;

public:
    Garage() : data(nullptr), capacity(0), count(0) { garageCount++; }
    
    explicit Garage(int cap) : capacity(cap), count(0) {
        data = new T[capacity];
        garageCount++;
    }
    
    Garage(const Garage& other) : capacity(other.capacity), count(other.count) {
        data = new T[capacity];
        for (int i = 0; i < count; i++) data[i] = other.data[i];
        garageCount++;
    }
    
    ~Garage() {
        delete[] data;
        garageCount--;
    }
    
    Garage& operator=(const Garage& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            count = other.count;
            data = new T[capacity];
            for (int i = 0; i < count; i++) data[i] = other.data[i];
        }
        return *this;
    }
    
    static int getTotalGarages() { return garageCount; }
    
    Garage& add(const T& item) {
        if (count >= capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[newCap];
            for (int i = 0; i < count; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCap;
        }
        data[count++] = item;
        return *this;
    }
    
    int getCount() const { return count; }
    
    T& operator[](int index) {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        return data[index];
    }
    
    const T& operator[](int index) const {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        return data[index];
    }
    
    Garage<T> operator+(const Garage<T>& other) const {
        Garage<T> result(count + other.count);
        for (int i = 0; i < count; i++) result.add(data[i]);
        for (int i = 0; i < other.count; i++) result.add(other.data[i]);
        return result;
    }
};

template <typename T>
int Garage<T>::garageCount = 0;