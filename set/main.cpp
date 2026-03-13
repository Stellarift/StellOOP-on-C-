#include <iostream>
#include "IntSet.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Класс множества целых чисел" << endl;
    
    cout << "\nСоздание множеств" << endl;
    IntSet A, B;
    
    cout << "\nДобавление элементов в множество A" << endl;
    A += 3;
    A += 8;
    A += 46;
    A += 5;
    A += 11;
    cout << "A = " << A << endl;
    
    cout << "\nДобавление элементов в множество B" << endl;
    B += 18;
    B += 8;
    B += 90;
    B += 11;
    B += 2;
    cout << "B = " << B << endl;
    
    cout << "\nПопытка добавить существующий элемент" << endl;
    A += 3;
    cout << "A после A += 3: " << A << " (не изменилось)" << endl;
    
    cout << "\nУдаление элемента из множества A" << endl;
    A -= 46;
    cout << "A после A -= 46: " << A << endl;
    
    cout << "\nОперации с множествами" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    
    IntSet C = A + B;
    cout << "A + B (объединение) = " << C << endl;
    
    IntSet D = A - B;
    cout << "A - B (разность) = " << D << endl;
    
    IntSet E = A * B;
    cout << "A * B (пересечение) = " << E << endl;
    
    cout << "\nСоставные операции" << endl;
    IntSet F = A;
    F += B;
    cout << "F = A; F += B = " << F << endl;
    
    IntSet G = A;
    G -= B;
    cout << "G = A; G -= B = " << G << endl;
    
    IntSet H = A;
    H *= B;
    cout << "H = A; H *= B = " << H << endl;
    
    cout << "\nСравнение множеств" << endl;
    IntSet A1 = A;
    cout << "A = " << A << endl;
    cout << "A1 = " << A1 << endl;
    cout << "A == A1: " << ((A == A1) ? "истина" : "ложь") << endl;
    cout << "A == B: " << ((A == B) ? "истина" : "ложь") << endl;
    
    cout << "\nВвод множества с клавиатуры" << endl;
    IntSet userSet;
    cin >> userSet;
    cout << "Введённое множество: " << userSet << endl;
    
    return 0;
}