#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* data;
    int size;

public:
    Array();                    
    explicit Array(int n);      
    Array(const Array& other); 
    
    ~Array();
    
    // Методы
    void fillRandom();
    void fillFromKeyboard();
    void display() const;
    
    void resize(int newSize);
    void sort();
    int getMin() const;
    int getMax() const;
    
    int getSize() const;
};

#endif