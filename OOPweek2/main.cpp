#include <iostream>
#include <fstream>
#include "PhoneBook.h"
using namespace std;

const int MAX_CONTACTS = 100;

void showMenu() {
    cout << "\n Телефонная книга" << endl;
    cout << "1. Добавить абонента" << endl;
    cout << "2. Показать всех абонентов" << endl;
    cout << "3. Найти абонента по ФИО" << endl;
    cout << "4. Удалить абонента" << endl;
    cout << "5. Сохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

void addContact(PhoneBook* contacts, int& count) {
    if (count >= MAX_CONTACTS) {
        cout << "Телефонная книга переполнена!" << endl;
        return;
    }
    
    cout << "\n Добавление нового абонента " << endl;
    contacts[count].inputData();
    count++;
    cout << "Абонент добавлен!" << endl;
}

void showAllContacts(PhoneBook* contacts, int count) {
    if (count == 0) {
        cout << "Телефонная книга пуста!" << endl;
        return;
    }
    
    cout << "\n--- ВСЕ АБОНЕНТЫ (" << count << ") ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\n" << i + 1 << ".";
        contacts[i].displayData();
    }
}

void findContact(PhoneBook* contacts, int count) {
    if (count == 0) {
        cout << "Телефонная книга пуста!" << endl;
        return;
    }
    
    char name[256];
    cout << "Введите ФИО для поиска: ";
    cin.ignore();
    cin.getline(name, 256);
    
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (contacts[i].compareByName(name)) {
            cout << "\nАбонент найден:";
            contacts[i].displayData();
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Абонент с ФИО \"" << name << "\" не найден!" << endl;
    }
}

void deleteContact(PhoneBook* contacts, int& count) {
    if (count == 0) {
        cout << "Телефонная книга пуста!" << endl;
        return;
    }
    
    char name[256];
    cout << "Введите ФИО для удаления: ";
    cin.ignore();
    cin.getline(name, 256);
    
    for (int i = 0; i < count; i++) {
        if (contacts[i].compareByName(name)) {
            // Сдвигаем всех следующих на одну позицию влево
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            cout << "Абонент удален!" << endl;
            return;
        }
    }
    
    cout << "Абонент с ФИО \"" << name << "\" не найден!" << endl;
}

void saveToFile(PhoneBook* contacts, int count) {
    ofstream file("phonebook.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }
    
    file << count << endl;
    for (int i = 0; i < count; i++) {
        contacts[i].saveToFile(file);
    }
    
    file.close();
    cout << "Данные сохранены в файл phonebook.txt" << endl;
}

void loadFromFile(PhoneBook* contacts, int& count) {
    ifstream file("phonebook.txt");
    if (!file.is_open()) {
        cout << "Файл phonebook.txt не найден!" << endl;
        return;
    }
    
    int newCount;
    file >> newCount;
    file.ignore(); 
    
    if (newCount > MAX_CONTACTS) {
        cout << "Слишком много записей в файле!" << endl;
        file.close();
        return;
    }
    
    for (int i = 0; i < newCount; i++) {
        contacts[i].loadFromFile(file);
    }
    
    count = newCount;
    file.close();
    cout << "Данные загружены из файла phonebook.txt" << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    PhoneBook contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addContact(contacts, contactCount);
                break;
            case 2:
                showAllContacts(contacts, contactCount);
                break;
            case 3:
                findContact(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, contactCount);
                break;
            case 5:
                saveToFile(contacts, contactCount);
                break;
            case 6:
                loadFromFile(contacts, contactCount);
                break;
            case 0:
                cout << "Программа завершена" << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
    
    return 0;
}