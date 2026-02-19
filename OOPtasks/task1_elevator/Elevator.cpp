#include "Elevator.h"
#include <iostream>
using namespace std;

Elevator::Elevator(int minF, int maxF) {
    minFloor = minF;
    maxFloor = maxF;
    currentFloor = minF;
    isWorking = true;
    cout << "Лифт создан. Этажи: " << minFloor << " - " << maxFloor << endl;
}

void Elevator::turnOn() {
    isWorking = true;
    cout << "Лифт включен" << endl;
}

void Elevator::turnOff() {
    isWorking = false;
    cout << "Лифт выключен" << endl;
}

bool Elevator::getIsWorking() {
    return isWorking;
}

int Elevator::getCurrentFloor() {
    return currentFloor;
}

void Elevator::call(int floor) {
    if (!isWorking) {
        cout << "Лифт не работает!" << endl;
        return;
    }
    
    if (floor < minFloor || floor > maxFloor) {
        cout << "Этаж " << floor << " вне диапазона!" << endl;
        return;
    }
    
    cout << "Лифт едет с " << currentFloor << " на " << floor;
    
    if (floor > currentFloor) {
        cout << " (вверх)";
    } else if (floor < currentFloor) {
        cout << " (вниз)";
    }
    
    currentFloor = floor;
    cout << "\nЛифт прибыл на этаж " << currentFloor << endl;
}