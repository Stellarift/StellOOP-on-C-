#ifndef STRING_H
#define STRING_H

class String {
private:
    char* str;
    int length;

public:
    String();
    String(const char* s);
    String(const String& other);
    ~String();
    
    String& operator=(const String& other);
    String operator+(const String& other) const;
    String operator*(const String& other) const;
    
    friend bool operator==(const String& a, const String& b);
    friend bool operator!=(const String& a, const String& b);
    friend bool operator<(const String& a, const String& b);
    friend bool operator>(const String& a, const String& b);
    
    void input();
    void output() const;
    int getLength() const;
    const char* c_str() const;
    
    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;
};

#endif