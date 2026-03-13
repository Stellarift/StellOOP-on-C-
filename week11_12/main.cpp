#include <iostream>
#include "Array.h"
using namespace std;

// Объявления демо-функций из заданий 11
void demoTask1();
void demoTask2();
void demoTask3();
void demoTask4();

void demoArray() {
    cout << "\nВстреча №12" << endl;
    
    cout << "\n1. Создание массива int" << endl;
    Array<int> arr1(5, 2);
    for (int i = 0; i < 5; i++) {
        arr1[i] = i * 10;
    }
    cout << "arr1: "; arr1.Print();
    cout << "Size: " << arr1.GetSize() << ", UpperBound: " << arr1.GetUpperBound() << endl;
    
    cout << "\n2. Добавление элементов (Add)" << endl;
    arr1.Add(50);
    arr1.Add(60);
    arr1.Add(70);
    cout << "После Add: "; arr1.Print();
    
    cout << "\n3. Установка нового размера (SetSize)" << endl;
    arr1.SetSize(10, 3);
    cout << "После SetSize(10,3): "; arr1.Print();
    
    cout << "\n4. Удаление лишней памяти (FreeExtra)" << endl;
    arr1.FreeExtra();
    cout << "После FreeExtra: "; arr1.Print();
    
    cout << "\n5. Вставка элемента (InsertAt)" << endl;
    arr1.InsertAt(2, 999);
    cout << "После InsertAt(2, 999): "; arr1.Print();
    
    cout << "\n6. Удаление элемента (RemoveAt)" << endl;
    arr1.RemoveAt(3);
    cout << "После RemoveAt(3): "; arr1.Print();
    
    cout << "\n7. Создание массива double" << endl;
    Array<double> arr2(3);
    arr2[0] = 1.1;
    arr2[1] = 2.2;
    arr2[2] = 3.3;
    cout << "arr2: "; arr2.Print();
    
    cout << "\n8. Сложение массивов (Append)" << endl;
    Array<int> arr3(3);
    arr3[0] = 100;
    arr3[1] = 200;
    arr3[2] = 300;
    
    Array<int> arr4 = arr1.Append(arr3);
    cout << "arr1: "; arr1.Print();
    cout << "arr3: "; arr3.Print();
    cout << "arr1.Append(arr3): "; arr4.Print();
    
    cout << "\n9. Оператор присваивания" << endl;
    Array<int> arr5;
    arr5 = arr1;
    cout << "arr5 (копия arr1): "; arr5.Print();
    
    cout << "\n10. Вставка массива (InsertAt with Array)" << endl;
    arr1.InsertAt(1, arr3);
    cout << "arr1 после InsertAt(1, arr3): "; arr1.Print();
    
    cout << "\n11. Удаление нескольких элементов" << endl;
    arr1.RemoveAt(2, 3);
    cout << "arr1 после RemoveAt(2, 3): "; arr1.Print();
    
    cout << "\n12. Проверка на пустоту" << endl;
    cout << "arr1.IsEmpty(): " << (arr1.IsEmpty() ? "да" : "нет") << endl;
    Array<int> arr6;
    cout << "arr6.IsEmpty(): " << (arr6.IsEmpty() ? "да" : "нет") << endl;
    
    cout << "\n13. Удаление всех элементов" << endl;
    arr1.RemoveAll();
    cout << "arr1 после RemoveAll(): "; arr1.Print();
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Встреча №11 шаблоны" << endl;
    
    demoTask1();
    demoTask2();
    demoTask3();
    demoTask4();
    
    demoArray();
    
    return 0;
}