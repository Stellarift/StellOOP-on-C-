#include <iostream>
#include "String.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Встреча №3 string " << endl;
    
    cout << "\n 1. Конструктор по умолчанию (80 символов) " << endl;
    String s1;
    s1.output();
    
    cout << "\n 2. Конструктор с произвольным размером " << endl;
    String s2(50);
    s2.output();
    
    cout << "\n 3. Конструктор с инициализацией строкой " << endl;
    String s3("Привет, мир!");
    s3.output();
    
    cout << "\n 4. Конструктор копирования " << endl;
    String s4 = s3;
    s4.output();
    
    cout << "\n 5. Статическая функция подсчета объектов " << endl;
    cout << "Количество созданных объектов: " << String::getObjectCount() << endl;
    
    cout << "\n 6. Ввод строки с клавиатуры " << endl;
    String s5;
    s5.input();
    s5.output();
    
    cout << "\n 7. Демонстрация работы со строками " << endl;
    {
        cout << "Создаем строку во вложенном блоке:" << endl;
        String temp("Временная строка");
        temp.output();
        cout << "Объектов сейчас: " << String::getObjectCount() << endl;
    } // здесь вызовется деструктор для temp
    cout << "После выхода из блока объектов: " << String::getObjectCount() << endl;
    
    cout << "\n 8. Массив строк " << endl;
    String* strings = new String[3]{
        String("Первая"),
        String("Вторая"),
        String("Третья")
    };
    
    cout << "\nСодержимое массива:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ": ";
        strings[i].output();
    }
    
    delete[] strings;
    cout << "После удаления массива объектов: " << String::getObjectCount() << endl;
    
    cout << "\n Завершение " << endl;
    
    return 0;
}