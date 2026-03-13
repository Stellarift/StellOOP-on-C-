#include "IntArray.h"
#include <iostream>
#include <cstring>
using namespace std;

IntArray::IntArray() : data(nullptr), size(0) {
    cout << "Конструктор по умолчанию: пустой массив" << endl;
}

IntArray::IntArray(size_t n) : size(n) {
    cout << "Конструктор от size_t: выделение памяти под " << n << " элементов" << endl;
    data = new int[size];
    for (size_t i = 0; i < size; i++) {
        data[i] = 0;
    }
}

IntArray::IntArray(const IntArray& other) : size(other.size) {
    cout << "Конструктор копирования: глубокое копирование " << other.size << " элементов" << endl;
    
    if (size > 0) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

IntArray::IntArray(IntArray&& other) noexcept 
    : data(other.data), size(other.size) {
    cout << "Конструктор перемещения: забираем ресурс у " << &other << endl;
    
    other.data = nullptr;
    other.size = 0;
}

IntArray::~IntArray() {
    cout << "Деструктор: освобождаем память " << data << endl;
    delete[] data;
}

IntArray& IntArray::operator=(const IntArray& other) {
    cout << "Оператор присваивания копированием" << endl;
    
    if (this != &other) {
        delete[] data;
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    
    return *this;
}

IntArray& IntArray::operator=(IntArray&& other) noexcept {
    cout << "Оператор присваивания перемещением" << endl;
    
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    
    return *this;
}

void IntArray::print() const {
    cout << "[";
    for (size_t i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "] (size: " << size << ")" << endl;
}

size_t IntArray::getSize() const {
    return size;
}