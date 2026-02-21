#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry {
private:
    static int calculationCount;  // счетчик подсчетов площади

public:
    // Статические методы для подсчета площади
    static double triangleArea(double a, double b, double c);  // по трем сторонам
    static double triangleArea(double base, double height);    // по основанию и высоте
    static double rectangleArea(double width, double height);
    static double squareArea(double side);
    static double rhombusAreaByDiagonals(double d1, double d2);          // по диагоналям
    static double rhombusAreaBySideAndAngle(double side, double angle);     // по стороне и углу
    
    // Статический метод для получения количества подсчетов
    static int getCalculationCount();
};

#endif