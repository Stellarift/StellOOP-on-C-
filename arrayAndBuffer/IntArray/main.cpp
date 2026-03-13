#include <iostream>
#include "IntArray.h"
using namespace std;

void processByValue(IntArray arr) {
    cout << "Внутри processByValue: ";
    arr.print();
}

IntArray createArray(size_t n) {
    IntArray arr(n);
    return arr;
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Задание 1" << endl;
    
    cout << "\n1. Конструктор по умолчанию" << endl;
    IntArray arr1;
    cout << "arr1: "; arr1.print();
    
    cout << "\n2. Конструктор с размером" << endl;
    IntArray arr2(5);
    cout << "arr2: "; arr2.print();
    
    cout << "\n3. Копирование (lvalue)" << endl;
    IntArray arr3 = arr2;
    cout << "arr3 (копия arr2): "; arr3.print();
    
    cout << "\n4. Перемещение из временного объекта" << endl;
    IntArray arr4 = createArray(3);
    cout << "arr4: "; arr4.print();
    
    cout << "\n5. Перемещение с помощью std::move" << endl;
    IntArray arr5(4);
    cout << "arr5 до перемещения: "; arr5.print();
    
    IntArray arr6 = std::move(arr5);
    cout << "arr5 после перемещения: "; arr5.print();
    cout << "arr6 после перемещения: "; arr6.print();
    
    cout << "\n6. Присваивание копированием" << endl;
    IntArray arr7;
    arr7 = arr2;
    cout << "arr7 после arr7 = arr2: "; arr7.print();
    
    cout << "\n7. Присваивание перемещением" << endl;
    IntArray arr8;
    arr8 = std::move(arr3);
    cout << "arr3 после перемещения: "; arr3.print();
    cout << "arr8 после arr8 = std::move(arr3): "; arr8.print();
    
    cout << "\n8. Передача в функцию по значению" << endl;
    processByValue(arr2);
    
    return 0;
}