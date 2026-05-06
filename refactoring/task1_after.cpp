#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

// функция для проверки и преобразования строки в число
bool parseInteger(const string& input, int& result) {
    if (input.empty()) return false;
    
    size_t start = 0;
    bool isNegative = false;
    
    if (input[0] == '-') {
        isNegative = true;
        start = 1;
        if (input.length() == 1) return false;
    }
    
    long long value = 0;
    for (size_t i = start; i < input.length(); i++) {
        if (!isdigit(input[i])) return false;
        value = value * 10 + (input[i] - '0');
        if (value > 2147483647) return false;
    }
    
    result = isNegative ? static_cast<int>(-value) : static_cast<int>(value);
    return true;
}

int getValidNumber() {
    string input;
    int result;
    
    while (true) {
        cout << "Введите число: ";
        cin >> input;
        
        if (parseInteger(input, result)) {
            return result;
        }
        
        cout << "Введите корректное целое число" << endl;
        cin.clear();
    }
}

// функция для возведения в квадрат
inline int square(int x) {
    return x * x;
}

int main() {
    int num = getValidNumber();
    
    cout << "Вы ввели: " << num << endl;
    cout << "Квадрат числа: " << square(num) << endl;
    
    return 0;
}