#include "Cat.h"
#include <iostream>
using namespace std;

int Cat::count = 0;

Cat::Cat(const string& name, int age, const string& color)
    : name(name), age(age), color(color) {
    count++;
    cout << "Cat constructor: " << name << " (всего кошек: " << count << ")" << endl;
}

Cat::~Cat() {
    count--;
    cout << "Cat destructor: " << name << " (осталось кошек: " << count << ")" << endl;
}

void Cat::printInfo() const {
    cout << "Имя: " << name << ", Возраст: " << age << ", Окрас: " << color;
}

void Cat::sound() const {
    cout << name << " издаёт звук: Meow!" << endl;
}

int Cat::getCount() { return count; }