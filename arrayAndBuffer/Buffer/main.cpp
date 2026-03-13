#include <iostream>
#include <vector>
#include "Buffer.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Задание 4" << endl;
    
    cout << "\n1. Обычное создание" << endl;
    Buffer buf1(100);
    cout << "buf1: "; buf1.print();
    
    cout << "\n2. Копирование" << endl;
    Buffer buf2 = buf1;
    cout << "buf2 (копия buf1): "; buf2.print();
    
    cout << "\n3. Перемещение с помощью std::move" << endl;
    Buffer buf3 = std::move(buf1);
    cout << "buf1 после перемещения: "; buf1.print();
    cout << "buf3 после перемещения: "; buf3.print();
    
    cout << "\n4. Присваивание перемещением" << endl;
    Buffer buf4(50);
    cout << "buf4 до: "; buf4.print();
    buf4 = std::move(buf2);
    cout << "buf2 после перемещения: "; buf2.print();
    cout << "buf4 после присваивания: "; buf4.print();
    
    cout << "\n5. Демонстрация с вектором" << endl;
    vector<Buffer> v;
    v.reserve(2);
    
    Buffer temp(200);
    cout << "temp: "; temp.print();
    
    cout << "Добавляем temp (копирование):" << endl;
    v.push_back(temp);
    
    cout << "Добавляем std::move(temp) (перемещение):" << endl;
    v.push_back(std::move(temp));
    cout << "temp после перемещения: "; temp.print();
    
    return 0;
}