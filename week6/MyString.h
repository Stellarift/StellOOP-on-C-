#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* str;
    int length;

public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);
    ~MyString();
    
    void input();
    void output() const;
    
    MyString operator*(const MyString& other) const;
    
    const char* getStr() const;
    int getLength() const;
};

#endif