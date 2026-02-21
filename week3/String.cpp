#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

// Инициализация статического счетчика
int String::objectCount = 0;

// Конструктор по умолчанию (создает строку длиной 80)
String::String() : length(80) {
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
    cout << "Конструктор по умолчанию (80 символов). Объектов: " 
         << objectCount << endl;
}

// Конструктор с параметром (произвольный размер)
String::String(int size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
    cout << "Конструктор с размером " << size 
         << ". Объектов: " << objectCount << endl;
}

// Конструктор с инициализацией строкой
String::String(const char* input) {
    length = strlen(input);
    str = new char[length + 1];
    strcpy(str, input);
    objectCount++;
    cout << "Конструктор со строкой \"" << input 
         << "\". Объектов: " << objectCount << endl;
}

// Конструктор копирования
String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
    objectCount++;
    cout << "Конструктор копирования. Объектов: " 
         << objectCount << endl;
}

// Деструктор
String::~String() {
    cout << "Деструктор для строки \"" << str 
         << "\". Объектов осталось: " << objectCount - 1 << endl;
    delete[] str;
    objectCount--;
}

// Ввод
void String::input() {
    cout << "Введите строку: ";
    
    // Временный буфер для ввода
    char buffer[1000];
    cin.getline(buffer, 1000);
    
    // перевыделяем память
    int newLength = strlen(buffer);
    if (newLength > length) {
        delete[] str;
        length = newLength;
        str = new char[length + 1];
    }
    
    strcpy(str, buffer);
}

// Вывод
void String::output() const {
    cout << "Строка: \"" << str << "\" (длина: " << length << ")" << endl;
}

// Статическая функция
int String::getObjectCount() {
    return objectCount;
}