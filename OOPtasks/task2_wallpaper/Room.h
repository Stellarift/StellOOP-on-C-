#ifndef ROOM_H
#define ROOM_H

class Room {
private:
    char name[50];
    double width;
    double height;
    double length;
    bool glueCeiling;

public:
    Room(const char* n, double w, double h, double l, bool ceiling);
    
    const char* getName();
    double getWidth();
    double getHeight();
    double getLength();
    bool getGlueCeiling();
    
    double getArea();
};

#endif