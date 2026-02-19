#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {
private:
    char name[50];

public:
    Subject(const char* n);
    const char* getName();
};

#endif