#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y) {
    cout << "Создаем дату для " << this << endl;
    day = d;
    month = m;
    year = y;
}

Date::Date() : Date(1, 1, 2000) {}

Date::~Date() {
    cout << "Уничтожаем дату для " << this << endl;
}

void Date::print() {
    cout << day << "." << month << "." << year;
}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }