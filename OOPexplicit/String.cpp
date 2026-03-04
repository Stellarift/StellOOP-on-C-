#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

String::String() : length(80) {
    str = new char[length + 1];
    str[0] = '\0';
    cout << "String default constructor (80)" << endl;
}

//explicit-произвольный размер
String::String(int size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    cout << "String constructor with size: " << size << endl;
}

// Конструктор с инициализацией строкой
String::String(const char* input) {
    length = strlen(input);
    str = new char[length + 1];
    strcpy(str, input);
    cout << "String constructor from C-string: \"" << input << "\"" << endl;
}

String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
    cout << "String copy constructor: \"" << str << "\"" << endl;
}

String::~String() {
    cout << "String destructor: \"" << str << "\"" << endl;
    delete[] str;
}

void String::input() {
    char buffer[1000];
    cout << "Введите строку: ";
    cin.getline(buffer, 1000);
    
    int newLen = strlen(buffer);
    if (newLen > length) {
        delete[] str;
        length = newLen;
        str = new char[length + 1];
    }
    strcpy(str, buffer);
}

void String::output() const {
    cout << "Строка: \"" << str << "\" (длина: " << length << ")" << endl;
}

// Геттер длины (const метод)
int String::getLength() const {
    return length;
}