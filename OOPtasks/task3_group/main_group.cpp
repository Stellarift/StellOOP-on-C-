#include <iostream>
#include "Student.h"
#include "Subject.h"
#include "Group.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << " Группа студентов " << endl;
    
    Group group("Рпо 24/1");
    
    Subject math("Математика");
    Subject phys("Физика");
    Subject prog("Программирование");
    
    group.addSubject(&math);
    group.addSubject(&phys);
    group.addSubject(&prog);
    
    int marks1[] = {5, 4, 5};
    Student s1("Иванов", 3, marks1);
    
    int marks2[] = {4, 4, 4};
    Student s2("Петров", 3, marks2);
    
    int marks3[] = {3, 4, 5};
    Student s3("Сидоров", 3, marks3);
    
    group.addStudent(&s1);
    group.addStudent(&s2);
    group.addStudent(&s3);
    
    group.printAll();
    group.printAverages();
    
    return 0;
}