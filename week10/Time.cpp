#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Нормализация времени
void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    else if (seconds < 0) {
        int m = (-seconds + 59) / 60;
        minutes -= m;
        seconds += m * 60;
    }
    
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    else if (minutes < 0) {
        int h = (-minutes + 59) / 60;
        hours -= h;
        minutes += h * 60;
    }
    
    if (hours < 0) hours = 0;
}

Time::Time() : hours(0), minutes(0), seconds(0) {
    cout << "Time default constructor" << endl;
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
    cout << "Time constructor: " << *this << endl;
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {
    cout << "Time copy constructor" << endl;
}

int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

void Time::setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalize();
}

Time& Time::operator++() {
    seconds++;
    normalize();
    return *this;
}

Time& Time::operator--() {
    seconds--;
    normalize();
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    seconds++;
    normalize();
    return temp;
}

Time Time::operator--(int) {
    Time temp = *this;
    seconds--;
    normalize();
    return temp;
}

bool operator==(const Time& a, const Time& b) {
    return (a.hours == b.hours && a.minutes == b.minutes && a.seconds == b.seconds);
}

bool operator!=(const Time& a, const Time& b) {
    return !(a == b);
}

bool operator<(const Time& a, const Time& b) {
    if (a.hours != b.hours) return a.hours < b.hours;
    if (a.minutes != b.minutes) return a.minutes < b.minutes;
    return a.seconds < b.seconds;
}

bool operator>(const Time& a, const Time& b) {
    return b < a;
}

Time& Time::operator+=(const Time& other) {
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;
    normalize();
    return *this;
}

Time& Time::operator-=(const Time& other) {
    hours -= other.hours;
    minutes -= other.minutes;
    seconds -= other.seconds;
    normalize();
    return *this;
}

Time& Time::operator=(const Time& other) {
    cout << "Time copy assignment" << endl;
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

int Time::operator()() const {
    return hours * 3600 + minutes * 60 + seconds;
}

ostream& operator<<(ostream& os, const Time& t) {
    os << setfill('0') << setw(2) << t.hours << ":"
       << setw(2) << t.minutes << ":"
       << setw(2) << t.seconds;
    return os;
}

istream& operator>>(istream& is, Time& t) {
    char colon;
    cout << "Введите время в формате чч:мм:сс: ";
    is >> t.hours >> colon >> t.minutes >> colon >> t.seconds;
    t.normalize();
    return is;
}