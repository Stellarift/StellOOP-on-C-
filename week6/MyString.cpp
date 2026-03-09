#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

MyString::MyString() : length(0) {
    str = new char[1];
    str[0] = '\0';
    cout << "MyString default constructor" << endl;
}

MyString::MyString(const char* s) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
    cout << "MyString constructor: \"" << str << "\"" << endl;
}

MyString::MyString(const MyString& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
    cout << "MyString copy constructor" << endl;
}

MyString::~MyString() {
    cout << "MyString destructor: \"" << str << "\"" << endl;
    delete[] str;
}

void MyString::input() {
    char buffer[1000];
    cin.getline(buffer, 1000);
    
    delete[] str;
    length = strlen(buffer);
    str = new char[length + 1];
    strcpy(str, buffer);
}

void MyString::output() const {
    cout << str;
}

MyString MyString::operator*(const MyString& other) const {
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
    
    return MyString(result);
}

const char* MyString::getStr() const { return str; }
int MyString::getLength() const { return length; }