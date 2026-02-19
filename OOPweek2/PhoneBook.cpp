#include "PhoneBook.h"
#include <iostream>
#include <cstring>
using namespace std;

// Конструктор по умолчанию
PhoneBook::PhoneBook() : homePhone(), workPhone(), mobilePhone(), additionalInfo() {
    fullName = new char[1];
    fullName[0] = '\0';
    
    homePhone[0] = '\0';
    workPhone[0] = '\0';
    mobilePhone[0] = '\0';
    additionalInfo[0] = '\0';
    
    cout << "Конструктор по умолчанию для " << this << endl;
}

// Конструктор с параметрами
PhoneBook::PhoneBook(const char* name, const char* home, const char* work, 
                     const char* mobile, const char* info)
    : homePhone(), workPhone(), mobilePhone(), additionalInfo() {
    
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    
    strcpy(homePhone, home);
    strcpy(workPhone, work);
    strcpy(mobilePhone, mobile);
    strcpy(additionalInfo, info);
    
    cout << "Конструктор с параметрами для " << this << endl;
}

// Конструктор копирования
PhoneBook::PhoneBook(const PhoneBook& other)
    : homePhone(), workPhone(), mobilePhone(), additionalInfo() {
    
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
    
    strcpy(homePhone, other.homePhone);
    strcpy(workPhone, other.workPhone);
    strcpy(mobilePhone, other.mobilePhone);
    strcpy(additionalInfo, other.additionalInfo);
    
    cout << "Конструктор копирования для " << this << endl;
}

// Деструктор
PhoneBook::~PhoneBook() {
    cout << "Деструктор для " << this << " (" << fullName << ")" << endl;
    delete[] fullName;
}

// Сеттер для ФИО
void PhoneBook::setFullName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

// Ввод данных
void PhoneBook::inputData() {
    char buffer[256];
    
    cout << "Введите ФИО: ";
    cin.ignore();
    cin.getline(buffer, 256);
    setFullName(buffer);
    
    cout << "Введите домашний телефон: ";
    cin.getline(homePhone, 12);
    
    cout << "Введите рабочий телефон: ";
    cin.getline(workPhone, 12);
    
    cout << "Введите мобильный телефон: ";
    cin.getline(mobilePhone, 12);
    
    cout << "Введите дополнительную информацию: ";
    cin.getline(additionalInfo, 100);
}

// Вывод данных
void PhoneBook::displayData() const {
    cout << "\n Абонент" << endl;
    cout << "ФИО: " << fullName << endl;
    cout << "Домашний: " << homePhone << endl;
    cout << "Рабочий: " << workPhone << endl;
    cout << "Мобильный: " << mobilePhone << endl;
    cout << "Доп. информация: " << additionalInfo << endl;
}

// Сравнение по ФИО 
bool PhoneBook::compareByName(const char* name) const {
    return strcmp(fullName, name) == 0;
}

// Сохранение в файл 
void PhoneBook::saveToFile(ofstream& file) const {
    file << fullName << endl;
    file << homePhone << endl;
    file << workPhone << endl;
    file << mobilePhone << endl;
    file << additionalInfo << endl;
}

// Загрузка из файла
void PhoneBook::loadFromFile(ifstream& file) {
    char buffer[256];
    
    file.getline(buffer, 256);
    setFullName(buffer);
    
    file.getline(homePhone, 12);
    file.getline(workPhone, 12);
    file.getline(mobilePhone, 12);
    file.getline(additionalInfo, 100);
}