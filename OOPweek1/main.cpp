#include <iostream>
#include "Student.h"
#include "Point.h"

using namespace std;

int main() {
    cout << "ЗАДАНИЕ 1: СТУДЕНТ\n";
    Student student;
    student.inputData();
    student.displayData();
    
    cout << "\nМеняем номер группы:\n";
    student.setGroupNumber("ПИН-231");
    cout << "Новый номер группы: " << student.getGroupNumber() << endl;
    
    cout << "\nЗАДАНИЕ 2: ТОЧКА\n";
    Point point;
    point.inputData();
    point.displayData();
    
    cout << "\nМеняем координату X:\n";
    point.setX(99.9);
    cout << "Новая координата X: " << point.getX() << endl;
    
    return 0;
}