#pragma once

#include <string>
#include "Point.h"
using namespace std;

// базовый класс
class Vehicle {
protected:
    string model;
    int year;
    Point position;
    static int totalVehicles;

public:
    Vehicle(const string& model, int year, const Point& pos) 
        : model(model), year(year), position(pos) { totalVehicles++; }
    
    Vehicle(const Vehicle& other) 
        : model(other.model), year(other.year), position(other.position) { totalVehicles++; }
    
    explicit Vehicle(const string& model) 
        : model(model), year(2020), position(Point(0,0)) { totalVehicles++; }
    
    virtual ~Vehicle() { totalVehicles--; }
    
    static int getTotalVehicles() { return totalVehicles; }
    
    void move(const Point& newPos) { position = newPos; }
    
    // Геттеры для позиции (чтобы получить x и y из Car)
    double getX() const { return position.getX(); }
    double getY() const { return position.getY(); }
    
    virtual double getMaxSpeed() const = 0;
    virtual void print() const = 0;
};

int Vehicle::totalVehicles = 0;

// car
class Car : public Vehicle {
private:
    int doors;

public:
    Car(const string& model, int year, const Point& pos, int doors) 
        : Vehicle(model, year, pos), doors(doors) {}
    
    double getMaxSpeed() const override { return 180.0; }
    
    void print() const override {
        cout << "Car: " << model << ", " << year << ", position " << position 
             << ", doors: " << doors << endl;
    }
    
    // Геттер для дверей
    int getDoors() const { return doors; }
    
    Car& operator++() { ++doors; return *this; }
    Car operator++(int) { Car temp = *this; ++doors; return temp; }
};

// bike
class Bike : public Vehicle {
private:
    string type;

public:
    Bike(const string& model, int year, const Point& pos, const string& type) 
        : Vehicle(model, year, pos), type(type) {}
    
    double getMaxSpeed() const override { return 60.0; }
    
    void print() const override {
        cout << "Bike: " << model << ", " << year << ", position " << position 
             << ", type: " << type << endl;
    }
};