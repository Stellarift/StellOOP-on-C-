#include "Apartment.h"
#include <iostream>
using namespace std;

Apartment::Apartment() {
    roomCount = 0;
}

void Apartment::addRoom(Room* room) {
    if (roomCount < 10) {
        rooms[roomCount] = room;
        roomCount++;
    }
}

void Apartment::calculate(WallpaperRoll* roll) {
    if (roomCount == 0) {
        cout << "Нет комнат для расчета!" << endl;
        return;
    }
    
    cout << "\n Расчет обоев " << endl;
    cout << "Рулон: " << roll->getName() << endl;
    cout << "Размер рулона: " << roll->getWidth() << "м x " 
         << roll->getLength() << "м" << endl;
    cout << "Площадь рулона: " << roll->getArea() << " кв.м" << endl;
    
    double totalArea = 0;
    
    cout << "\nКомнаты:" << endl;
    for (int i = 0; i < roomCount; i++) {
        double roomArea = rooms[i]->getArea();
        totalArea += roomArea;
        
        cout << "- " << rooms[i]->getName() 
             << ": площадь " << roomArea << " кв.м";
        if (rooms[i]->getGlueCeiling()) {
            cout << " (с потолком)";
        }
        cout << endl;
    }
    
    int rollsNeeded = (int)(totalArea / roll->getArea()) + 1;
    double totalPrice = rollsNeeded * roll->getPrice();
    
    cout << "\n результат " << endl;
    cout << "Нужно рулонов: " << rollsNeeded << endl;
    cout << "Общая стоимость: " << totalPrice << " руб." << endl;
}