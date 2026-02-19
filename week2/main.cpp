#include <iostream>
#include "Point.h"
#include "Fraction.h"
#include "Student.h"
using namespace std;

void testPoint() {
    cout << "\n ЗАД. 1 ТОЧКА " << endl;
    
    cout << "\n--- Создание точки через конструктор по умолчанию ---" << endl;
    Point p1;
    p1.displayData();
    
    cout << "\n--- Создание точки через конструктор с параметрами ---" << endl;
    Point p2(10.5, 20.7, 30.9);
    p2.displayData();
    
    cout << "\n Создание копии точки " << endl;
    Point p3 = p2;
    p3.displayData();
    
    cout << "\nохранение в файл и загрузка из файла " << endl;
    p2.saveToFile("point.txt");
    p1.loadFromFile("point.txt");
    p1.displayData();
    
    cout << "\n--- Использование геттеров и сеттеров ---" << endl;
    cout << "Координата X второй точки: " << p2.getX() << endl;
    p2.setX(99.9);
    cout << "Новая координата X после изменения: " << p2.getX() << endl;
}

void testFraction() {
    cout << "\nЗАД.2 ДРОБЬ " << endl;
    
    cout << "\n--- Создание дроби через конструктор по умолчанию ---" << endl;
    Fraction f1;
    cout << "f1 = "; f1.print(); cout << endl;
    
    cout << "\nСоздание дроби через конструктор с параметрами " << endl;
    Fraction f2(3, 4);
    cout << "f2 = "; f2.print(); cout << endl;
    
    cout << "\nСоздание копии дроби " << endl;
    Fraction f3 = f2;
    cout << "f3 = "; f3.print(); cout << endl;
    
    cout << "\n Демонстрация цепочки операций " << endl;
    Fraction f4(1, 2);
    cout << "f4 = "; f4.print(); cout << endl;
    cout << "Выполняем f4.add(f2)->multiply(2)->subtract(1)" << endl;
    f4.add(f2)->multiply(2)->subtract(1);
    cout << "Результат: f4 = "; f4.print(); cout << endl;
}

void testStudent() {
    cout << "\n ЗАД.4 СТУДЕНТ " << endl;
    
    cout << "\n Создание студента через конструктор по умолчанию " << endl;
    Student s1;
    s1.displayData();
    
    cout << "\n Создание студента через конструктор с параметрами " << endl;
    Student s2("Иванов Иван Иванович", "15.05.2000", "+1234567890",
               "Москва", "Россия", "МГУ", "Москва", "Россия", "ПИ-201");
    s2.displayData();
    
    cout << "\nСоздание копии студента" << endl;
    Student s3 = s2;
    s3.displayData();
    
    cout << "\n Изменение данных через сеттеры " << endl;
    s1.setFullName("Петров Петр Петрович");
    s1.setBirthDate("20.10.2001");
    s1.setGroupNumber("ФИ-101");
    s1.displayData();
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "   ТЕСТИРОВАНИЕ КЛАССОВ (ВСТРЕЧА №2)   " << endl;
    
    testPoint();
    testFraction();
    testStudent();
    
    cout << "Программа завершена" << endl;
    
    return 0;
}