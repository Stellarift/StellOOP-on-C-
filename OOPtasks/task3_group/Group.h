#ifndef GROUP_H
#define GROUP_H
#include "Student.h"
#include "Subject.h"

class Group {
private:
    char name[50];
    Student* students[30];
    Subject* subjects[10];
    int studentCount;
    int subjectCount;

public:
    Group(const char* n);
    
    void addStudent(Student* s);
    void addSubject(Subject* s);
    
    void printAll();
    void printAverages();
};

#endif