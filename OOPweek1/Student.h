#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string fullName;
    string birthDate;
    string phone;
    string city;
    string country;
    string universityName;
    string universityCity;
    string universityCountry;
    string groupNumber;

public:
    void inputData();
    void displayData() const;
    
    string getFullName() const;
    string getBirthDate() const;
    string getPhone() const;
    string getCity() const;
    string getCountry() const;
    string getUniversityName() const;
    string getUniversityCity() const;
    string getUniversityCountry() const;
    string getGroupNumber() const;
    
    void setFullName(const string& newFullName);
    void setBirthDate(const string& newBirthDate);
    void setPhone(const string& newPhone);
    void setCity(const string& newCity);
    void setCountry(const string& newCountry);
    void setUniversityName(const string& newUniName);
    void setUniversityCity(const string& newUniCity);
    void setUniversityCountry(const string& newUniCountry);
    void setGroupNumber(const string& newGroup);
};

#endif