#include <iostream>
#include "Array.h"
#include "Var.h"
using namespace std;

void testArray() {
    cout << "\nЗадание 1" << endl;
    
    Array arr(5);
    arr.fillRandom();
    cout << "Исходный массив:" << endl;
    arr.display();
    
    cout << "Элемент с индексом 2: " << arr[2] << endl;
    arr[2] = 99;
    cout << "После изменения arr[2] = 99:" << endl;
    arr.display();
    
    arr(10);
    cout << "После увеличения всех элементов на 10:" << endl;
    arr.display();
    
    int sum = arr;
    cout << "Сумма всех элементов: " << sum << endl;
    
    char* str = (char*)arr;
    cout << "Массив в виде строки: " << str << endl;
    delete[] str;
}

void testVar() {
    cout << "\nЗадание 2" << endl;
    
    Var a = 15;
    Var b = "Привет";
    Var c = 7.8;
    Var d = "50";
    
    cout << "a = "; a.print(); cout << " (целое число)" << endl;
    cout << "b = "; b.print(); cout << " (строка)" << endl;
    cout << "c = "; c.print(); cout << " (дробное число)" << endl;
    cout << "d = "; d.print(); cout << " (строка)" << endl;
    
    Var e = a + d;
    cout << "a + d = "; e.print(); cout << endl;
    
    Var f = b + a;
    cout << "b + a = "; f.print(); cout << endl;
    
    Var g = a * 3;
    cout << "a * 3 = "; g.print(); cout << endl;
    
    Var h = b * 3;
    cout << "b * 3 = "; h.print(); cout << endl;
    
    Var i = 20;
    Var j = 20;
    cout << "20 == 20: " << ((i == j) ? "истина" : "ложь") << endl;
    cout << "15 == \"Привет\": " << ((a == b) ? "истина" : "ложь") << endl;
    
    Var k = 25;
    Var l = "25";
    Var m = k + l;
    cout << "25 (число) + \"25\" (строка) = "; m.print(); cout << endl;
    
    Var n = 100;
    Var o = 3;
    Var p = n / o;
    cout << "100 / 3 = "; p.print(); cout << endl;
    
    Var q = 10.5;
    Var r = 5;
    cout << "10.5 > 5: " << ((q > r) ? "истина" : "ложь") << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Встреча №9" << endl;
    cout << "Темы: перегрузка [] и (), преобразование типов, класс Var" << endl;
    
    testArray();
    testVar();
    
    return 0;
}