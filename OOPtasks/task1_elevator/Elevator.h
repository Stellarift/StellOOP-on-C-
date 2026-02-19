#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator {
private:
    int minFloor;
    int maxFloor;
    int currentFloor;
    bool isWorking;

public:
    Elevator(int minF, int maxF);
    
    void turnOn();
    void turnOff();
    
    bool getIsWorking();
    int getCurrentFloor();
    
    void call(int floor);
};

#endif