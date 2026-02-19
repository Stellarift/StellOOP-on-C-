#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char* fullName;
    char birthDate[11];
    char phone[12];
    char city[50];
    char country[50];
    char universityName[100];
    char universityCity[50];
    char universityCountry[50];
    char groupNumber[10];

public:
    Student();
    Student(const char* name, const char* birth, const char* ph,
            const char* c, const char* cntr,
            const char* uni, const char* uniCity,
            const char* uniCountry, const char* group);
    Student(const Student& other);
    
    ~Student();
    
    inline const char* getFullName() const { return fullName; }
    inline const char* getBirthDate() const { return birthDate; }
    inline const char* getPhone() const { return phone; }
    inline const char* getCity() const { return city; }
    inline const char* getCountry() const { return country; }
    inline const char* getUniversityName() const { return universityName; }
    inline const char* getUniversityCity() const { return universityCity; }
    inline const char* getUniversityCountry() const { return universityCountry; }
    inline const char* getGroupNumber() const { return groupNumber; }
    
    void setFullName(const char* name);
    
    inline void setBirthDate(const char* date) {
        for (int i = 0; i < 11 && date[i]; i++) birthDate[i] = date[i];
        birthDate[10] = '\0';
    }
    
    inline void setPhone(const char* ph) {
        for (int i = 0; i < 12 && ph[i]; i++) phone[i] = ph[i];
        phone[11] = '\0';
    }
    
    inline void setCity(const char* c) {
        for (int i = 0; i < 50 && c[i]; i++) city[i] = c[i];
        city[49] = '\0';
    }
    
    inline void setCountry(const char* cntr) {
        for (int i = 0; i < 50 && cntr[i]; i++) country[i] = cntr[i];
        country[49] = '\0';
    }
    
    inline void setUniversityName(const char* uni) {
        for (int i = 0; i < 100 && uni[i]; i++) universityName[i] = uni[i];
        universityName[99] = '\0';
    }
    
    inline void setUniversityCity(const char* uniCity) {
        for (int i = 0; i < 50 && uniCity[i]; i++) universityCity[i] = uniCity[i];
        universityCity[49] = '\0';
    }
    
    inline void setUniversityCountry(const char* uniCountry) {
        for (int i = 0; i < 50 && uniCountry[i]; i++) universityCountry[i] = uniCountry[i];
        universityCountry[49] = '\0';
    }
    
    inline void setGroupNumber(const char* group) {
        for (int i = 0; i < 10 && group[i]; i++) groupNumber[i] = group[i];
        groupNumber[9] = '\0';
    }
    
    void inputData();
    void displayData() const;
};

#endif