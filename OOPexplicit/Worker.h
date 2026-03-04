#ifndef WORKER_H
#define WORKER_H

#include <string>
using namespace std;

class Worker {
private:
    string fullName;
    string position;
    int startYear;
    double salary;

public:
    Worker(const string& fullName, const string& position, 
           int startYear, double salary);
    
    Worker();
    
    void display() const;
    
    // Геттеры (const)
    string getFullName() const;
    string getPosition() const;
    int getStartYear() const;
    double getSalary() const;
    
    int getExperience(int currentYear) const;
};

#endif