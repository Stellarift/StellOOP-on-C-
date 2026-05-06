#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// очистка потока ввода
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// проверка
bool isValidDivision(double b) {
    if (b == 0) {
        cout << "деление на ноль невозможно" << endl;
        return false;
    }
    return true;
}

// Возведение в степень
double power(double base, int exponent) {
    if (exponent == 0) return 1;
    
    double result = 1;
    int absExp = abs(exponent);
    
    for (int i = 0; i < absExp; i++) {
        result *= base;
    }
    
    return (exponent > 0) ? result : 1.0 / result;
}

// Вычисление в зависимости от оператора
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (!isValidDivision(b)) return 0;
            return a / b;
        case '^': return power(a, static_cast<int>(b));
        default: return numeric_limits<double>::quiet_NaN();
    }
}

// Получение числа от пользователя
double getNumber(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Ошибочка, введите число: ";
        clearInput();
    }
    return value;
}

// Получение оператора
char getOperator() {
    char op;
    cout << "Введите оператор (+, -, *, /, ^): ";
    while (true) {
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
            return op;
        }
        cout << "Неверный оператор! Введите (+, -, *, /, ^): ";
        clearInput();
    }
}

int main() {
    double a = getNumber("Введите первое число: ");
    char op = getOperator();
    double b = getNumber("Введите второе число: ");
    
    double result = calculate(a, b, op);
    
    if (isnan(result)) {
        cout << "Неизвестная операция" << endl;
        return 1;
    }
    
    cout << a << " " << op << " " << b << " = " << result << endl;
    
    return 0;
}