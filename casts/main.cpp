#include <iostream>
#include <vector>
#include "Shapes.h"
#include "DataHolder.h"
using namespace std;

// задание 1.1 dynamic cast
void identifyAndDraw(Shape* s) {
    Circle* circle = dynamic_cast<Circle*>(s);
    if (circle) {
        cout << "Обнаружен Circle! ";
        circle->draw();
        return;
    }
    
    Rectangle* rect = dynamic_cast<Rectangle*>(s);
    if (rect) {
        cout << "Обнаружен Rectangle! ";
        rect->draw();
        return;
    }
    
    cout << "Неизвестный тип фигуры" << endl;
}

void testDynamicCast() {
    cout << "\nзадание 1.1 dynamic cast" << endl;
    
    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Circle(3.0),
        new Rectangle(2.0, 8.0)
    };
    
    for (Shape* s : shapes) {
        identifyAndDraw(s);
    }
    
    for (Shape* s : shapes) {
        delete s;
    }
}

// 1.2 const_cast
void modifyData(const DataHolder& dh) {
    DataHolder& nonConstDh = const_cast<DataHolder&>(dh);
    vector<int>& data = const_cast<vector<int>&>(dh.getData());
    
    if (!data.empty()) {
        data[0] = 999;
        cout << "Первый элемент изменён на 999" << endl;
    }
}

void testConstCast() {
    cout << "\nЗадание 1.2 const_cast" << endl;
    
    vector<int> vec = {10, 20, 30, 40, 50};
    DataHolder dh(vec);
    
    cout << "До изменения: ";
    dh.print();
    
    modifyData(dh);
    
    cout << "После изменения: ";
    dh.print();
    
}

int main() {
    setlocale(LC_ALL, "");
    
    testDynamicCast();
    testConstCast();
    
    return 0;
}