#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() 
    : fullName(nullptr), birthDate(), phone(), city(), country(),
      universityName(), universityCity(), universityCountry(), groupNumber() {
    
    fullName = new char[1];
    fullName[0] = '\0';
    
    birthDate[0] = '\0';
    phone[0] = '\0';
    city[0] = '\0';
    country[0] = '\0';
    universityName[0] = '\0';
    universityCity[0] = '\0';
    universityCountry[0] = '\0';
    groupNumber[0] = '\0';
    
    cout << "Конструктор студента (по умолчанию) для " << this << endl;
}

Student::Student(const char* name, const char* birth, const char* ph,
                 const char* c, const char* cntr,
                 const char* uni, const char* uniCity,
                 const char* uniCountry, const char* group)
    : birthDate(), phone(), city(), country(),
      universityName(), universityCity(), universityCountry(), groupNumber() {
    
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    
    strcpy(birthDate, birth);
    strcpy(phone, ph);
    strcpy(city, c);
    strcpy(country, cntr);
    strcpy(universityName, uni);
    strcpy(universityCity, uniCity);
    strcpy(universityCountry, uniCountry);
    strcpy(groupNumber, group);
    
    cout << "Конструктор студента (с параметрами) для " << this << endl;
}

Student::Student(const Student& other)
    : birthDate(), phone(), city(), country(),
      universityName(), universityCity(), universityCountry(), groupNumber() {
    
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
    
    strcpy(birthDate, other.birthDate);
    strcpy(phone, other.phone);
    strcpy(city, other.city);
    strcpy(country, other.country);
    strcpy(universityName, other.universityName);
    strcpy(universityCity, other.universityCity);
    strcpy(universityCountry, other.universityCountry);
    strcpy(groupNumber, other.groupNumber);
    
    cout << "Конструктор копирования студента для " << this << endl;
}

Student::~Student() {
    cout << "Деструктор студента для " << this << " (" << fullName << ")" << endl;
    delete[] fullName;
}

void Student::setFullName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    cout << "ФИО изменено на: " << fullName << endl;
}

void Student::inputData() {
    char buffer[256];
    
    cout << "Введите ФИО студента: ";
    cin.ignore();
    cin.getline(buffer, 256);
    setFullName(buffer);
    
    cout << "Введите дату рождения: ";
    cin.getline(birthDate, 11);
    
    cout << "Введите контактный телефон: ";
    cin.getline(phone, 12);
    
    cout << "Введите город проживания: ";
    cin.getline(city, 50);
    
    cout << "Введите страну проживания: ";
    cin.getline(country, 50);
    
    cout << "Введите название учебного заведения: ";
    cin.getline(universityName, 100);
    
    cout << "Введите город учебного заведения: ";
    cin.getline(universityCity, 50);
    
    cout << "Введите страну учебного заведения: ";
    cin.getline(universityCountry, 50);
    
    cout << "Введите номер группы: ";
    cin.getline(groupNumber, 10);
}

void Student::displayData() const {
    cout << "\n Данные студента" << endl;
    cout << "ФИО: " << (fullName ? fullName : "не указано") << endl;
    cout << "Дата рождения: " << birthDate << endl;
    cout << "Телефон: " << phone << endl;
    cout << "Город проживания: " << city << endl;
    cout << "Страна проживания: " << country << endl;
    cout << "Учебное заведение: " << universityName << endl;
    cout << "Город учебного заведения: " << universityCity << endl;
    cout << "Страна учебного заведения: " << universityCountry << endl;
    cout << "Номер группы: " << groupNumber << endl;
}