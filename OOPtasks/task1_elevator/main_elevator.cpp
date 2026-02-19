#include <iostream>
#include "Elevator.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "тест лифта" << endl;
    
    Elevator lift(1, 9);
    
    lift.call(5);
    lift.call(7);
    lift.call(2);
    
    lift.turnOff();
    lift.call(4);
    
    lift.turnOn();
    lift.call(4);
    
    lift.call(10);
    
    return 0;
}