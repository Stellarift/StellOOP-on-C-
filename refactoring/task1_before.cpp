#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    cout << "Введите число: ";
    cin >> input;
    
    int num = 0;
    bool isNegative = false;
    int i = 0;
    
    if (input[0] == '-') {
        isNegative = true;
        i = 1;
    }
    
    for (; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            cout << "Ошибка: введены буквы!" << endl;
            return 1;
        }
        num = num * 10 + (input[i] - '0');
    }
    
    if (isNegative) {
        num = -num;
    }
    
    cout << "Вы ввели: " << num << endl;
    cout << "Квадрат числа: " << num * num << endl;
    
    return 0;
}