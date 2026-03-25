#pragma once

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
public:
    Employee(const string& n) : name(n) {}
    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        cout << "Employee: " << name << endl;
    }
    string getName() const { return name; }
};

class Manager : public Employee {
    double fixedSalary;
public:
    Manager(const string& n, double salary) : Employee(n), fixedSalary(salary) {}
    double calculateSalary() const override { return fixedSalary; }
    void displayInfo() const override { cout << "Manager: " << name << endl; }
};

class Engineer : public Employee {
    double hourlyRate;
    int hours;
public:
    Engineer(const string& n, double rate, int h) : Employee(n), hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
    void displayInfo() const override {
        cout << "Engineer: " << name << " (" << hours << " hours at $" << hourlyRate << "/hour)" << endl;
    }
};

class SalesPerson : public Employee {
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    SalesPerson(const string& n, double base, double sales, double rate)
        : Employee(n), baseSalary(base), salesAmount(sales), commissionRate(rate) {}
    double calculateSalary() const override { return baseSalary + salesAmount * commissionRate / 100; }
    void displayInfo() const override {
        cout << "SalesPerson: " << name << " (base $" << baseSalary 
             << " + " << commissionRate << "% of $" << salesAmount << ")" << endl;
    }
};
