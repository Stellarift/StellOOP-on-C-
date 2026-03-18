#include <iostream>
#include "Complex.h"
#include "Time.h"
using namespace std;

void testComplex() {
    cout << "\nЗадание 1" << endl;
    
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    
    Complex c4 = c1 - c2;
    cout << "c1 - c2 = " << c4 << endl;
    
    cout << "c1 == c2: " << ((c1 == c2) ? "да" : "нет") << endl;
    cout << "c1 != c2: " << ((c1 != c2) ? "да" : "нет") << endl;
    
    Complex c5 = c1;
    cout << "c5 (копия c1) = " << c5 << endl;
    cout << "c1 == c5: " << ((c1 == c5) ? "да" : "нет") << endl;
    
    cout << "Модуль c1 = " << c1() << endl;
    cout << "Модуль c2 = " << c2() << endl;
    
    cout << "\nВвод комплексного числа с клавиатуры " << endl;
    Complex c6;
    cin >> c6;
    cout << "Вы ввели: " << c6 << endl;
    cout << "Модуль = " << c6() << endl;
}

void testTime() {
    cout << "\nЗадание 2" << endl;
    
    Time t1(10, 30, 45);
    Time t2(2, 15, 30);
    
    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;
    
    cout << "\nИнкремент и декремент" << endl;
    cout << "t1++ = " << t1++ << " (затем t1 = " << t1 << ")" << endl;
    cout << "++t1 = " << ++t1 << endl;
    cout << "t1-- = " << t1-- << " (затем t1 = " << t1 << ")" << endl;
    cout << "--t1 = " << --t1 << endl;
    
    cout << "\nСравнение времени" << endl;
    cout << "t1 == t2: " << ((t1 == t2) ? "да" : "нет") << endl;
    cout << "t1 != t2: " << ((t1 != t2) ? "да" : "нет") << endl;
    cout << "t1 < t2: " << ((t1 < t2) ? "да" : "нет") << endl;
    cout << "t1 > t2: " << ((t1 > t2) ? "да" : "нет") << endl;
    
    cout << "\nОперации += и -= " << endl;
    Time t3 = t1;
    t3 += t2;
    cout << "t1 + t2 = " << t3 << endl;
    
    Time t4 = t1;
    t4 -= t2;
    cout << "t1 - t2 = " << t4 << endl;
    
    cout << "\nОператор ()" << endl;
    cout << "t1 в секундах = " << t1() << endl;
    cout << "t2 в секундах = " << t2() << endl;
    
    cout << "\nПрисваивание" << endl;
    Time t5;
    t5 = t1;
    cout << "t5 = t1: " << t5 << endl;
    
    cout << "\nВвод времени с клавиатуры" << endl;
    Time t6;
    cin >> t6;
    cout << "Вы ввели: " << t6 << endl;
    cout << "В секундах: " << t6() << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    testComplex();
    testTime();
    
    return 0;
}