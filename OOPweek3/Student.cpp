#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

int Student::objectCount = 0;

void Student::copyString(char* dest, const char* src, int maxLen) {
    if (src) {
        int i = 0;
        while (i < maxLen - 1 && src[i]) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    } else {
        dest[0] = '\0';
    }
}

//конструктор (основной)
Student::Student(const char* name, const char* birth, const char* ph,
                 const char* c, const char* cntr,
                 const char* uni, const char* uniCity,
                 const char* uniCountry, const char* grp) {
    
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    
    copyString(birthDate, birth, 11);
    copyString(phone, ph, 12);
    copyString(city, c, 50);
    copyString(country, cntr, 50);
    copyString(university, uni, 100);
    copyString(universityCity, uniCity, 50);
    copyString(universityCountry, uniCountry, 50);
    copyString(group, grp, 10);
    
    objectCount++;
    cout << "Студент создан. Всего объектов: " << objectCount << endl;
}

// Делегирующие конструкторы
Student::Student() : Student("", "", "", "", "", "", "", "", "") {}

Student::Student(const char* name) 
    : Student(name, "", "", "", "", "", "", "", "") {}

Student::Student(const char* name, const char* birth, const char* ph)
    : Student(name, birth, ph, "", "", "", "", "", "") {}

// Конструктор копирования
Student::Student(const Student& other) {
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
    
    strcpy(birthDate, other.birthDate);
    strcpy(phone, other.phone);
    strcpy(city, other.city);
    strcpy(country, other.country);
    strcpy(university, other.university);
    strcpy(universityCity, other.universityCity);
    strcpy(universityCountry, other.universityCountry);
    strcpy(group, other.group);
    
    objectCount++;
    cout << "Студент скопирован. Всего объектов: " << objectCount << endl;
}

Student::~Student() {
    cout << "Студент " << fullName << " удален. Осталось: " << objectCount - 1 << endl;
    delete[] fullName;
    objectCount--;
}

int Student::getObjectCount() {
    return objectCount;
}

void Student::display() const {
    cout << "ФИО: " << fullName << endl;
    if (birthDate[0]) cout << "Дата рождения: " << birthDate << endl;
    if (phone[0]) cout << "Телефон: " << phone << endl;
    if (city[0]) cout << "Город: " << city << endl;
    if (country[0]) cout << "Страна: " << country << endl;
}