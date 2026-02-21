#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y, z;
    static int objectCount;  // счетчик созданных объектов

public:
    // Конструкторы с делегированием
    Point();                                  // делегирует Point(0,0,0)
    Point(double x, double y, double z);      // основной конструктор
    Point(const Point& other);                // копирования
    
    ~Point();
    
    // Статическая функция для получения количества объектов
    static int getObjectCount();
    
    // Аксессоры
    inline double getX() const { return x; }
    inline double getY() const { return y; }
    inline double getZ() const { return z; }
    
    inline void setX(double newX) { x = newX; }
    inline void setY(double newY) { y = newY; }
    inline void setZ(double newZ) { z = newZ; }
    
    void display() const;
};

#endif