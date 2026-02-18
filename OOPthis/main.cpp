#include <iostream>
#include "Fraction.h"
#include "Person.h"
#include "String.h"
#include "House.h"
using namespace std;

int main() {
    cout << "ЗАДАНИЕ 1: ДРОБЬ" << endl;
    Fraction a(1, 2);
    Fraction b(2, 3);
    
    cout << "a = "; a.print(); cout << endl;
    cout << "b = "; b.print(); cout << endl;
    
    a.slozhenie(b)->umnozhenie(2)->vychitanie(1);
    cout << "a после цепочки: "; a.print(); cout << endl;
    
    cout << "\nЗАДАНИЕ 2: ЧЕЛОВЕК" << endl;
    cout << "Всего людей: " << Person::getCount() << endl;
    
    Person p1(1, "Иванов", "Иван", "Иванович", 15, 5, 1990);
    Person p2(2, "Петрова", "Мария", "Сергеевна", 23, 8, 1985);
    
    cout << "\nЧеловек 1:" << endl;
    p1.print();
    cout << "\nЧеловек 2:" << endl;
    p2.print();
    
    Person p3 = p1;
    cout << "\nЧеловек 3 (копия):" << endl;
    p3.print();
    
    cout << "Всего людей: " << Person::getCount() << endl;
    
    cout << "\nЗАДАНИЕ 3: СТРОКА" << endl;
    String s1("Привет");
    String s2("Мир");
    String s3 = s1;
    
    cout << "s1: "; s1.print(); cout << endl;
    cout << "s2: "; s2.print(); cout << endl;
    cout << "s3: "; s3.print(); cout << endl;
    
    s1.set("Привет, Мир!");
    cout << "s1 после set: "; s1.print(); cout << endl;
    
    cout << "\nЗАДАНИЕ 4: ДОМ" << endl;
    House dom("Ленина, 10", 3);
    
    Apartment kv1(0);
    kv1.dobavitZhiltza(Person(101, "Сидоров", "Петр", "Алексеевич", 10, 3, 1980));
    kv1.dobavitZhiltza(Person(102, "Сидорова", "Анна", "Ивановна", 15, 7, 1982));
    
    Apartment kv2(1);
    kv2.dobavitZhiltza(Person(201, "Козлов", "Иван", "Петрович", 5, 12, 1975));
    
    Apartment kv3(2);
    kv3.dobavitZhiltza(Person(301, "Смирнова", "Елена", "Дмитриевна", 20, 9, 1995));
    kv3.dobavitZhiltza(Person(302, "Смирнов", "Дмитрий", "Егорович", 25, 11, 1992));
    kv3.dobavitZhiltza(Person(303, "Смирнова", "Ольга", "Дмитриевна", 3, 6, 2020));
    
    dom.dobavitKvartiru(kv1);
    dom.dobavitKvartiru(kv2);
    dom.dobavitKvartiru(kv3);
    
    dom.print();
    
    cout << "\nДЕСТРУКТОРЫ" << endl;
    return 0;
}