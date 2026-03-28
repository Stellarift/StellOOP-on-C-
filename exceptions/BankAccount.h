#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(const string& name, double initialBalance) : owner(name), balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Ошибка: начальный баланс не может быть отрицательным!");
        }
        cout << "Счёт создан для " << owner << ", баланс: " << balance << endl;
    }
    
    void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("сумма снятия не может быть отрицательной");
        }
        if (amount > balance) {
            throw runtime_error("недостаточно средств! Баланс: " + 
                               to_string(balance) + ", запрошено: " + to_string(amount));
        }
        balance -= amount;
        cout << "Снято " << amount << ", остаток: " << balance << endl;
    }
    
    double getBalance() const { return balance; }
    string getOwner() const { return owner; }
};