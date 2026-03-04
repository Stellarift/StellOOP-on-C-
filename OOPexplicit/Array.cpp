#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Array::Array() : size(10) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
    cout << "Array default constructor (size=10)" << endl;
}

Array::Array(int n) : size(n) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
    cout << "Array constructor with size=" << size << endl;
}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    cout << "Array copy constructor" << endl;
}

Array::~Array() {
    cout << "Array destructor for size=" << size << endl;
    delete[] data;
}

void Array::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
    cout << "Array filled with random numbers" << endl;
}

void Array::fillFromKeyboard() {
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]: ";
        cin >> data[i];
    }
}

void Array::display() const {
    cout << "Array (size=" << size << "): ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Array::resize(int newSize) {
    int* newData = new int[newSize];
    int minSize = (newSize < size) ? newSize : size;
    for (int i = 0; i < minSize; i++) newData[i] = data[i];
    for (int i = minSize; i < newSize; i++) newData[i] = 0;
    
    delete[] data;
    data = newData;
    size = newSize;
    cout << "Array resized to " << size << endl;
}

void Array::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted" << endl;
}

int Array::getMin() const {
    if (size == 0) 
    return 0;
    int minVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < minVal) minVal = data[i];
    }
    return minVal;
}

int Array::getMax() const {
    if (size == 0) return 0;
    int maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) maxVal = data[i];
    }
    return maxVal;
}

int Array::getSize() const {
    return size;
}