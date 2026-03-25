#include <iostream>
#include <vector>
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"
#include "Horse.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

void testAnimals() {
    cout << "\nПервое задание с животными" << endl;
    
    vector<Animal*> animals;
    
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());
    
    for (Animal* animal : animals) {
        animal->speak();
    }
    
    for (Animal* animal : animals) {
        delete animal;
    }
}

void testShapes() {
    cout << "\nВторое заданьеце с геомертю. фигурами" << endl;
    
    vector<Shape*> shapes;
    
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4, 5));
    
    for (Shape* shape : shapes) {
        shape->printInfo();
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
    }
    
    for (Shape* shape : shapes) {
        delete shape;
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    testAnimals();
    testShapes();
    
    return 0;
}