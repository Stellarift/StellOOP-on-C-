#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;

Person::Person() : name(nullptr), age(0) {
    name = new char[1];
    name[0] = '\0';
    cout << "Person default constructor" << endl;
}

Person::Person(const char* name, int age) : age(age) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    cout << "Person parameter constructor: " << this->name << endl;
}

Person::Person(const Person& other) : age(other.age) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    cout << "Person copy constructor: " << name << endl;
}

Person::Person(Person&& other) noexcept : name(other.name), age(other.age) {
    other.name = nullptr;
    cout << "Person move constructor: " << name << endl;
}

Person::~Person() {
    cout << "Person destructor: " << (name ? name : "nullptr") << endl;
    delete[] name;
}

void Person::display() const {
    cout << "Person: " << name << ", Age: " << age << endl;
}