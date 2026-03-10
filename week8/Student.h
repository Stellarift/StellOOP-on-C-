#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char* fullName;
    int age;
    double averageGrade;

public:
    Student();
    Student(const char* name, int age, double avg);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student();
    
    void display() const;
};

#endif