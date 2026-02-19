#ifndef APARTMENT_H
#define APARTMENT_H
#include "Room.h"
#include "WallpaperRoll.h"

class Apartment {
private:
    Room* rooms[10];
    int roomCount;

public:
    Apartment();
    
    void addRoom(Room* room);
    void calculate(WallpaperRoll* roll);
};

#endif