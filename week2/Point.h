#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;
    double z;

public:
    Point();
    Point(double x, double y, double z);
    Point(const Point& other);
    
    ~Point();
    
    inline double getX() const { return x; }
    inline double getY() const { return y; }
    inline double getZ() const { return z; }
    
    inline void setX(double newX) { x = newX; }
    inline void setY(double newY) { y = newY; }
    inline void setZ(double newZ) { z = newZ; }
    
    void inputData();
    void displayData() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};

#endif