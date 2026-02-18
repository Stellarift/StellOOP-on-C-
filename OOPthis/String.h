#ifndef STRING_H
#define STRING_H

class String {
private:
    int dlina;
    char* stroka;

public:
    String(const char* s);
    String(int len);
    String(const String& other);
    ~String();
    
    void print();
    void set(const char* s);
    
    int getDlina();
    const char* getStroka();
};

#endif