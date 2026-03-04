#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker(const string& fullName, const string& position, 
               int startYear, double salary)
    : fullName(fullName), position(position), startYear(startYear), salary(salary) {}

Worker::Worker() : fullName(""), position(""), startYear(0), salary(0.0) {}

void Worker::display() const {
    cout << "ФИО: " << fullName << endl;
    cout << "Должность: " << position << endl;
    cout << "Год поступления: " << startYear << endl;
    cout << "Зарплата: " << salary << endl;
}

string Worker::getFullName() const { return fullName; }
string Worker::getPosition() const { return position; }
int Worker::getStartYear() const { return startYear; }
double Worker::getSalary() const { return salary; }

int Worker::getExperience(int currentYear) const {
    return currentYear - startYear;
}