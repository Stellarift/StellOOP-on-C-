#pragma once
#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y, z;

public:
    Point();
    
    void inputData();
    void displayData() const;
    
    double getX() const;
    double getY() const;
    double getZ() const;
    
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
};

#endif