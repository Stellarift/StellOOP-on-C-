#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char* fullName;
    char birthDate[11];
    char phone[12];
    char city[50];
    char country[50];
    char university[100];
    char universityCity[50];
    char universityCountry[50];
    char group[10];
    
    static int objectCount;  // счетчик созданных объектов
    
    void copyString(char* dest, const char* src, int maxLen);

public:
    // Конструкторы с делегированием
    Student();                                                    // пустой
    Student(const char* name);                                    // только имя
    Student(const char* name, const char* birth, const char* ph); // имя + дата + телефон
    Student(const char* name, const char* birth, const char* ph,  // полный
            const char* city, const char* country,
            const char* uni, const char* uniCity,
            const char* uniCountry, const char* group);
    Student(const Student& other);                                 // копирования
    
    ~Student();
    
    static int getObjectCount();
    
    // inline геттеры
    inline const char* getFullName() const { return fullName; }
    inline const char* getBirthDate() const { return birthDate; }
    inline const char* getPhone() const { return phone; }
    inline const char* getCity() const { return city; }
    inline const char* getCountry() const { return country; }
    
    void display() const;
};

#endif