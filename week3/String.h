#ifndef STRING_H
#define STRING_H

class String {
private:
    char* str;          // указатель на строку
    int length;         // длина строки
    static int objectCount;  // статический счетчик объектов

public:
    // Конструкторы
    String();   // по умолчанию (80 символов)
    String(int size); // произвольного размера
    String(const char* input);  // инициализация строкой
    
    // Конструктор копирования
    String(const String& other);
    
    // Деструктор
    ~String();
    
    // Методы
    void input();        // ввод строки с клавиатуры
    void output() const; // вывод строки на экран
    
    // Статическая функция для получения количества объектов
    static int getObjectCount();
    
    // Геттер для длины (inline)
    inline int getLength() const { return length; }
};

#endif