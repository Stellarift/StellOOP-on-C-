#include <iostream>
#include <stdexcept>
#include "Point.h"
#include "Vehicles.h"
#include "Garage.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "демо" << endl;
    
    // 1. Point
    cout << "\n1.Point" << endl;
    Point p1(3, 4), p2(3, 4), p3(5, 12);
    cout << "p1=" << p1 << ", p2=" << p2 << ", p3=" << p3 << endl;
    cout << "p1==p2: " << (p1==p2 ? "да" : "нет") << endl;
    cout << "p1==p3: " << (p1==p3 ? "да" : "нет") << endl;
    cout << "Всего точек: " << Point::getPointCount() << endl;
    
    // 2. Транспорт
    cout << "\n 2. Транспорт" << endl;
    Car car1("Toyota", 2020, Point(1,1), 4);
    Car car2("Honda", 2021, Point(2,2), 2);
    Bike bike1("Stels", 2022, Point(3,3), "mountain");
    Bike bike2("Author", 2023, Point(4,4), "sport");
    Vehicle* v1 = new Car("Lada", 2020, Point(5,5), 4);
    Vehicle* v2 = new Bike("Forward", 2021, Point(6,6), "city");
    cout << "Всего ТС: " << Vehicle::getTotalVehicles() << endl;
    
    // 3. Гараж с цепочкой
    cout << "\n3. Гараж" << endl;
    Garage<Vehicle*> garage1;
    garage1.add(&car1).add(&car2).add(&bike1).add(&bike2).add(v1).add(v2);
    
    for (int i = 0; i < garage1.getCount(); i++) {
        garage1[i]->print();
        cout << "   Max speed: " << garage1[i]->getMaxSpeed() << " km/h" << endl;
    }
    
    cout << "\n4. Перемещение" << endl;
    car1.move(Point(10,10));
    cout << "car1 после move: (" << car1.getX() << ", " << car1.getY() << ")" << endl;
    
    // 5. Копирование
    cout << "\n5. Копирование" << endl;
    Garage<Vehicle*> garage2 = garage1;
    cout << "garage2: " << garage2.getCount() << " элементов" << endl;
    
    // 6. Объединение
    cout << "\n 6. Объединение" << endl;
    Garage<Vehicle*> garage3;
    garage3.add(v1).add(v2);
    Garage<Vehicle*> garage4 = garage1 + garage3;
    cout << "garage1 + garage3: " << garage4.getCount() << " элементов" << endl;
    
    // 7. Префиксный ++
    cout << "\n7. Префиксный" << endl;
    cout << "car1 дверей: " << car1.getDoors() << " -> ++car1: " << (++car1).getDoors() << endl;
    
    // 8. Статистика
    cout << "\n8.Статистика" << endl;
    cout << "Всего точек: " << Point::getPointCount() << endl;
    cout << "Всего ТС: " << Vehicle::getTotalVehicles() << endl;
    cout << "Всего гаражей: " << Garage<Vehicle*>::getTotalGarages() << endl;
    
    // 9. Исключения
    cout << "\nИсключения" << endl;
    try { garage1[100]; }
    catch (const out_of_range& e) { cout << "Исключение: " << e.what() << endl; }
    
    delete v1;
    delete v2;
    
    return 0;
}