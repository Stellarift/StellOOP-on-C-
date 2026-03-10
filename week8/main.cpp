#include <iostream>
#include "Student.h"
#include "House.h"
using namespace std;

Student createStudent() {
    Student s("Temp Student", 20, 4.5);
    return s;
}

House createHouse() {
    House h("Temp Address", 2);
    Apartment a1(1);
    a1.addResident(Person("Temp Person", 30));
    h.addApartment(a1);
    return h;
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Встреча №8" << endl;
    
    cout << "\nЗадание 1" << endl;
    Student s1("Ivan Ivanov", 19, 4.8);
    Student s2 = move(s1);
    cout << "s2 after move: ";
    s2.display();
    
    cout << "\nMove from function return" << endl;
    Student s3 = createStudent();
    s3.display();
    
    cout << "\nЗадание 2" << endl;
    House h1("Lenina 10", 3);
    
    Apartment apt1(101);
    apt1.addResident(Person("Petrov Petr", 25));
    apt1.addResident(Person("Petrova Anna", 23));
    
    Apartment apt2(102);
    apt2.addResident(Person("Sidorov Sidr", 40));
    
    h1.addApartment(apt1);
    h1.addApartment(apt2);
    
    cout << "\nOriginal house:" << endl;
    h1.display();
    
    House h2 = move(h1);
    cout << "\nHouse after move:" << endl;
    h2.display();
    
    cout << "\n--- Move house from function ---" << endl;
    House h3 = createHouse();
    h3.display();
    
    return 0;
}