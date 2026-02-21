#include <iostream>
#include "Geometry.h"
#include "Point.h"
#include "Fraction.h"
#include "Student.h"
using namespace std;

void testGeometry() {
    cout << "\n Зад.1 площади фигур" << endl;
    
    cout << "Прямоугольник 5x3: " << Geometry::rectangleArea(5, 3) << endl;
    cout << "Квадрат 4: " << Geometry::squareArea(4) << endl;
    cout << "Треугольник (основание 6, высота 4): " 
         << Geometry::triangleArea(6, 4) << endl;
    cout << "Треугольник (стороны 3,4,5): " 
         << Geometry::triangleArea(3, 4, 5) << endl;
    cout << "Ромб (диагонали 6 и 8): " 
         << Geometry::rhombusAreaByDiagonals(6, 8) << endl;
    cout << "Ромб (сторона 5, угол 60°): " 
         << Geometry::rhombusAreaBySideAndAngle(5, 60) << endl;
    
    cout << "Всего подсчетов площади: " 
         << Geometry::getCalculationCount() << endl;
}

void testPoint() {
    cout << "\n Точка (с делегированием)" << endl;
    cout << "Объектов Point сейчас: " << Point::getObjectCount() << endl;
    
    Point p1;
    Point p2(10, 20, 30);
    Point p3 = p2;
    
    p1.display();
    p2.display();
    p3.display();
    
    cout << "Объектов Point сейчас: " << Point::getObjectCount() << endl;
}

void testFraction() {
    cout << "\nДробь (с делегированием) " << endl;
    cout << "Объектов Fraction сейчас: " << Fraction::getObjectCount() << endl;
    
    Fraction f1;
    Fraction f2(5);
    Fraction f3(3, 4);
    Fraction f4 = f3;
    
    cout << "f1: "; f1.display(); cout << endl;
    cout << "f2: "; f2.display(); cout << endl;
    cout << "f3: "; f3.display(); cout << endl;
    cout << "f4: "; f4.display(); cout << endl;
    
    cout << "Объектов Fraction сейчас: " << Fraction::getObjectCount() << endl;
}

void testStudent() {
    cout << "\nСтудент (с делегированием)" << endl;
    cout << "Объектов Student сейчас: " << Student::getObjectCount() << endl;
    
    Student s1;
    Student s2("Иванов Иван");
    Student s3("Петров Петр", "15.05.2000", "+123456789");
    Student s4("Сидоров Сидор", "20.10.2001", "+987654321",
               "Москва", "Россия", "МГУ", "Москва", "Россия", "ПИ-201");
    Student s5 = s4;
    
    cout << "\nСтудент 1 (пустой)" << endl;
    s1.display();
    
    cout << "\nСтудент 2 (только имя)" << endl;
    s2.display();
    
    cout << "\n Студент 3 (имя + дата + телефон)" << endl;
    s3.display();
    
    cout << "\nСтудент 4 (полный)" << endl;
    s4.display();
    
    cout << "\n Студент 5 (копия 4) " << endl;
    s5.display();
    
    cout << "\nОбъектов Student сейчас: " << Student::getObjectCount() << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Встреча №3" << endl;
    
    testGeometry();
    testPoint();
    testFraction();
    testStudent();
    
    cout << "\n Завершено" << endl;
    
    return 0;
}