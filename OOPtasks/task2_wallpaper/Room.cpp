#include "Room.h"
#include <cstring>
using namespace std;

Room::Room(const char* n, double w, double h, double l, bool ceiling) {
    strcpy(name, n);
    width = w;
    height = h;
    length = l;
    glueCeiling = ceiling;
}

const char* Room::getName() { return name; }
double Room::getWidth() { return width; }
double Room::getHeight() { return height; }
double Room::getLength() { return length; }
bool Room::getGlueCeiling() { return glueCeiling; }

double Room::getArea() {
    double wallsArea = 2 * (width + length) * height;
    
    if (glueCeiling) {
        wallsArea += width * length;
    }
    
    return wallsArea;
}