#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() : fullName(nullptr), age(0), averageGrade(0.0) {
    fullName = new char[1];
    fullName[0] = '\0';
    cout << "Student default constructor" << endl;
}

Student::Student(const char* name, int age, double avg) : age(age), averageGrade(avg) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    cout << "Student parameter constructor: " << fullName << endl;
}

Student::Student(const Student& other) : age(other.age), averageGrade(other.averageGrade) {
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
    cout << "Student copy constructor: " << fullName << endl;
}

Student::Student(Student&& other) noexcept 
    : fullName(other.fullName), age(other.age), averageGrade(other.averageGrade) {
    other.fullName = nullptr;
    cout << "Student move constructor: " << fullName << endl;
}

Student::~Student() {
    cout << "Student destructor: " << (fullName ? fullName : "nullptr") << endl;
    delete[] fullName;
}

void Student::display() const {
    cout << "Student: " << fullName << ", Age: " << age << ", Avg: " << averageGrade << endl;
}