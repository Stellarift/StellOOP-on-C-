#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char name[50];
    int* marks;
    int markCount;

public:
    Student(const char* n, int count, int* m);
    ~Student();
    
    const char* getName();
    int getMark(int index);
    double getAverage();
};

#endif