#ifndef STRING_H
#define STRING_H

class String {
private:
    char* str;
    int length;

public:
    // Конструкторы
    String();                    
    explicit String(int size);   
    String(const char* input);   
    String(const String& other);

    ~String();
    
    void input();
    void output() const;
    
    int getLength() const;
};

#endif