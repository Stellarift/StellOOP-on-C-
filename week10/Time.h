#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    
    void normalize();

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& other);
    
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void setTime(int h, int m, int s);
    
    // Перегрузка инкремента/декремента (префиксные)
    Time& operator++();
    Time& operator--();
    
    // Перегрузка инкремента/декремента (постфиксные)
    Time operator++(int);  // t++
    Time operator--(int);  // t--
    
    friend bool operator==(const Time& a, const Time& b);
    friend bool operator!=(const Time& a, const Time& b);
    friend bool operator<(const Time& a, const Time& b);
    friend bool operator>(const Time& a, const Time& b);
    
    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    
    Time& operator=(const Time& other);
    
    int operator()() const;
    
    friend ostream& operator<<(ostream& os, const Time& t);
    friend istream& operator>>(istream& is, Time& t);
};

#endif