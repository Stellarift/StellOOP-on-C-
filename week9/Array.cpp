#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

Array::Array() : size(10) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
    cout << "Конструктор Array по умолчанию" << endl;
}

Array::Array(int n) : size(n) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
    cout << "Конструктор Array с размером " << size << endl;
}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    cout << "Конструктор копирования Array" << endl;
}

Array::~Array() {
    cout << "Деструктор Array" << endl;
    delete[] data;
}

void Array::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
}

void Array::display() const {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int& Array::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Индекс за пределами массива!" << endl;
        return data[0];
    }
    return data[index];
}

void Array::operator()(int value) {
    for (int i = 0; i < size; i++) {
        data[i] += value;
    }
}

Array::operator int() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

Array::operator char*() const {
    char* result = new char[256];
    result[0] = '\0';
    char buffer[20];
    
    for (int i = 0; i < size; i++) {
        sprintf(buffer, "%d ", data[i]);
        strcat(result, buffer);
    }
    
    return result;
}

int Array::getSize() const { return size; }