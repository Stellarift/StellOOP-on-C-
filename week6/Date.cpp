#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : day(1), month(1), year(2000) {
    cout << "Date default constructor" << endl;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    cout << "Date constructor: " << day << "." << month << "." << year << endl;
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {
    cout << "Date copy constructor" << endl;
}

Date::~Date() {
    cout << "Date destructor: " << day << "." << month << "." << year << endl;
}

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
    if (m == 2) {
        return isLeapYear(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

void Date::display() const {
    cout << day << "." << month << "." << year;
}

int Date::operator-(const Date& other) const {
    int days1 = day;
    for (int m = 1; m < month; m++) {
        days1 += daysInMonth(m, year);
    }
    
    int days2 = other.day;
    for (int m = 1; m < other.month; m++) {
        days2 += daysInMonth(m, other.year);
    }
    
    int yearDiff = year - other.year;
    int totalDays = yearDiff * 365;
    
    for (int y = other.year; y < year; y++) {
        if (isLeapYear(y)) totalDays++;
    }
    
    return totalDays + (days1 - days2);
}

Date Date::operator+(int days) const {
    Date result = *this;
    result += days;
    return result;
}

Date& Date::operator+=(int days) {
    day += days;
    
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    
    return *this;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}