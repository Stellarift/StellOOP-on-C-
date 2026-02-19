#include "Student.h"
#include <cstring>
using namespace std;

Student::Student(const char* n, int count, int* m) {
    strcpy(name, n);
    markCount = count;
    
    marks = new int[markCount];
    for (int i = 0; i < markCount; i++) {
        marks[i] = m[i];
    }
}

Student::~Student() {
    delete[] marks;
}

const char* Student::getName() { return name; }
int Student::getMark(int index) { return marks[index]; }

double Student::getAverage() {
    double sum = 0;
    for (int i = 0; i < markCount; i++) {
        sum += marks[i];
    }
    return sum / markCount;
}