#include "IntSet.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Конструктор по умолчанию
IntSet::IntSet() : size(0), capacity(10) {
    elements = new int[capacity];
}

// Конструктор с заданной вместимостью
IntSet::IntSet(int initialCapacity) : size(0), capacity(initialCapacity) {
    elements = new int[capacity];
}

// Конструктор копирования
IntSet::IntSet(const IntSet& other) : size(other.size), capacity(other.capacity) {
    elements = new int[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

IntSet::~IntSet() {
    delete[] elements;
}

//Проверка наличия элемента
bool IntSet::contains(int value) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) return true;
    }
    return false;
}

// Увеличение вместимости при необходимости
void IntSet::resize() {
    capacity *= 2;
    int* newElements = new int[capacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

// Добавление элемента
void IntSet::add(int value) {
    if (!contains(value)) {
        if (size >= capacity) resize();
        elements[size++] = value;
    }
}

// Удаление элемента
void IntSet::remove(int value) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            for (int j = i; j < size - 1; j++) {
                elements[j] = elements[j + 1];
            }
            size--;
            return;
        }
    }
}

// Вывод множества
void IntSet::print() const {
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << elements[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "}";
}

// Получение размера
int IntSet::getSize() const {
    return size;
}

// += для одного элемента
IntSet& IntSet::operator+=(int value) {
    add(value);
    return *this;
}

// -= для одного элемента
IntSet& IntSet::operator-=(int value) {
    remove(value);
    return *this;
}

// + для двух множеств (объединение)
IntSet IntSet::operator+(const IntSet& other) const {
    IntSet result(capacity + other.capacity);
    
    //  все элементы из первого множества
    for (int i = 0; i < size; i++) {
        result.add(elements[i]);
    }
    
    // все элементы из второго множества
    for (int i = 0; i < other.size; i++) {
        result.add(other.elements[i]);
    }
    
    return result;
}

// - для двух множеств (разность)
IntSet IntSet::operator-(const IntSet& other) const {
    IntSet result(capacity);
    
    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    
    return result;
}

// * для двух множеств (пересечение)
IntSet IntSet::operator*(const IntSet& other) const {
    IntSet result(capacity < other.capacity ? capacity : other.capacity);
    
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    
    return result;
}

// += для двух множеств (объединение)
IntSet& IntSet::operator+=(const IntSet& other) {
    for (int i = 0; i < other.size; i++) {
        add(other.elements[i]);
    }
    return *this;
}

// -= для двух множеств (разность)
IntSet& IntSet::operator-=(const IntSet& other) {
    for (int i = 0; i < other.size; i++) {
        remove(other.elements[i]);
    }
    return *this;
}

// *= для двух множеств (пересечение)
IntSet& IntSet::operator*=(const IntSet& other) {
    IntSet result = *this * other;
    *this = result;
    return *this;
}

// Оператор присваивания
IntSet& IntSet::operator=(const IntSet& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        capacity = other.capacity;
        elements = new int[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

// Оператор сравнения ==
bool IntSet::operator==(const IntSet& other) const {
    if (size != other.size) return false;
    
    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) return false;
    }
    
    return true;
}

// Оператор сравнения !=
bool IntSet::operator!=(const IntSet& other) const {
    return !(*this == other);
}

// Оператор вывода
ostream& operator<<(ostream& os, const IntSet& set) {
    os << "{";
    for (int i = 0; i < set.size; i++) {
        os << set.elements[i];
        if (i < set.size - 1) os << ", ";
    }
    os << "}";
    return os;
}

// Оператор ввода
istream& operator>>(istream& is, IntSet& set) {
    int value;
    cout << "Введите элементы множества (0 для окончания):" << endl;
    while (true) {
        is >> value;
        if (value == 0) break;
        set.add(value);
    }
    return is;
}