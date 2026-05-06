#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите оператор (+, -, *, /, ^): ";
    cin >> op;
    cout << "Введите второе число: ";
    cin >> b;
    
    double res;
    
    if (op == '+') {
        res = a + b;
    } else if (op == '-') {
        res = a - b;
    } else if (op == '*') {
        res = a * b;
    } else if (op == '/') {
        if (b == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return 1;
        }
        res = a / b;
    } else if (op == '^') {
        res = 1;
        for (int i = 0; i < (int)b; i++) {
            res = res * a;
        }
    } else {
        cout << "Неизвестный оператор" << endl;
        return 1;
    }
    
    cout << "Результат: " << res << endl;
    
    return 0;
}