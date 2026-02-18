#include "Student.h"
#include <iostream>

using namespace std;

void Student::inputData() {
    cout << "Введите ФИО студента: ";
    getline(cin, fullName);
    cout << "Введите дату рождения: ";
    getline(cin, birthDate);
    cout << "Введите контактный телефон: ";
    getline(cin, phone);
    cout << "Введите город проживания: ";
    getline(cin, city);
    cout << "Введите страну проживания: ";
    getline(cin, country);
    cout << "Введите название учебного заведения: ";
    getline(cin, universityName);
    cout << "Введите город учебного заведения: ";
    getline(cin, universityCity);
    cout << "Введите страну учебного заведения: ";
    getline(cin, universityCountry);
    cout << "Введите номер группы: ";
    getline(cin, groupNumber);
}

void Student::displayData() const {
    cout << "\nДанные студента\n";
    cout << "ФИО: " << fullName << endl;
    cout << "Дата рождения: " << birthDate << endl;
    cout << "Телефон: " << phone << endl;
    cout << "Город проживания: " << city << endl;
    cout << "Страна проживания: " << country << endl;
    cout << "Учебное заведение: " << universityName << endl;
    cout << "Город УЗ: " << universityCity << endl;
    cout << "Страна УЗ: " << universityCountry << endl;
    cout << "Группа: " << groupNumber << endl;
    cout << "------------------------\n";
}

string Student::getFullName() const { return fullName; }
string Student::getBirthDate() const { return birthDate; }
string Student::getPhone() const { return phone; }
string Student::getCity() const { return city; }
string Student::getCountry() const { return country; }
string Student::getUniversityName() const { return universityName; }
string Student::getUniversityCity() const { return universityCity; }
string Student::getUniversityCountry() const { return universityCountry; }
string Student::getGroupNumber() const { return groupNumber; }

void Student::setFullName(const string& newFullName) { fullName = newFullName; }
void Student::setBirthDate(const string& newBirthDate) { birthDate = newBirthDate; }
void Student::setPhone(const string& newPhone) { phone = newPhone; }
void Student::setCity(const string& newCity) { city = newCity; }
void Student::setCountry(const string& newCountry) { country = newCountry; }
void Student::setUniversityName(const string& newUniName) { universityName = newUniName; }
void Student::setUniversityCity(const string& newUniCity) { universityCity = newUniCity; }
void Student::setUniversityCountry(const string& newUniCountry) { universityCountry = newUniCountry; }
void Student::setGroupNumber(const string& newGroup) { groupNumber = newGroup; }