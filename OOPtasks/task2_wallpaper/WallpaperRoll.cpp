#include "WallpaperRoll.h"
#include <cstring>
using namespace std;

WallpaperRoll::WallpaperRoll(const char* n, double w, double l, double p) {
    strcpy(name, n);
    width = w;
    length = l;
    price = p;
}

const char* WallpaperRoll::getName() { return name; }
double WallpaperRoll::getWidth() { return width; }
double WallpaperRoll::getLength() { return length; }
double WallpaperRoll::getPrice() { return price; }

double WallpaperRoll::getArea() {
    return width * length;
}