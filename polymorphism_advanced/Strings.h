#pragma once

#include <iostream>
#include <cstring>
using namespace std;

class StringHolder {
protected:
    char* str;
public:
    StringHolder(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        cout << "StringHolder constructor for \"" << str << "\"" << endl;
    }
    
    virtual ~StringHolder() {
        cout << "StringHolder destructor for \"" << str << "\"" << endl;
        delete[] str;
    }
    
    virtual void print() const {
        cout << str;
    }
};

class ReverseString : public StringHolder {
public:
    ReverseString(const char* s) : StringHolder(s) {
        cout << "ReverseString constructor for \"" << str << "\"" << endl;
    }
    
    ~ReverseString() {
        cout << "ReverseString destructor" << endl;
    }
    
    void print() const override {
        int len = strlen(str);
        for (int i = len - 1; i >= 0; i--) {
            cout << str[i];
        }
    }
};