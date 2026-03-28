#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// задание 2
class DivisionByZeroException : public exception {
private:
    string message;
public:
    DivisionByZeroException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class SafeDivision {
public:
    static double divide(double a, double b) {
        if (b == 0) {
            throw DivisionByZeroException("Ошибка: деление на ноль невозможно!");
        }
        return a / b;
    }
};

// задание 3
class IntArray {
private:
    int* data;
    int size;

public:
    IntArray(int n) : size(n) {
        if (n <= 0) {
            throw invalid_argument("размер массива должен быть положительным");
        }
        data = new int[size];
        cout << "Создан массив размером " << size << endl;
    }
    
    ~IntArray() {
        delete[] data;
        cout << "Массив удалён" << endl;
    }
    
    int at(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка: индекс " + to_string(index) + 
                              " выходит за границы массива (0.." + to_string(size-1) + ")");
        }
        return data[index];
    }
    
    void setAt(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка: индекс " + to_string(index) + 
                              " выходит за границы массива (0.." + to_string(size-1) + ")");
        }
        data[index] = value;
    }
    
    int getSize() const { return size; }
};