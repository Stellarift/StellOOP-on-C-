#include <iostream>
#include "Date.h"
#include "MyString.h"
using namespace std;

void testDate() {
    cout << "\nЗадание 1" << endl;
    
    cout << "\nСоздание дат" << endl;
    Date d1(15, 3, 2024);
    Date d2(1, 1, 2024);
    
    cout << "d1 = "; d1.display(); cout << endl;
    cout << "d2 = "; d2.display(); cout << endl;
    
    cout << "\nРазность дат" << endl;
    int diff = d1 - d2;
    cout << "d1 - d2 = " << diff << " дней" << endl;
    
    cout << "\nПрибавление дней" << endl;
    Date d3 = d1 + 30;
    cout << "d1 + 30 дней = "; d3.display(); cout << endl;
    
    Date d4 = d1;
    d4 += 100;
    cout << "d1 += 100 дней = "; d4.display(); cout << endl;
    
    cout << "\nПример с високосным годом" << endl;
    Date d5(28, 2, 2024);
    Date d6(1, 3, 2024);
    
    cout << "28.02.2024 - 01.03.2024 = " << (d6 - d5) << " день" << endl;
    
    d5 += 1;
    cout << "28.02.2024 + 1 день = "; d5.display(); cout << endl;
}

void testMyString() {
    cout << "\nЗадание 2" << endl;
    
    MyString s1("sdqcg");
    MyString s2("rgfas34");
    
    cout << "s1 = "; s1.output(); cout << endl;
    cout << "s2 = "; s2.output(); cout << endl;
    
    MyString s3 = s1 * s2;
    cout << "s1 * s2 = "; s3.output(); cout << endl;
    
    cout << "\nДополнительные примеры" << endl;
    
    MyString s4("hello world");
    MyString s5("world of programming");
    
    cout << "s4 = "; s4.output(); cout << endl;
    cout << "s5 = "; s5.output(); cout << endl;
    
    MyString s6 = s4 * s5;
    cout << "s4 * s5 = "; s6.output(); cout << endl;
    
    MyString s7("abc123");
    MyString s8("def456");
    
    cout << "s7 = "; s7.output(); cout << endl;
    cout << "s8 = "; s8.output(); cout << endl;
    
    MyString s9 = s7 * s8;
    cout << "s7 * s8 = "; s9.output(); cout << endl;
    
    cout << "\nВвод строк с клавиатуры" << endl;
    MyString s10, s11;
    cout << "Введите первую строку: ";
    s10.input();
    cout << "Введите вторую строку: ";
    s11.input();
    
    MyString s12 = s10 * s11;
    cout << "Результат: ";
    s12.output();
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Перегрузка операторов" << endl;
    
    testDate();
    testMyString();
    
    return 0;
}