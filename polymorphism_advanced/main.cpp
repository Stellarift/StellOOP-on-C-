#include <iostream>
#include <vector>
#include "Strings.h"
#include "Shapes.h"
#include "Vehicles.h"
#include "Employees.h"
using namespace std;

void testTask3() {
    cout << "\n3 задание виртуальность" << endl;
    
    StringHolder* s1 = new StringHolder("Hello");
    StringHolder* s2 = new ReverseString("World");
    
    s1->print(); cout << endl;
    s2->print(); cout << endl;
    
    delete s1;
    delete s2;
}

void testTask4() {
    cout << "\n4 задание множественное наследование" << endl;
    
    vector<Drawable*> drawables;
    drawables.push_back(new Circle(10, 20, 5));
    drawables.push_back(new Rectangle(0, 0, 30, 15));
    
    for (auto d : drawables) d->draw();
    for (auto d : drawables) delete d;
    
    vector<Serializable*> serializables;
    serializables.push_back(new Circle(10, 20, 5));
    serializables.push_back(new Rectangle(0, 0, 30, 15));
    
    for (auto s : serializables) cout << "Serialized: " << s->serialize() << endl;
    for (auto s : serializables) delete s;
}

void testTask5() {
    cout << "\n5 задание с транспортом" << endl;
    
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car());
    vehicles.push_back(new ElectricCar());
    vehicles.push_back(new Bicycle());
    
    for (auto v : vehicles) {
        v->startEngine();
        cout << "Max speed: " << v->getMaxSpeed() << " km/h" << endl;
        v->info();
    }
    
    for (auto v : vehicles) delete v;
    
}

void testTask6() {
    cout << "\n6 задание с сотрудниками" << endl;
    
    vector<Employee*> employees;
    employees.push_back(new Manager("Alice", 5000));
    employees.push_back(new Engineer("Bob", 30, 160));
    employees.push_back(new SalesPerson("Charlie", 2000, 50000, 5));
    
    double totalSalary = 0;
    for (auto e : employees) {
        e->displayInfo();
        double salary = e->calculateSalary();
        cout << "Salary: $" << salary << endl;
        totalSalary += salary;
    }
    
    cout << "Total payroll: $" << totalSalary << endl;
    for (auto e : employees) delete e;
}

int main() {
    setlocale(LC_ALL, "");
    
    testTask3();
    testTask4();
    testTask5();
    testTask6();
    
    return 0;
}