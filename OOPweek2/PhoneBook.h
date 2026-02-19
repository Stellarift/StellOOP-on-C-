#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <fstream>  
using namespace std;

class PhoneBook {
private:
    char* fullName;        // ФИО (динамическая память)
    char homePhone[12];     // домашний телефон
    char workPhone[12];     // рабочий телефон
    char mobilePhone[12];   // мобильный телефон
    char additionalInfo[100]; // доп. информация

public:
    // Конструкторы
    PhoneBook();
    PhoneBook(const char* name, const char* home, const char* work, 
              const char* mobile, const char* info);
    PhoneBook(const PhoneBook& other);
    
    // Деструктор
    ~PhoneBook();
    
    // inline геттеры
    inline const char* getFullName() const { return fullName; }
    inline const char* getHomePhone() const { return homePhone; }
    inline const char* getWorkPhone() const { return workPhone; }
    inline const char* getMobilePhone() const { return mobilePhone; }
    inline const char* getAdditionalInfo() const { return additionalInfo; }
    
    // Сеттеры
    void setFullName(const char* name);
    inline void setHomePhone(const char* phone) {
        for (int i = 0; i < 12 && phone[i]; i++) homePhone[i] = phone[i];
        homePhone[11] = '\0';
    }
    inline void setWorkPhone(const char* phone) {
        for (int i = 0; i < 12 && phone[i]; i++) workPhone[i] = phone[i];
        workPhone[11] = '\0';
    }
    inline void setMobilePhone(const char* phone) {
        for (int i = 0; i < 12 && phone[i]; i++) mobilePhone[i] = phone[i];
        mobilePhone[11] = '\0';
    }
    inline void setAdditionalInfo(const char* info) {
        for (int i = 0; i < 100 && info[i]; i++) additionalInfo[i] = info[i];
        additionalInfo[99] = '\0';
    }
    
    // Методы
    void inputData();
    void displayData() const;
    bool compareByName(const char* name) const;  // поиск по ФИО
    
    // Работа с файлами через fstream
    void saveToFile(ofstream& file) const;
    void loadFromFile(ifstream& file);
};

#endif