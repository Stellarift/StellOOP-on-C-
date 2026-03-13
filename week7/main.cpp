#include <iostream>
#include "Circle.h"
#include "Airplane.h"
using namespace std;

void testCircle() {
    cout << "\nЗадание 1, класс Circle" << endl;
    
    Circle c1(5);
    Circle c2(5);
    Circle c3(10);
    
    cout << "\nСозданные окружности " << endl;
    c1.print();
    c2.print();
    c3.print();
    
    cout << "\nПроверка на равенство (==)" << endl;
    cout << "c1 == c2: " << ((c1 == c2) ? "да" : "нет") << endl;
    cout << "c1 == c3: " << ((c1 == c3) ? "да" : "нет") << endl;
    
    cout << "\n--- Сравнение длин (>) ---" << endl;
    cout << "c1 > c3: " << ((c1 > c3) ? "да" : "нет") << endl;
    cout << "c3 > c1: " << ((c3 > c1) ? "да" : "нет") << endl;
    
    cout << "\nИзменение радиуса (+= и -=)" << endl;
    c1 += 2;
    c1.print();
    
    c1 -= 3;
    c1.print();
    
    cout << "\nПопытка сделать радиус <= 0" << endl;
    c1 -= 10;
}

void testAirplane() {
    cout << "\nЗадание 2, класс Airplane" << endl;
    
    Airplane a1("Boeing 737", 150);
    Airplane a2("Boeing 737", 150);
    Airplane a3("Airbus A320", 180);
    
    cout << "\nСозданные самолёты" << endl;
    a1.print();
    a2.print();
    a3.print();
    
    cout << "\nПроверка на равенство типов (==)" << endl;
    cout << "a1 == a2: " << ((a1 == a2) ? "да" : "нет") << endl;
    cout << "a1 == a3: " << ((a1 == a3) ? "да" : "нет") << endl;
    
    cout << "\nСравнение по максимальному количеству пассажиров (>=)" << endl;
    cout << "a3 >= a1: " << ((a3 >= a1) ? "да" : "нет") << endl;
    cout << "a1 >= a3: " << ((a1 >= a3) ? "да" : "нет") << endl;
    
    cout << "\n--- Демонстрация префиксного ++ и -- ---" << endl;
    Airplane a4("Boeing 737", 5);
    a4.print();
    
    ++a4;
    ++a4;
    ++a4;
    a4.print();
    
    --a4;
    a4.print();
    
    cout << "\nДемонстрация постфиксного ++ и -- " << endl;
    Airplane a5("Airbus A320", 3);
    a5.print();
    
    a5++;
    a5++;
    a5.print();
    
    a5--;
    a5.print();
    
    cout << "\nРазница между префиксным и постфиксным" << endl;
    Airplane a6("Test", 2);
    cout << "Исходное: ";
    a6.print();
    
    cout << "Префиксный: " << endl;
    cout << "  (++a6).print(): ";
    (++a6).print();
    cout << "  a6 после: ";
    a6.print();
    
    cout << "Постфиксный: " << endl;
    cout << "  (a6++).print(): ";
    (a6++).print();
    cout << "  a6 после: ";
    a6.print();
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "week7" << endl;
    
    testCircle();
    testAirplane();
    
    return 0;
}