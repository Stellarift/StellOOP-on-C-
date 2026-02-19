#include "Group.h"
#include <iostream>
using namespace std;

Group::Group(const char* n) {
    strcpy(name, n);
    studentCount = 0;
    subjectCount = 0;
}

void Group::addStudent(Student* s) {
    if (studentCount < 30) {
        students[studentCount] = s;
        studentCount++;
    }
}

void Group::addSubject(Subject* s) {
    if (subjectCount < 10) {
        subjects[subjectCount] = s;
        subjectCount++;
    }
}

void Group::printAll() {
    cout << "\n Группа " << name << "---" << endl;
    
    for (int j = 0; j < subjectCount; j++) {
        cout << "\t" << subjects[j]->getName();
    }
    cout << "\tСр.балл" << endl;
    
    for (int i = 0; i < studentCount; i++) {
        cout << students[i]->getName();
        
        for (int j = 0; j < subjectCount; j++) {
            cout << "\t" << students[i]->getMark(j);
        }
        cout << "\t" << students[i]->getAverage() << endl;
    }
}

void Group::printAverages() {
    cout << "\n Средние оценки " << endl;
    
    double groupSum = 0;
    
    for (int j = 0; j < subjectCount; j++) {
        double subjectSum = 0;
        for (int i = 0; i < studentCount; i++) {
            subjectSum += students[i]->getMark(j);
        }
        double avg = subjectSum / studentCount;
        cout << subjects[j]->getName() << ": " << avg << endl;
        groupSum += avg;
    }
    
    cout << "Средний балл группы: " << groupSum / subjectCount << endl;
}