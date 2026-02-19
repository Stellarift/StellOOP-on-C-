#ifndef WALLPAPERROLL_H
#define WALLPAPERROLL_H

class WallpaperRoll {
private:
    char name[50];
    double width;
    double length;
    double price;

public:
    WallpaperRoll(const char* n, double w, double l, double p);
    
    const char* getName();
    double getWidth();
    double getLength();
    double getPrice();
    
    double getArea();
};

#endif