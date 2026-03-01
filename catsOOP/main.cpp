#include <iostream>
#include "Cat.h"
#include "HouseCat.h"
#include "WildCat.h"
#include "PersianCat.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Иерархия классов 'КОШКИ'" << endl;
    cout << "Тема: Наследование" << endl << endl;
    
    cout << "Создание объектов" << endl;
    

    Cat basicCat("БазоваяКошка", 3, "Рыжий");
    HouseCat houseCat("Мурка", 2, "Серый", "Иван Петров");
    WildCat wildCat("Тигрица", 5, "Полосатый", "Джунгли");
    PersianCat persianCat("Снежок", 1, "Белый", 15);
    
    cout << "\nДемонстрация работы методов" << endl;
    
    // Вызов методов
    cout << "\nБазовая кошка" << endl;
    basicCat.printInfo();
    cout << endl;
    basicCat.sound();
    
    cout << "\nДомашняя кошка" << endl;
    houseCat.printInfo();
    houseCat.sound();
    houseCat.play();
    
    cout << "\nДикая кошка" << endl;
    wildCat.printInfo();
    wildCat.sound();
    wildCat.hunt();
    
    cout << "\nПерсидская кошка" << endl;
    persianCat.printInfo();
    persianCat.sound();
    persianCat.groom();
    
    cout << "\nДемонстрация цепочки конструкторов и деструкторов" << endl;
    
    {
        cout << "\nВходим во вложенный блок..." << endl;
        HouseCat tempCat("Временный", 1, "Черный", "Анна");
        cout << "Выходим из блока..." << endl;
    }
    
    cout << "\nСтатический подсчет объектов" << endl;
    cout << "Всего создано объектов Cat: " << Cat::getCount() << endl;
    
    cout << "\nПрограмма завершена" << endl;
    
    return 0;
}