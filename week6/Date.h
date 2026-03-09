#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;

public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& other);
    ~Date();
    
    void display() const;
    
    int operator-(const Date& other) const;
    Date operator+(int days) const;
    Date& operator+=(int days);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    void setDate(int d, int m, int y);
};

#endif