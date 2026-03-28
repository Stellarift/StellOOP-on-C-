#include <iostream>
#include <stdexcept>
#include "BankAccount.h"
#include "Exceptions.h"
using namespace std;

void testBankAccount() {
    cout << "\nБанк-аккаунт, задание 1" << endl;
    
    try {
        BankAccount acc1("Иванов", -100);
    } catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    
    BankAccount acc("Петров", 1000);
    
    try {
        acc.withdraw(-50);
    } catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    
    try {
        acc.withdraw(2000);
    } catch (const runtime_error& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    
    acc.withdraw(300);
    cout << "Конечный баланс: " << acc.getBalance() << endl;
}

void testSafeDivision() {
    cout << "\nБезопасное деление, задание 2" << endl;
    
    try {
        cout << "10 / 2 = " << SafeDivision::divide(10, 2) << endl;
    } catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
    
    try {
        cout << "10 / 0 = " << SafeDivision::divide(10, 0) << endl;
    } catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
    
    try {
        cout << "7 / 3 = " << SafeDivision::divide(7, 3) << endl;
    } catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
}

void testIntArray() {
    cout << "\nМассив с контролем границ, задание 3" << endl;
    
    try {
        IntArray arr(-5);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    
    IntArray arr(5);
    
    for (int i = 0; i < arr.getSize(); i++) {
        arr.setAt(i, (i + 1) * 10);
    }
    
    try {
        cout << "Элемент с индексом 2: " << arr.at(2) << endl;
        cout << "Элемент с индексом 4: " << arr.at(4) << endl;
        cout << "Элемент с индексом 5: " << arr.at(5) << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
    
    try {
        arr.setAt(5, 100);
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
    
    cout << "Все элементы массива: ";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    testBankAccount();
    testSafeDivision();
    testIntArray();
    
    return 0;
}