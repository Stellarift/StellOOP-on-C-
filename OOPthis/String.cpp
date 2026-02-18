#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

String::String(const char* s) {
    if (s) {
        dlina = strlen(s);
        stroka = new char[dlina + 1];
        strcpy(stroka, s);
    } else {
        dlina = 0;
        stroka = new char[1];
        stroka[0] = '\0';
    }
    cout << "Создаем строку для " << this << ": " << stroka << endl;
}

String::String(int len) : dlina(len) {
    stroka = new char[dlina + 1];
    stroka[0] = '\0';
    cout << "Создаем пустую строку для " << this << endl;
}

String::String(const String& other) : dlina(other.dlina) {
    stroka = new char[dlina + 1];
    strcpy(stroka, other.stroka);
    cout << "Копируем строку для " << this << endl;
}

String::~String() {
    cout << "Уничтожаем строку для " << this << ": " << stroka << endl;
    delete[] stroka;
}

void String::print() {
    cout << stroka;
}

void String::set(const char* s) {
    if (!s) return;
    
    int novDlina = strlen(s);
    if (novDlina > dlina) {
        delete[] stroka;
        dlina = novDlina;
        stroka = new char[dlina + 1];
    }
    strcpy(stroka, s);
}

int String::getDlina() { return dlina; }
const char* String::getStroka() { return stroka; }