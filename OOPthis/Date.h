#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y);
    Date();
    ~Date();
    
    void print();
    
    int getDay();
    int getMonth();
    int getYear();
    
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
};

#endif