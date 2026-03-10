#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

String::String() : length(0) {
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

String::String(String&& other) noexcept : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
}

String::~String() {
    delete[] str;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str;
        str = other.str;
        length = other.length;
        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}

String String::operator+(const String& other) const {
    char* newStr = new char[length + other.length + 1];
    strcpy(newStr, str);
    strcat(newStr, other.str);
    String result(newStr);
    delete[] newStr;
    return result;
}

String String::operator*(const String& other) const {
    bool used[256] = {false};
    bool inThis[256] = {false};
    bool inOther[256] = {false};
    
    for (int i = 0; i < length; i++) {
        inThis[(unsigned char)str[i]] = true;
    }
    
    for (int i = 0; i < other.length; i++) {
        inOther[(unsigned char)other.str[i]] = true;
    }
    
    char result[256] = "";
    int pos = 0;
    
    for (int i = 0; i < length; i++) {
        unsigned char ch = str[i];
        if (inOther[ch] && !used[ch]) {
            result[pos++] = ch;
            used[ch] = true;
        }
    }
    
    return String(result);
}

bool operator==(const String& a, const String& b) {
    return strcmp(a.str, b.str) == 0;
}

bool operator!=(const String& a, const String& b) {
    return !(a == b);
}

bool operator<(const String& a, const String& b) {
    return strcmp(a.str, b.str) < 0;
}

bool operator>(const String& a, const String& b) {
    return strcmp(a.str, b.str) > 0;
}

void String::input() {
    char buffer[1000];
    cin.getline(buffer, 1000);
    delete[] str;
    length = strlen(buffer);
    str = new char[length + 1];
    strcpy(str, buffer);
}

void String::output() const {
    cout << str;
}

int String::getLength() const { return length; }
const char* String::c_str() const { return str; }