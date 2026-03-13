#include "Buffer.h"
#include <iostream>
#include <cstring>
using namespace std;

Buffer::Buffer(size_t n) : size(n) {
    cout << "Конструктор Buffer: выделение памяти под " << n << " байт" << endl;
    data = new char[size];
    memset(data, 0, size);
}

Buffer::Buffer(const Buffer& other) : size(other.size) {
    cout << "Конструктор копирования Buffer" << endl;
    data = new char[size];
    memcpy(data, other.data, size);
}

Buffer::Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
    cout << "Конструктор перемещения Buffer" << endl;
    other.data = nullptr;
    other.size = 0;
}

Buffer::~Buffer() {
    cout << "Деструктор Buffer: освобождаем память " << data << endl;
    if (data){
    delete[] data;}
}

Buffer& Buffer::operator=(const Buffer& other) {
    cout << "Оператор присваивания копированием Buffer" << endl;
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new char[size];
        memcpy(data, other.data, size);
    }
    return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    cout << "Оператор присваивания перемещением Buffer" << endl;
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

void Buffer::print() const {
    cout << "Buffer(" << size << " байт)";
    if (data) {
        cout << " - данные есть";
    } else {
        cout << " - ПУСТОЙ";
    }
    cout << endl;
}